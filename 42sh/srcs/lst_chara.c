/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_chara.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 20:27:45 by tmerlier          #+#    #+#             */
/*   Updated: 2014/06/16 19:05:27 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sh42.h>

t_chara			*new_chara_lst(char c)
{
	t_chara		*new;

	if (!(new = (t_chara *)ft_memalloc(sizeof(t_chara))))
		malloc_error("new_chara_lst");
	new->c = c;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			add_chara_lst(t_cursor *lst, char c)
{
	t_chara		*new;

	new = new_chara_lst(c);
	if (lst->current == lst->start)
	{
		new->next = lst->current;
		lst->start = new;
		lst->current->prev = lst->start;
	}
	else
	{
		new->prev = lst->current->prev;
		new->next = lst->current;
		if (lst->current->prev)
		{
			lst->current->prev->next = new;
			lst->current->prev = new;
		}
	}
}
