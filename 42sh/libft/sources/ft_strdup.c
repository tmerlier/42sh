/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:36:57 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:08:32 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*temp;
	char	*temp2;

	str = (char *)s;
	if (s)
		if ((temp = (char *)malloc((ft_strlen(s) + 1) * sizeof(temp))))
		{
			temp2 = temp;
			while (*str != '\0')
				*temp++ = *str++;
			*temp = *str;
			return (temp2);
		}
	return (NULL);
}
