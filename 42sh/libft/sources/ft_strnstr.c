/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:06:25 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:10:02 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;
	char	*temp;
	size_t	i;

	str1 = (char *)s1;
	if (*s2 == '\0')
		return (str1);
	while (*str1 != '\0' && n)
	{
		str2 = (char *)s2;
		temp = str1;
		i = n;
		while (*str2 != '\0' && *temp == *str2 && *temp != '\0' && i--)
		{
			str2++;
			temp++;
		}
		if (*str2 == '\0')
			return (str1);
		str1++;
		n--;
	}
	return (NULL);
}
