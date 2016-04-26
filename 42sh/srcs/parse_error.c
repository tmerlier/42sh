/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 13:35:15 by amazie            #+#    #+#             */
/*   Updated: 2014/06/22 21:36:37 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>
#include <libft.h>

static char	*str_token(int token)
{
	if (token == 0)
		return (";");
	else if (token == 1)
		return ("&& or ||");
	else if (token == 2)
		return ("|| or &&");
	else if (token == 3)
		return ("|");
	return ("UNKNOW");
}

int			parse_error(t_lex *temp, int token)
{
	if ((!temp) || (temp && temp->token < 4))
	{
		ft_putstr_fd("42sh: parse error ", 2);
		ft_putendl_fd(str_token(token), 2);
		return (1);
	}
	return (0);
}

static void	init_tab(int *tab, int type)
{
	if (type)
		tab[2] = 0;
	tab[0] = 0;
	tab[1] = 0;
}

int			undefine_file(t_lex *lst)
{
	if (!lst->next || lst->next->token != 8)
	{
		ft_putendl_fd("42sh: undefine file redirection", 2);
		return (1);
	}
	return (0);
}

int			redirec_check(t_lex *lst)
{
	int tab[3];

	init_tab(tab, 1);
	while (lst)
	{
		if ((lst->token == 3 && tab[0])
			|| (lst->token == 6 && tab[2])
			|| (tab[0] > 1 || tab[1] > 1))
		{
			ft_putendl_fd("42sh: ambigous redirection", 2);
			return (1);
		}
		else if (lst->token == 3)
			tab[2] = 1;
		else if (lst->token == 4 || lst->token == 5)
			tab[0]++;
		else if (lst->token == 6)
			tab[1]++;
		else if (!lst->token || lst->token == 1 || lst->token == 2)
			init_tab(tab, 1);
		if ((lst->token >= 4 && lst->token <= 6) && (undefine_file(lst)))
			return (1);
		lst = lst->next;
	}
	return (0);
}
