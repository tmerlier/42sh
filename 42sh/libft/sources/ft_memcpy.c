/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:19:02 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:06:39 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_c;
	char	*src_c;

	dest_c = (char *)dest;
	src_c = (char *)src;
	if (!dest)
		return (NULL);
	else if (!src)
		return (dest);
	else if (n > 0)
		while (n--)
			*dest_c++ = *src_c++;
	return (dest);
}
