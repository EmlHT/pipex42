/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:12:37 by ehouot            #+#    #+#             */
/*   Updated: 2023/06/13 14:50:14 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_here_doc(int argc, char **argv, t_varb *var)
{
	char	*str;

	if (pipe(var->fdhd) == -1)
		ft_error("here_doc pipe error\n");
	while (1)
	{
		str = get_next_line(0);
		if (ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(str);
			break ;
		}
		write (var->fdhd, str, ft_strlen(str) + 1);
	}
	close(var->fdhd);
}

static void	ft_check_files(int argc, char **argv, t_varb *var, bool here_doc)
{
	var->fd[0] = open(argv[1], O_RDWR);
	if (var->fd[0] == -1)
		ft_error("infile problem\n");
	if (access(argv[argc - 1], F_OK) == 0)
		unlink(argv[argc - 1]);
	var->fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT, 0666);
	if (var->fd[1] == -1)
		ft_error("outfile problem\n");
}

void	parsing_bonus(int argc, char **argv, t_varb *var)
{
	bool	here_doc;

	here_doc = false;
	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 8) && argc < 6))
		ft_error("wrong number of arguments\n");
	if (ft_strncmp(argv[1], "here_doc", 8))
	{
		ft_here_doc(argc, argv, var);
		here_doc = true;
	}
	ft_check_files(argc, argv, var, here_doc);
}