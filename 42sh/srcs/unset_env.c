/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:00:40 by amazie            #+#    #+#             */
/*   Updated: 2014/06/18 17:01:08 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

static void	free_unset_env(char **name, char **value, t_env **env)
{
	free(*name);
	name = NULL;
	free(*value);
	value = NULL;
	free(*env);
	env = NULL;
}

static void	unset_glob(char *name, int i)
{
	t_env	**first;
	t_env	*temp;
	t_env	*previous;

	first = &glob()->env;
	temp = *first;
	previous = temp;
	while (temp)
	{
		if (ft_strnstr(temp->name, name, i))
		{
			if (temp == previous)
				*first = temp->next;
			else
				previous->next = temp->next;
			free_unset_env(&(temp)->name, &(temp)->value, &temp);
			break ;
		}
		previous = temp;
		temp = temp->next;
	}
}

int			unset_env(char **cmd, int i)
{
	if (i < 2)
		ft_putendl_fd("usage: unsetenv [name]", 2);
	else if (i > 2)
		ft_putendl_fd("unsetenv: Too many Arguments", 2);
	else if (ft_strchr(cmd[1], '='))
		ft_putendl_fd("Invalid Arguments", 2);
	else
	{
		unset_glob(cmd[1], ft_strlen(cmd[1]));
		return (0);
	}
	return (1);
}
