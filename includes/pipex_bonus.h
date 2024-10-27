/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigarcia <nigarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:25:26 by nigarcia          #+#    #+#             */
/*   Updated: 2023/01/26 10:37:51 by nigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int	**pipes;
	int	*pids;
	int	nb_cmd;
	int	rfd;
	int	wfd;
	int	rdup;
	int	wdup;
}	t_pipex;

int		**get_pipes(int nb_pipes);
void	free_pipes(int **pipes, int nb_pipes);
void	close_pipes_not_used(t_pipex *pipex);
int		waitforit(t_pipex *pipex);
t_pipex	*get_pipex(int nb_cmd);
void	free_pipex(t_pipex *pipex);
void	close_pipex_dup(t_pipex *pipex);
char	**get_splited_command(char *command, char **envp);
void	free_split(char **split);
void	close_all_pipes(t_pipex *pipex);
int		ft_dup(t_pipex *pipex, int pid, char **argv);
int		exec_command(t_pipex *pipex, int pid, char **argv, char **envp);
int		process(t_pipex *pipex, char **argv, char **envp);
void	print_wrong_args_number_error(void);
void	print_technical_error(void);
void	print_infile_error(char *file_name);
void	print_command_not_found_error(char *command_name);

#endif