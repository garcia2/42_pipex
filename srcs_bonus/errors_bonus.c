/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigarcia <nigarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:37:02 by nigarcia          #+#    #+#             */
/*   Updated: 2023/01/26 10:12:55 by nigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	print_wrong_args_number_error(void)
{
	char	*str;

	str = "pipex: wrong number of arguments\n";
	print_error(str);
}

void	print_technical_error(void)
{
	char	*str;

	str = "pipex: a technical error append\n";
	print_error(str);
}

void	print_infile_error(char *file_name)
{
	char	*temp_1;
	char	*temp_2;

	temp_1 = ft_strjoin("pipex: ", strerror(errno));
	temp_2 = ft_strjoin(temp_1, ": ");
	free(temp_1);
	temp_1 = ft_strjoin(temp_2, file_name);
	free(temp_2);
	temp_2 = ft_strjoin(temp_1, "\n");
	print_error(temp_2);
	free(temp_1);
	free(temp_2);
}

void	print_command_not_found_error(char *command_name)
{
	char	*temp_1;
	char	*temp_2;

	temp_1 = ft_strjoin("pipex: command_not_found: ", command_name);
	temp_2 = ft_strjoin(temp_1, "\n");
	print_error(temp_2);
	free(temp_1);
	free(temp_2);
}
