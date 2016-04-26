/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
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

static int	count_env(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

static int	copy_env(char ***new_env, t_env *env)
{
	char	**temp;
	char	*join;

	temp = *new_env;
	join = NULL;
	while (env)
	{
		if (!(join = ft_strjoin(env->name, "=")))
		{
			ft_putendl_fd("42sh: An error occured code : 010", 2);
			ft_p_free(new_env);
			return (1);
		}
		if (!(*temp = ft_strjoin(join, env->value)))
		{
			ft_putendl_fd("42sh: An error occured code : 011", 2);
			ft_p_free(new_env);
			return (1);
		}
		free(join);
		join = NULL;
		temp++;
		env = env->next;
	}
	return (0);
}

char		**build_env(t_env *env)
{
	int		i;
	char	**new_env;

	i = count_env(env);
	if (!(new_env = ft_memalloc(sizeof(char **) * (i + 1))))
		return (NULL);
	copy_env(&new_env, env);
	return (new_env);
}
