/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 21:13:08 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:47:04 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

void		add_env(t_env **temp, char *name, char *value)
{
	t_env	*new_env;
	t_env	*c_temp;

	new_env = NULL;
	if (!(new_env = ft_memalloc(sizeof(t_env *))))
		malloc_error("add_env");
	new_env->name = ft_strdup(name);
	new_env->value = ft_strdup(value);
	new_env->next = NULL;
	if (!*temp)
		*temp = new_env;
	else
	{
		c_temp = *temp;
		while (c_temp->next)
			c_temp = c_temp->next;
		c_temp->next = new_env;
	}
}

static void	init_env_next(t_env **temp)
{
	char	**str;

	str = NULL;
	if (!(str = ft_memalloc(sizeof(char **))))
		malloc_error("init_env_next");
	str[0] = "PATH";
	str[1] = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin";
	add_env(temp, str[0], str[1]);
	str[0] = "TERM";
	str[1] = "xterm-256color";
	add_env(temp, str[0], str[1]);
	free(str);
}

t_env		*init_env(char **env)
{
	t_env	*temp;
	char	**split;

	temp = NULL;
	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) && strncmp(*env, "TERM=", 5))
		{
			split = NULL;
			if (!(split = ft_strsplit(*env, '=')))
				malloc_error("init_env");
			else if (ft_strplen(split) == 2)
				add_env(&temp, split[0], split[1]);
			ft_p_free(&split);
		}
		env++;
	}
	init_env_next(&temp);
	return (temp);
}
