/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 21:13:08 by amazie            #+#    #+#             */
/*   Updated: 2014/06/22 21:41:07 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

static int		buitlin_error(t_pars_cmd *cmd)
{
	if (!cmd->cmd)
	{
		ft_putendl_fd("42sh: no command input", 2);
		return (1);
	}
	return (0);
}

int				builtin(t_pars_cmd *cmd)
{
	char	**str;
	int		i;

	i = -1;
	if (buitlin_error(cmd))
		return (1);
	if (!(str = ft_strsplit(cmd->cmd, ' ')))
	{
		ft_putendl_fd("42sh: an error occured code : 015\n", 2);
		return (1);
	}
	if (!ft_strcmp(*str, "setenv"))
		i = set_env(str, ft_strplen(str));
	else if (!ft_strcmp(*str, "unsetenv"))
		i = unset_env(str, ft_strplen(str));
	else if (!ft_strcmp(*str, "echo"))
		i = build_echo(str + 1);
	else if (!ft_strcmp(*str, "cd"))
		i = cd(str);
	else if (!ft_strcmp(*str, "exit"))
		i = at_exit(str);
	else if (!ft_strcmp(*str, "env"))
		i = env(str + 1);
	ft_p_free(&str);
	return (i);
}
