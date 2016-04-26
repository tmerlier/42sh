/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 13:24:26 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:24:35 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <libft.h>
#include <termios.h>
#include <stdlib.h>
#include <sh42.h>

static void		init_shell(char **env)
{
	glob()->env = init_env(env);
	glob()->user = ft_getenv("USER");
	init_signal();
	init_term();
}

int				main(int ac, char **av, char **env)
{
	char	*line;

	(void)ac;
	(void)av;
	init_shell(env);
	while (glob()->exit_sh == -1)
	{
		prompt();
		line = get_line();
		tputs(tgetstr("do", NULL), 1, term_putchar);
		if (line && *line != '\0')
			lexer(line, NULL);
		exit_term();
		init_term();
		free(line);
	}
	exit_term();
	return (glob()->exit_sh);
}
