/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:04:17 by amazie            #+#    #+#             */
/*   Updated: 2014/04/14 12:04:59 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char		*ft_itoa(int n)
{
	int			i;
	long		sign;
	char		*s;
	char		*c;

	sign = (long int)n;
	s = ft_strnew(11);
	c = ft_strnew(11);
	i = 0;
	if (sign < 0)
		sign *= -1;
	if (sign == 0)
		s[0] = '0';
	while (sign > 0)
	{
		s[i++] = sign % 10 + '0';
		sign /= 10;
	}
	if (n < 0)
		s[i] = '-';
	sign = ft_strlen(s) - 1;
	i = 0;
	while (sign > -1)
		c[i++] = s[sign--];
	return (c);
}
