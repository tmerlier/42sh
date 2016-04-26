/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 11:00:28 by amazie            #+#    #+#             */
/*   Updated: 2014/06/11 16:01:58 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

static void	no_space(char **line)
{
	char	*temp;

	temp = *line;
	while (*temp && (*temp == ' ' || *temp == '\t'))
		temp++;
	*line = temp;
}

void		lexer(char *line, t_lex *lst)
{
	int		param[3];

	param[2] = 0;
	while (*line)
	{
		no_space(&line);
		if (!*line)
			break ;
		if ((is_token(line, param)))
		{
			add_token(&lst, param);
			line = line + param[1];
		}
		else if ((is_word(line, param)))
		{
			add_word(&lst, param, line);
			line = line + param[1];
		}
		else
		{
			add_word(&lst, NULL, line);
			line++;
		}
	}
	parser(&lst);
}
