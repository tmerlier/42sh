/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 11:11:49 by amazie            #+#    #+#             */
/*   Updated: 2014/06/18 11:11:51 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

void	set_glob(char *name, char *value, int i)
{
	t_env	*temp;

	temp = glob()->env;
	while (temp)
	{
		if (strnstr(temp->name, name, i) && ft_strlen(temp->name) == i)
		{
			free(temp->value);
			temp->value = ft_strdup(value);
			return ;
		}
		temp = temp->next;
	}
	add_env(&(glob()->env), name, value);
}

int		set_env(char **cmd, int i)
{
	if (i <= 2)
		ft_putendl_fd("usage: setenv [name][value]", 2);
	else if (i > 3)
		ft_putendl_fd("setenv: Too many Arguments", 2);
	else if (ft_strchr(cmd[1], '=')
		|| ft_strchr(cmd[2], '='))
		ft_putendl_fd("Invalid Arguments", 2);
	else
	{
		set_glob(cmd[1], cmd[2], ft_strlen(cmd[1]));
		return (0);
	}
	return (1);
}
