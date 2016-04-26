/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:12:08 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:08:05 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>

char	*ft_strchr(const char *src, int c)
{
	char	*str;

	str = (char *)src;
	if (src)
	{
		if (c == 0)
			return (str + ft_strlen(src));
		while (*str != '\0')
		{
			if (*str == c)
				return (str);
			str++;
		}
	}
	return (NULL);
}
