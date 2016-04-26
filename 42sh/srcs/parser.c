/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 13:25:27 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:25:33 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sh42.h>

static int	parser_pv(t_lex *lst, t_lex *stop, int token, t_pars **three)
{
	int		i;
	t_lex	*temp;

	temp = lst;
	i = 0;
	if (parse_error(temp, token))
		return (1);
	if ((!temp) || (token > 3 && (*three = add_three_cmd(temp))))
		return (0);
	while (temp && temp != stop)
	{
		if ((temp->token == token) || (temp->token == 2 && token == 1))
		{
			*three = add_three(temp->token);
			if (parser_pv(lst, temp, token + 1, &(*three)->left) ||
				parser_pv(temp->next, stop, token, &(*three)->right))
				return (1);
			i = 1;
			break ;
		}
		temp = temp->next;
	}
	if (!i && parser_pv(lst, stop, token + 1, three))
		return (1);
	return (0);
}

int			parser(t_lex **lst)
{
	t_pars	*three;

	three = NULL;
	if (!*lst)
		return (1);
	if (redirec_check(*lst))
	{
		free_lst_lex(lst);
		return (0);
	}
	if (!parser_pv(*lst, NULL, 0, &three))
	{
		free_lst_lex(lst);
		glob()->ex_return = exec_pars(three, 0, 0) % 255;
	}
	if (*lst)
		free_lst_lex(lst);
	if (three)
		free_three(&three);
	return (0);
}
