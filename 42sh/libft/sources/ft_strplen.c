/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 16:00:43 by amazie            #+#    #+#             */
/*   Updated: 2014/01/04 16:03:02 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strplen(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (*(str++))
			i++;
	}
	return (i);
}