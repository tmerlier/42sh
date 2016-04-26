/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 18:47:35 by vcosson           #+#    #+#             */
/*   Updated: 2014/06/19 19:01:05 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <libft.h>
#include <sh42.h>

t_glob				*glob(void)
{
	static t_glob		*glob = NULL;

	if (!glob)
	{
		if (!(glob = ft_memalloc(sizeof(t_glob))))
			malloc_error("glob");
		glob->env = NULL;
		glob->chara = NULL;
		glob->hist = NULL;
		glob->pwd = ft_getcwd();
		glob->lex = NULL;
		glob->exit_sh = -1;
		glob->ex_return = 0;
	}
	return (glob);
}

struct termios		*singleton_term(void)
{
	static struct termios		*term;

	if (term == NULL)
	{
		if (!(term = ft_memalloc(sizeof(struct termios))))
			malloc_error("singleton_term");
	}
	return (term);
}

t_cursor			*lst_cursor(void)
{
	static t_cursor		*lst;

	if (lst == NULL)
	{
		if (!(lst = ft_memalloc(sizeof(t_cursor))))
			malloc_error("lst_cursor");
		lst->start = NULL;
		lst->current = NULL;
		lst->end = NULL;
	}
	return (lst);
}
