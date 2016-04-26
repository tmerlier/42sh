/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:06:25 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:10:40 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*str1;
	char	*str2;
	char	*temp;

	str1 = (char *)str;
	str2 = (char *)to_find;
	if (!to_find)
		return (str1);
	while (*str1 != '\0')
	{
		temp = str1;
		while (*str2 != '\0' && *temp == *str2 && *temp != '\0')
		{
			str2++;
			temp++;
		}
		if (*str2 == '\0')
			return (str1);
		else
			str2 = (char *)to_find;
		str1++;
	}
	return (NULL);
}
