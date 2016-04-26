/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 17:30:24 by amazie            #+#    #+#             */
/*   Updated: 2014/02/23 00:58:25 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strword(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str)
			i++;
		while (*str && !ft_isspace(*str))
			str++;
	}
	return (i);
}
