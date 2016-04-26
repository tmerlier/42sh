/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 15:02:01 by amazie            #+#    #+#             */
/*   Updated: 2014/02/21 17:18:19 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		strisint(char *str, int i)
{
	char	*temp;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	temp = str;
	while (*temp)
	{
		if (!ft_isdigit(*temp))
			return (1);
		temp++;
	}
	if (i == 10)
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (1);
	}
	else if (i > 10)
		return (1);
	return (0);
}
