/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:52:41 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:08:21 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*str;
	char	*str2;

	str = (char *)src;
	str2 = dest;
	if (dest && src)
	{
		while (*str != '\0')
			*str2++ = *str++;
		*str2 = '\0';
		return (dest);
	}
	return (NULL);
}
