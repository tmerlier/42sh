/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 20:33:54 by tmerlier          #+#    #+#             */
/*   Updated: 2014/05/29 21:14:04 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

static void		limit_hist(void)
{
	t_hist	*tmp;

	tmp = glob()->hist;
	while (tmp->next)
		tmp = tmp->next;
	tmp = tmp->prev;
	free(tmp->next);
	tmp->next = NULL;
}

static t_hist	*init_history(char *str)
{
	t_hist	*new;

	if (!(new = (t_hist *)ft_memalloc(sizeof(t_hist))))
		malloc_error("init_history");
	new->line = ft_strdup(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			add_history(t_hist **hist, char *str)
{
	t_hist		*new;
	t_hist		*tmp;
	static int	i = 0;

	if (i == H_LIMIT)
	{
		limit_hist();
		i--;
	}
	new = init_history(str);
	if (!(*hist))
		*hist = new;
	else
	{
		tmp = *hist;
		*hist = new;
		(*hist)->next = tmp;
		tmp->prev = new;
	}
	i++;
}

void			history_down(void)
{
	static char	*str = NULL;
	int			i;

	if (lst_cursor()->start->c != 0)
		delete_cmdline(lst_cursor());
	if (glob()->hist && glob()->pos->prev)
	{
		str = ft_strdup(glob()->pos->line);
		if (str && !ft_strcmp(str, glob()->pos->line))
			glob()->pos = glob()->pos->prev;
		if (str)
			free(str);
		str = ft_strdup(glob()->pos->line);
		i = 0;
		while (str[i])
		{
			add_char(str[i]);
			i++;
		}
	}
}

void			history_up(void)
{
	static char		*str = NULL;
	int				i;

	if (lst_cursor()->start->c)
		delete_cmdline(lst_cursor());
	if (glob()->hist && glob()->pos)
	{
		if (str && !ft_strcmp(str, glob()->pos->line)
			&& glob()->pos->next)
			glob()->pos = glob()->pos->next;
		if (str)
			free(str);
		str = ft_strdup(glob()->pos->line);
		i = 0;
		while (str[i])
		{
			add_char(str[i]);
			i++;
		}
	}
}
