/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 20:32:48 by vcosson           #+#    #+#             */
/*   Updated: 2014/06/16 18:52:06 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>
#include <sh42.h>

void		init_term(void)
{
	char			buffer[2048];
	struct termios	term;

	if (!(ft_getenv("TERM")))
		termcaps_error("init_term - env");
	if (tgetent(buffer, ft_getenv("TERM")) != 1)
		termcaps_error("init_term - tgetent");
	tcgetattr(0, &term);
	tcgetattr(0, singleton_term());
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, 0, &term);
	tputs(tgetstr("im", NULL), 1, term_putchar);
}

void		exit_term(void)
{
	tputs(tgetstr("ei", NULL), 1, term_putchar);
	tcsetattr(0, 0, singleton_term());
}
