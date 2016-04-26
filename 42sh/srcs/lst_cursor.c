/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 20:29:44 by tmerlier          #+#    #+#             */
/*   Updated: 2014/05/25 19:42:05 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sh42.h>

void			init_cursor_lst(void)
{
	t_cursor		*lst;
	t_chara			*new;

	lst = lst_cursor();
	new = new_chara_lst(0);
	lst->start = new;
	lst->current = new;
	lst->end = new;
}
