/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:18:24 by amazie            #+#    #+#             */
/*   Updated: 2014/01/24 19:12:42 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_del_str(char *str)
{
	free(str);
	str = NULL;
}

void		ft_p_free(char ***c_env)
{
	char	**temp;

	if (*c_env)
	{
		temp = *c_env;
		while (*temp)
			ft_del_str(*temp++);
		free(*c_env);
		*c_env = NULL;
	}
}

void		ft_free_line(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
