/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttextstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 14:18:21 by amazie            #+#    #+#             */
/*   Updated: 2014/06/14 14:18:23 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_puttext_fd(char *string1, char *str, char *string2, int fd)
{
	if (string1)
		ft_putstr_fd(string1, fd);
	if (str)
		ft_putstr_fd(str, fd);
	if (string2)
		ft_putstr_fd(string2, fd);
}
