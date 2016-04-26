/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 21:49:49 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:09:13 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*str_t;
	char	*temp;

	temp = (char *)s;
	if (!s)
		return (NULL);
	if (!(str = ft_memalloc(ft_strlen(s))))
		return (NULL);
	str_t = str;
	while (*temp)
		*str++ = f(*temp++);
	return (str_t);
}
