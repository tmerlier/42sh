/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 21:13:08 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:47:04 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <sh42.h>

void		add_token(t_lex **lst, int *param)
{
	t_lex	*new_lst;

	new_lst = NULL;
	if (!(new_lst = ft_memalloc(sizeof(t_lex *))))
	{
		ft_putendl_fd("42sh: An error occured code : 006\nexit", 2);
		exit(1);
	}
	new_lst->token = prior_tok(param[0]);
	new_lst->name = NULL;
	new_lst->next = NULL;
	param[2] = param[0];
	add_lst(lst, &new_lst);
}

void		add_word(t_lex **lst, int *param, char *line)
{
	t_lex	*new_lst;

	if (!(new_lst = ft_memalloc(sizeof(t_lex *))))
	{
		ft_putendl_fd("42sh: An error occured code : 007\nexit", 2);
		exit(1);
	}
	if (!param)
	{
		new_lst->token = UNKNOW;
		new_lst->name = ft_strsub(line, 0, 1);
	}
	else
	{
		if ((param[2] < 5 && param[2] != 2) || param[2] == FILE)
			param[2] = CMD;
		else if (param[2] < 7 || param[2] == 2)
			param[2] = FILE;
		else
			param[2] = OPTION;
		new_lst->token = param[2];
		new_lst->name = ft_strsub(line, 0, param[1]);
	}
	new_lst->next = NULL;
	add_lst(lst, &new_lst);
}

static int	grammar_check(char str)
{
	if (str == ';' || str == '&' || str == '|'
		|| str == '<' || str == '>' || str == ' ')
		return (0);
	return (1);
}

int			is_token(char *line, int *param)
{
	char	*test[8];

	param[0] = 0;
	init_token(test);
	while (test[param[0]])
	{
		param[1] = ft_strlen(test[param[0]]);
		if (!ft_strncmp(line, test[param[0]], param[1]))
			return (1);
		param[0]++;
	}
	return (0);
}

int			is_word(char *line, int *param)
{
	char	*temp;

	if (grammar_check(*line))
	{
		temp = line;
		while (*temp && grammar_check(*temp))
			temp++;
		param[1] = temp - line;
		return (1);
	}
	return (0);
}
