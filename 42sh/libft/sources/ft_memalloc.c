/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:33:30 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:06:11 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void	*str;

	if ((str = (void *)malloc(size * sizeof(str))))
		ft_bzero(str, size);
	else
		return (NULL);
	return (str);
}
