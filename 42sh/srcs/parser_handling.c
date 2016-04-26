/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 13:43:04 by amazie            #+#    #+#             */
/*   Updated: 2014/06/14 13:43:06 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>
#include <libft.h>
#include <stdlib.h>

t_pars				*add_three(int token)
{
	t_pars	*new_three;

	new_three = NULL;
	if (!(new_three = ft_memalloc(sizeof(t_pars *))))
	{
		ft_putendl_fd("42sh: An error occured code : 003\nexit", 2);
		exit(-1);
	}
	new_three->token = token;
	new_three->left = NULL;
	new_three->right = NULL;
	new_three->cmd = NULL;
	return (new_three);
}

static void			add_redirect(t_lex *temp, t_pars_cmd **pars_new)
{
	if (temp->token == 4)
		(*pars_new)->r_out = ft_strdup(temp->next->name);
	else if (temp->token == 5)
		(*pars_new)->r_new_out = ft_strdup(temp->next->name);
	else if (temp->token == 6)
		(*pars_new)->r_in = ft_strdup(temp->next->name);
}

static void			add_cmd(t_lex *temp, t_pars_cmd **pars_new)
{
	char	*cmd_join;

	cmd_join = NULL;
	if (!(*pars_new)->cmd)
		(*pars_new)->cmd = ft_strdup(temp->name);
	else
	{
		if (!(cmd_join = ft_strjoin((*pars_new)->cmd, " ")))
		{
			ft_putendl_fd("42sh: An error occured code : 004\nexit", 2);
			exit(-1);
		}
		free((*pars_new)->cmd);
		if (!((*pars_new)->cmd = ft_strjoin(cmd_join, temp->name)))
		{
			ft_putendl_fd("42sh: An error occured code : 005\nexit", 2);
			exit(-1);
		}
		free(cmd_join);
		cmd_join = NULL;
	}
}

static t_pars_cmd	*add_pars_cmd(t_lex *lex)
{
	t_pars_cmd	*pars_new;
	t_lex		*temp;

	pars_new = NULL;
	temp = lex;
	if (!(pars_new = ft_memalloc(sizeof(t_pars_cmd))))
		return (NULL);
	pars_new->cmd = NULL;
	while (temp && temp->token > 3)
	{
		if (temp->token < 7)
		{
			add_redirect(temp, &pars_new);
			temp = temp->next;
		}
		else if (temp->token == 7 || temp->token == 9)
			add_cmd(temp, &pars_new);
		temp = temp->next;
	}
	return (pars_new);
}

t_pars				*add_three_cmd(t_lex *lex)
{
	t_pars	*new_three;

	new_three = NULL;
	if (!(new_three = ft_memalloc(sizeof(t_pars *))))
	{
		ft_putendl_fd("42sh: An error occured code : 001\nexit", 2);
		exit(-1);
	}
	new_three->token = 7;
	new_three->left = NULL;
	new_three->right = NULL;
	if (!(new_three->cmd = add_pars_cmd(lex)))
	{
		ft_putendl_fd("42sh: An error occured code : 002\nexit", 2);
		exit(-1);
	}
	return (new_three);
}
