/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 15:31:34 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:09:32 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)src;
	str2 = dest;
	if (dest && src && n != 0)
	{
		while (*str2 != '\0')
			str2++;
		while (n--)
			*str2++ = *str1++;
		*str2 = '\0';
		return (dest);
	}
	else if (n == 0)
		return (dest);
	else
		return (NULL);
}
