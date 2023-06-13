/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:32:26 by ehouot            #+#    #+#             */
/*   Updated: 2023/06/13 16:38:52 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>

# include "./Libft/libft.h"
# include "./Get_next_line/get_next_line.h"

typedef struct s_varb
{
	int		fd[2];
	int		pfd[2];
	int		fdhd[2];
	int		tmp;
	pid_t	child;
	char	**path;
	char	**cmd;
}				t_varb;

/* -- GNL -- */

char	*get_next_line(int fd);

/* -- PIPEX -- */

int		main_bonus(int argc, char **argv, char **envp);
int		parsing_bonus(int argc, char **argv, t_varb *var);
void	exec_cmd_bonus(char *argv, char **envp, t_varb *var);

#endif