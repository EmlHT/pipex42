/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:59:50 by ehouot            #+#    #+#             */
/*   Updated: 2023/06/09 17:03:58 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_path(char **envp, t_var *var)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	var->path = ft_split(ft_strchr(envp[i], '/'), ':');
}

char	*check_cmd(t_var *var)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ft_strjoin("/", var->cmd[0]);
	i = -1;
	while (var->path[++i])
	{
		var->path[i] = ft_strjoin(var->path[i], tmp);
		j = -1;
		while (var->path[i][++j])
		{
			if (access(var->path[i], F_OK) == 0)
				return (var->path[i]);
		}
	}
	ft_error("cmd not found\n");
	return (NULL);
}

void	exec_cmd(char **argv, char **envp, t_var *var)
{
	init_path(envp, var);
	var->cmd = ft_split(*argv, ' ');
	if (execve(var->cmd[0], var->cmd, envp) == 0)
		return ;
	var->cmd[0] = check_cmd(var);
	execve(var->cmd[0], var->cmd, envp);
}
