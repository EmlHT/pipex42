/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:30:51 by ehouot            #+#    #+#             */
/*   Updated: 2023/06/13 16:38:27 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_pipe_to_pipe(char *argv, char **envp, t_varb *var)
{
	var->child = fork();
	if (var->child < 0)
		ft_error("fork problem\n");
	else if (var->child == 0)
	{
		close (var->fd[1]);
		close (var->pfd[0]);
		close (var->pfd[1]);
		var->tmp = dup(STDOUT_FILENO);
		dup2(var->fd[0], STDIN_FILENO);
		close (var->fd[0]);
		close (var->tmp);
		exec_cmd_bonus(&argv[2], envp, var);
	}
}

static void	ft_read_to_pipe(char *argv, char **envp, t_varb *var)
{
	var->child = fork();
	if (var->child < 0)
		ft_error("fork problem\n");
	else if (var->child == 0)
	{
		close (var->fd[1]);
		close (var->pfd[0]);
		dup2(var->fd[0], STDIN_FILENO);
		dup2(var->pfd[1], STDOUT_FILENO);
		close (var->fd[0]);
		close (var->pfd[1]);
		exec_cmd_bonus(&argv[2], envp, var);
	}
}

static void	ft_pipe_to_write(char *argv, char **envp, t_varb *var)
{
	var->child = fork();
	if (var->child < 0)
		ft_error("fork problem\n");
	else if (var->child == 0)
	{
		close (var->fd[0]);
		close (var->pfd[1]);
		dup2(var->fd[1], STDOUT_FILENO);
		dup2(var->pfd[0], STDIN_FILENO);
		close (var->fd[1]);
		close (var->pfd[0]);
		exec_cmd_bonus(&argv[3], envp, var);
	}
}

int	main_bonus(int argc, char **argv, char **envp)
{
	t_varb	var;
	int		i;
	int		ishere_doc;

	i = 3;
	ishere_doc = parsing_bonus(argc, argv, &var);
	if (pipe(var.pfd) == -1)
		ft_error("pipe error\n");
	ft_read_to_pipe(argv[2], envp, &var);
	while (i++ > argc - 1)
		ft_pipe_to_pipe(argv[i], envp, &var);
	ft_pipe_to_write(argv[argc - 1], envp, &var);
	waitpid(-1, NULL, 0);
	return (EXIT_SUCCESS);
}
