/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 20:02:46 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:09:43 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (n != 0)
		while (*str1 != '\0' && n--)
		{
			if (*str1 != *str2 || !n)
				return (*str1 - *str2);
			str1++;
			str2++;
		}
	return (*str1 - *str2);
}
