/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 15:08:32 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:07:57 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strcat(char *dest, const char *src)
{
	char	*str1;
	char	*str2;

	str1 = (char *)src;
	str2 = dest;
	if (dest && src)
	{
		while (*str2 != '\0')
			str2++;
		while (*str1 != '\0')
			*str2++ = *str1++;
		*str2 = '\0';
		return (dest);
	}
	return (NULL);
}
