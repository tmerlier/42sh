/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 15:00:47 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:10:24 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)src;
	str2 = dest;
	if (dest && src && n != 0)
	{
		while (n--)
			if (*str1 == '\0')
				*str2++ = '\0';
			else
				*str2++ = *str1++;
		return (dest);
	}
	return (NULL);
}
