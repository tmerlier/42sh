/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 21:15:29 by tmerlier          #+#    #+#             */
/*   Updated: 2014/05/29 21:15:53 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <stdlib.h>
#include <sh42.h>

void			cursor_move(char key[4])
{
	t_cursor		*lst;

	lst = lst_cursor();
	if (K2 == 67)
	{
		if (lst->current->next)
		{
			lst->current = lst->current->next;
			tputs(tgetstr("nd", NULL), 1, term_putchar);
		}
	}
	else if (K2 == 68)
	{
		if (lst->current->prev)
		{
			lst->current = lst->current->prev;
			tputs(tgetstr("le", NULL), 1, term_putchar);
		}
	}
}

void			move_end(t_cursor *lst)
{
	while (lst->current != lst->end)
	{
		tputs(tgetstr("nd", NULL), 1, term_putchar);
		lst->current = lst->current->next;
	}
}

void			move_home(t_cursor *lst)
{
	while (lst->current != lst->start)
	{
		tputs(tgetstr("le", NULL), 1, term_putchar);
		lst->current = lst->current->prev;
	}
}

void			move_left(t_cursor *lst)
{
	while (lst->current->prev && lst->current->prev->c == ' ')
	{
		tputs(tgetstr("le", NULL), 1, term_putchar);
		lst->current = lst->current->prev;
	}
	while (lst->current->prev && lst->current->prev->c != ' ')
	{
		tputs(tgetstr("le", NULL), 1, term_putchar);
		lst->current = lst->current->prev;
	}
}

void			move_right(t_cursor *lst)
{
	while (lst->current->next && lst->current->c == ' ')
	{
		tputs(tgetstr("nd", NULL), 1, term_putchar);
		lst->current = lst->current->next;
	}
	while (lst->current->next && lst->current->c != ' ')
	{
		tputs(tgetstr("nd", NULL), 1, term_putchar);
		lst->current = lst->current->next;
	}
	while (lst->current->next && lst->current->c == ' ')
	{
		tputs(tgetstr("nd", NULL), 1, term_putchar);
		lst->current = lst->current->next;
	}
}
