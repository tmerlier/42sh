/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 21:13:08 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:47:04 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sh42.h>

int		term_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	add_lst(t_lex **lst, t_lex **new_lst)
{
	t_lex	*temp;

	if (!(*lst))
		*lst = *new_lst;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = *new_lst;
	}
}

void	init_token(char *test[8])
{
	test[0] = "||";
	test[1] = "&&";
	test[2] = ">>";
	test[3] = "|";
	test[4] = ";";
	test[5] = ">";
	test[6] = "<";
	test[7] = NULL;
}

int		prior_tok(int param)
{
	if (param == 4)
		return (0);
	if (param == 0)
		return (2);
	if (param == 2)
		return (4);
	return (param);
}
