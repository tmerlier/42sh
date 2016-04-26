/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:01:31 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:06:19 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*dest_c;
	char	*src_c;

	dest_c = (char *)dest;
	src_c = (char *)src;
	if (n > 0 && src && dest)
		while (n--)
		{
			*dest_c++ = *src_c++;
			if (*(src_c - 1) == c)
				return (dest_c);
		}
	return (NULL);
}
