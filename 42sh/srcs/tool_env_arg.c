/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_env_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 15:12:39 by amazie            #+#    #+#             */
/*   Updated: 2014/06/20 15:12:41 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sh42.h>

char	**write_env(char **str)
{
	char **temp;

	temp = str;
	while (*temp)
	{
		ft_putendl(*temp);
		temp++;
	}
	ft_p_free(&str);
	return (NULL);
}

char	**new_env(char **str)
{
	char	**temp;
	char	**newenv;
	int		i;

	i = grep_cmd(str);
	if (!(newenv = ft_memalloc(sizeof(char **) * (i + 1))))
		return (NULL);
	temp = newenv;
	while (i--)
		*temp++ = ft_strdup(*str++);
	*temp = NULL;
	return (newenv);
}

int		isex(char **newenv, char *str)
{
	char	*temp;
	char	*temp2;

	while (*newenv)
	{
		temp = *newenv;
		temp2 = str;
		while (*temp++ == *temp2++)
		{
			if (*temp == *temp2 && *temp == '=')
				return (0);
		}
		newenv++;
	}
	return (1);
}

int		grep_cmd(char **str)
{
	int	i;

	i = 0;
	while (ft_strchr(str[i], '='))
		i++;
	return (i);
}
