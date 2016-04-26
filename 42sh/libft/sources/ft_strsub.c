/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 22:10:51 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:10:45 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*src;
	char	*str_t;

	src = (char *)s;
	if (!(str = ft_strnew(len + 1)) || !s)
		return (NULL);
	str_t = str;
	if (len)
		while (len--)
			*str++ = *((src++) + start);
	return (str_t);
}
