/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 13:21:53 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:21:58 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sh42.h>

void		free_lst_lex(t_lex **lst)
{
	t_lex	*temp;
	t_lex	*b_temp;

	temp = *lst;
	while (temp)
	{
		b_temp = temp;
		temp = temp->next;
		if (b_temp->name)
			free(b_temp->name);
		free(b_temp);
		b_temp = NULL;
	}
	*lst = NULL;
}

static void	free_cmd(t_pars_cmd **cmd)
{
	if ((*cmd)->cmd)
		free((*cmd)->cmd);
	if ((*cmd)->r_in)
		free((*cmd)->r_in);
	if ((*cmd)->r_out)
		free((*cmd)->r_out);
	if ((*cmd)->r_new_out)
		free((*cmd)->r_new_out);
	(*cmd)->r_in = NULL;
	(*cmd)->r_out = NULL;
	(*cmd)->r_new_out = NULL;
}

void		free_three(t_pars **three)
{
	if ((*three)->left)
		free_three(&(*three)->left);
	if ((*three)->right)
		free_three(&(*three)->right);
	if ((*three)->cmd)
	{
		free_cmd(&(*three)->cmd);
		free((*three)->cmd);
		(*three)->cmd = NULL;
	}
	free(*three);
	*three = NULL;
}
