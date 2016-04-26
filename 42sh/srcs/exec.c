/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 21:13:08 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:47:04 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <sh42.h>

static char		*getenv_path(char **env)
{
	while (env && *env)
	{
		if (!(ft_strncmp(*env, "PATH=", 5)))
			return ((*env) + 5);
		env++;
	}
	return (NULL);
}

static void		exec_file(char **cmd, int isnew_env, char **env)
{
	if (!isnew_env)
		env = build_env(glob()->env);
	isaccess(&(*cmd), 0, 0);
	execve(*cmd, cmd, env);
	ft_puttext_fd("42sh: cannot exec: ", *cmd, "\n", 2);
	if (env)
		ft_p_free(&env);
	exit(3);
}

static void		exec_bin(char **cmd, int isnew_env, char **env)
{
	char	**path;
	int		i;

	if (!isnew_env)
		env = build_env(glob()->env);
	if ((!isnew_env) || (isnew_env && !getenv_path(env)))
		path = bin(*cmd, ft_getenv("PATH"));
	else
		path = bin(*cmd, getenv_path(env));
	if ((i = isaccess(path, 1, 0)) > -1)
		execve(path[i], cmd, env);
	ft_puttext_fd("42sh: command not found: ", *cmd, "\n", 2);
	if (path)
		ft_p_free(&path);
	if (env)
		ft_p_free(&env);
	exit(5);
}

void			exec_env(char **str, int *i, int isnew_env, char **env)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
	{
		ft_putendl_fd("Fork fail", 2);
		return ;
	}
	if (!pid)
	{
		if (ft_strchr(*str, '/'))
			exec_file(str, isnew_env, env);
		else
			exec_bin(str, isnew_env, env);
	}
	else
		waitpid(pid, i, 0);
}

void			exec(t_pars_cmd *cmd, int type)
{
	char	**str;
	int		i;

	str = NULL;
	i = -1;
	if (type && (i = builtin(cmd)) > -1)
		exit(i);
	if (!(str = ft_strsplit(cmd->cmd, ' ')))
	{
		ft_putendl_fd("42sh: an error occured code : 012", 2);
		exit(3);
	}
	if (ft_strchr(*str, '/'))
		exec_file(str, 0, NULL);
	else
		exec_bin(str, 0, NULL);
	ft_p_free(&str);
	exit(4);
}
