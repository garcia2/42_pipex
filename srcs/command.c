/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigarcia <nigarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:07:18 by nico              #+#    #+#             */
/*   Updated: 2023/01/26 12:23:18 by nigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	char	**paths;

	while (*envp != NULL)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
		{
			paths = ft_split(*envp + 5, ':');
			return (paths);
		}
		envp++;
	}
	return (NULL);
}

char	*join_path_and_command(char *command, char *path)
{
	char	*str_temp;
	char	*path_and_command;

	str_temp = ft_strjoin(path, "/");
	if (str_temp == NULL)
		return (NULL);
	path_and_command = ft_strjoin(str_temp, command);
	free(str_temp);
	return (path_and_command);
}

char	*find_valid_path(char *command, char **paths)
{
	int		i;
	char	*command_path;

	i = 0;
	while (paths[i] != NULL)
	{
		command_path = join_path_and_command(command, paths[i]);
		if (command_path != NULL)
		{
			if (access(command_path, 0) == 0)
				return (command_path);
			free(command_path);
		}
		i++;
	}
	return (NULL);
}

void	free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**get_splited_command(char *command, char **envp)
{
	char	**splited_command;
	char	**paths;
	char	*valid_path;

	if (ft_strlen(command) == 0)
		return (NULL);
	splited_command = ft_split(command, ' ');
	if (splited_command == NULL || !splited_command[0])
		return (NULL);
	if (splited_command[0][0] == ' ' || splited_command[0][0] == '	')
		return (NULL);
	if (access(splited_command[0], 0) == 0)
		return (splited_command);
	paths = get_paths(envp);
	if (paths == NULL)
		return (free_split(splited_command), NULL);
	valid_path = find_valid_path(splited_command[0], paths);
	if (valid_path == NULL)
		return (free_split(splited_command), free_split(paths), NULL);
	free(splited_command[0]);
	splited_command[0] = valid_path;
	return (free_split(paths), splited_command);
}
