/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigarcia <nigarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:27:09 by nigarcia          #+#    #+#             */
/*   Updated: 2023/01/26 10:51:36 by nigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	exec_command(t_pipex *pipex, int pid, char **argv, char **envp)
{
	char	**splited_command;

	if (ft_dup(pipex, pid, argv) == 0)
	{
		free_pipex(pipex);
		exit(1);
	}
	splited_command = get_splited_command(argv[pid + 2], envp);
	if (splited_command == 0)
	{
		close_pipex_dup(pipex);
		free_split(splited_command);
		free_pipex(pipex);
		print_command_not_found_error(argv[pid + 2]);
		exit(127);
	}
	if (execve(splited_command[0], splited_command, NULL) == -1)
		return (close_pipex_dup(pipex), free_split(splited_command), 0);
	return (1);
}
