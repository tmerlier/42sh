/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:25:12 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:07:33 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;

	if (!src || !n)
		return (dest);
	else
	{
		if ((temp = (char *)malloc(n * sizeof(temp))) && dest)
		{
			ft_memcpy(temp, src, n);
			ft_memcpy(dest, temp, n);
		}
		else
			return (NULL);
	}
	return (dest);
}
