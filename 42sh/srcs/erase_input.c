/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 21:01:52 by tmerlier          #+#    #+#             */
/*   Updated: 2014/05/29 21:06:21 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sh42.h>

void			erase_backspace(t_cursor *lst)
{
	t_chara		*todel;

	todel = lst->current->prev;
	lst->current->prev = todel->prev;
	if (todel->prev)
		todel->prev->next = lst->current;
	else
		lst->start = lst->current;
	free(todel);
}

void			erase_input(t_cursor *lst)
{
	t_chara		*todel;

	todel = lst->current;
	todel->next->prev = todel->prev;
	if (todel != lst->start)
		todel->prev->next = todel->next;
	else
		lst->start = todel->next;
	if (todel != lst->start)
		lst->current = todel->next;
	free(todel);
}
