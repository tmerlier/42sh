/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcosson <vcosson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 14:22:19 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:41:48 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <sh42.h>

static void	put_echo(char **str, int option)
{
	if (option == 2)
		ft_putnbr(glob()->ex_return);
	else
	{
		str = str + option;
		while (*str)
		{
			ft_putstr(*str);
			str++;
			if (*str)
				ft_putstr(" ");
		}
		if (option)
			ft_puttext_fd("\033[0;30;47m", "%", RESET, 1);
	}
	ft_putchar('\n');
}

static int	isoption(char *str)
{
	if (!ft_strncmp(str, "-n", 3))
		return (1);
	if (!ft_strncmp(str, "$?", 3))
		return (2);
	return (0);
}

int			build_echo(char **str)
{
	if (str == NULL || str[0] == NULL)
	{
		ft_putstr("\n");
		return (0);
	}
	put_echo(str, isoption(*str));
	return (0);
}
