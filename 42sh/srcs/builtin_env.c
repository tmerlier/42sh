/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 09:59:57 by amazie            #+#    #+#             */
/*   Updated: 2014/06/20 10:00:01 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sh42.h>

static char	**env_add_new_env(char **str, char **env, int i)
{
	char	**newenv;
	char	**temp;
	char	**tmp_str;

	i = ft_strplen(str) + i;
	newenv = ft_memalloc(sizeof(char **) * (i + 1));
	temp = newenv;
	tmp_str = str;
	while (*env)
	{
		*temp++ = ft_strdup(*env++);
		i--;
	}
	while (i--)
	{
		if (isex(newenv, *tmp_str))
			*temp++ = ft_strdup(*tmp_str++);
		else
			tmp_str++;
	}
	ft_p_free(&str);
	*temp = NULL;
	return (newenv);
}

static void	env_chge_void(char **str, char **env, int *i, int size_cmd)
{
	char	**test;

	test = NULL;
	test = env_add_new_env(build_env(glob()->env), env, size_cmd);
	if (*(str + size_cmd))
		exec_env(str + grep_cmd(str), i, 1, test);
	else
		test = write_env(test);
	if (test)
		ft_p_free(&test);
}

static int	env_chge(char **str, int env_void, int *i)
{
	int		size_cmd;
	char	**env;

	if (!(env = new_env(str)))
		return (0);
	size_cmd = grep_cmd(str);
	if (env_void)
		env_chge_void(str, env, i, size_cmd);
	else
	{
		if (*(str + size_cmd))
			exec_env(str + grep_cmd(str), i, 1, env);
		else
			env = write_env(env);
	}
	if (env)
		ft_p_free(&env);
	return (0);
}

static int	env_void(char **str, int *i)
{
	if (!*str)
		return (0);
	else if (ft_strchr(*str, '='))
		env_chge(str, 0, i);
	else
		exec_env(str, i, 1, NULL);
	return (0);
}

int			env(char **str)
{
	int	i;
	int	isvoid;

	i = 0;
	if (!*str)
		write_env(build_env(glob()->env));
	else
	{
		isvoid = ft_strncmp(*str, "-i", 3);
		if (!isvoid)
			env_void(str + 1, &i);
		else if (ft_strchr(*str, '='))
			env_chge(str, isvoid, &i);
		else
			exec_env(str, &i, 0, NULL);
	}
	return (i);
}
