/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:34:49 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:07:48 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	else if (n > 0)
		while (n--)
			*str++ = c;
	return (s);
}
