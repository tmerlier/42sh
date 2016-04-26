/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 13:23:10 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:23:16 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <stdlib.h>
#include <signal.h>
#include <libft.h>
#include <sh42.h>

void		signal_interrupt(int sig)
{
	(void)sig;
	tputs(tgetstr("do", NULL), 1, term_putchar);
	delete_cmdline(lst_cursor());
	prompt();
}

void		signal_quit(int sig)
{
	(void)sig;
	exit_term();
	exit(0);
}

void		signal_eof(int sig)
{
	(void)sig;
	ft_putchar('\n');
	exit_term();
	exit(0);
}

void		init_signal(void)
{
	signal(SIGQUIT, signal_quit);
	signal(SIGINT, signal_interrupt);
	signal(SIGHUP, signal_quit);
}
