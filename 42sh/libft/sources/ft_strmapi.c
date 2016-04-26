/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 21:49:49 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:09:23 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*str_t;
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)s;
	if (!s)
		return (NULL);
	if (!(str = ft_memalloc(ft_strlen(s))))
		return (NULL);
	str_t = str;
	while (*temp)
		*str++ = f(i++, *temp++);
	return (str_t);
}
