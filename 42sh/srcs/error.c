/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 19:28:26 by vcosson           #+#    #+#             */
/*   Updated: 2014/06/16 17:53:47 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

void	malloc_error(char *func)
{
	ft_putstr_fd("42sh: *** (", 2);
	ft_putstr_fd(func, 2);
	ft_putendl_fd(") Malloc Error ***", 2);
	exit(ER_MALLOC);
}

void	termcaps_error(char *var_env)
{
	ft_putstr_fd("42sh: *** (", 2);
	ft_putstr_fd(var_env, 2);
	ft_putstr_fd(" : Invalid Term", 2);
	ft_putendl_fd(") Termcaps Error ***", 2);
	exit(ER_TERMCAPS);
}
