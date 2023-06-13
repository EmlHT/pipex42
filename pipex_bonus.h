/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:32:26 by ehouot            #+#    #+#             */
/*   Updated: 2023/06/10 16:55:00 by ehouot           ###   ########.fr       */
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

/* -- PIPEX -- */

int		main_bonus(int argc, char **argv, char **envp);
void	parsing_bonus(int argc, char **argv, t_varb *var);
void	exec_cmd_bonus(char *argv, char **envp, t_varb *var);

#endif