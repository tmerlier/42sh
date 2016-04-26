/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 14:11:01 by amazie            #+#    #+#             */
/*   Updated: 2014/06/15 14:11:03 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

static void son_recurs_pipe(t_pars *three, int input, int *fd)
{
	if (input > -1)
		dup2(input, 0);
	close(fd[0]);
	if (three->right)
		dup2(fd[1], 1);
	close(fd[1]);
	exec(three->left->cmd, 1);
}

static void father_recurs_pipe(pid_t pid, t_pars *three, int *result, int *fd)
{
	close(fd[1]);
	if (three->right)
	{
		if (three->right->token == 3)
			recurs_pipe(three->right, fd[0], result);
		else if (three->right->token == 7 && builtin(three->right->cmd) < 0)
			exec_cmd(three->right->cmd, fd[0], result, 1);
		close(fd[0]);
	}
	waitpid(pid, NULL, 0);
}

void		recurs_pipe(t_pars *three, int input, int *result)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
	{
		ft_putendl_fd("Pipe fail", 2);
		return ;
	}
	if ((pid = fork()) < 0)
	{
		ft_putendl_fd("Fork fail", 2);
		return ;
	}
	if (!pid)
		son_recurs_pipe(three, input, fd);
	else
		father_recurs_pipe(pid, three, result, fd);
}

void		exec_pipe(t_pars *three, int *result)
{
	int	fd;

	fd = -1;
	if (three->left->cmd->r_in)
	{
		if ((fd = open_file(three->left->cmd->r_in, 1)) < 0)
		{
			*result = 1;
			return ;
		}
	}
	recurs_pipe(three, fd, result);
	close(fd);
}
