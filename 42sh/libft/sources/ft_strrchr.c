/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:55:06 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:10:31 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*temp;

	temp = NULL;
	str = (char *)s;
	if (s)
	{
		if (c == 0)
			return (str + ft_strlen(s));
		while (*str != '\0')
		{
			if (*str == c)
				temp = str;
			str++;
		}
		if (temp)
			return (temp);
	}
	return (NULL);
}
