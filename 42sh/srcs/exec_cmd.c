/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 16:37:41 by amazie            #+#    #+#             */
/*   Updated: 2014/06/15 16:37:48 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

static void	isredirect(char *r_in, char *r_out, char *r_new_out, int *fd)
{
	if (r_in)
	{
		if ((fd[0] = open_file(r_in, 1)) < 0)
			exit(2);
		dup2(fd[0], 0);
	}
	if (r_out)
	{
		if ((fd[1] = open_file(r_out, 2)) < 0)
			exit(2);
		dup2(fd[1], 1);
	}
	if (r_new_out)
	{
		if ((fd[1] = open_file(r_new_out, 3)) < 0)
			exit(2);
		dup2(fd[1], 1);
	}
}

static void	son_exec_cmd(t_pars_cmd *cmd, int input, int type, int *fd)
{
	if (type && input > -1)
	{
		dup2(input, 0);
		close(fd[0]);
	}
	isredirect(cmd->r_in, cmd->r_out, cmd->r_new_out, fd);
	exec(cmd, type);
}

static void	father_exec_cmd(pid_t pid, int *result, int type, int *fd)
{
	if (type)
	{
		close(fd[1]);
		close(fd[0]);
	}
	waitpid(pid, result, 0);
	glob()->ex_return = *result % 255;
}

void		exec_cmd(t_pars_cmd *cmd, int input, int *result, int type)
{
	pid_t	pid;
	int		fd[2];

	if (!cmd->cmd)
		return ;
	if (!type && (*result = builtin(cmd)) > -1)
		return ;
	if (type)
		pipe(fd);
	if ((pid = fork()) < 0)
	{
		ft_putendl_fd("Fork fail", 2);
		return ;
	}
	if (!pid)
		son_exec_cmd(cmd, input, type, fd);
	else
		father_exec_cmd(pid, result, type, fd);
}
