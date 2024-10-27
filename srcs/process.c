/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigarcia <nigarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:28:39 by nigarcia          #+#    #+#             */
/*   Updated: 2023/01/25 16:55:55 by nigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	process(t_pipex *pipex, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (i < pipex->nb_cmd)
	{
		pipex->pids[i] = fork();
		if (pipex->pids[i] < 0)
			return (2);
		if (pipex->pids[i] == 0)
		{
			if (exec_command(pipex, i, argv, envp) != 0)
				return (0);
			return (1);
		}
		i++;
	}
	close_all_pipes(pipex);
	return (waitforit(pipex));
}
