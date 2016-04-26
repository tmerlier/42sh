/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 20:39:54 by tmerlier          #+#    #+#             */
/*   Updated: 2014/06/16 17:51:49 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>
#include <sh42.h>

void		backspace_input(t_cursor *lst)
{
	if (lst->current->prev == NULL)
		return ;
	tputs(tgetstr("dm", NULL), 1, term_putchar);
	tputs(tgetstr("le", NULL), 1, term_putchar);
	tputs(tgetstr("dc", NULL), 1, term_putchar);
	erase_backspace(lst);
	tputs(tgetstr("ed", NULL), 1, term_putchar);
}

void		delete_input(t_cursor *lst)
{
	if (lst->current == lst->end)
		return ;
	tputs(tgetstr("dm", NULL), 1, term_putchar);
	tputs(tgetstr("dc", NULL), 1, term_putchar);
	erase_input(lst);
	tputs(tgetstr("ed", NULL), 1, term_putchar);
}

void		delete_cmdline(t_cursor *lst)
{
	t_chara	*tmp;

	move_home(lst);
	tmp = lst->start;
	while (tmp->next)
	{
		delete_input(lst);
		tmp = tmp->next;
	}
}
