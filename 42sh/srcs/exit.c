/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 13:21:22 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:21:28 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sh42.h>

int			at_exit(char **cmdline)
{
	unsigned int	i;
	unsigned int	exit_r;

	i = ft_strplen(cmdline);
	exit_r = 0;
	if (i > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (0);
	}
	if (i == 2)
	{
		if (!strisint(cmdline[1], ft_strlen(cmdline[1])))
			exit_r = ft_atoi(cmdline[1]) % 255;
	}
	else
		exit_r = 0;
	glob()->exit_sh = exit_r;
	return (0);
}
