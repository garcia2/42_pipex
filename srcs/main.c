/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigarcia <nigarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:39:40 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/26 10:30:53 by nigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		end_code;

	if (argc != 5)
		return (print_wrong_args_number_error(), 3);
	pipex = get_pipex(argc - 3);
	if (pipex == NULL)
		return (print_technical_error(), 1);
	end_code = process(pipex, argv, envp);
	return (free_pipex(pipex), end_code);
}
