/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 16:35:06 by amazie            #+#    #+#             */
/*   Updated: 2014/06/15 16:35:08 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int	analyse_pars(int result, int token)
{
	if ((token == 1 && !result)
		|| (token == 2 && result)
		|| (!token))
		return (1);
	return (0);
}

int			exec_pars(t_pars *three, int result, int token)
{
	if (three->token < 3)
		result = exec_pars(three->left, result, token);
	else if (analyse_pars(result, token) && three->token == 3)
	{
		exec_pipe(three, &result);
		return (result);
	}
	else if (analyse_pars(result, token) && three->token == 7)
	{
		exec_cmd(three->cmd, -1, &result, 0);
		return (result);
	}
	if (three->right)
		result = exec_pars(three->right, result, three->token);
	return (result);
}
