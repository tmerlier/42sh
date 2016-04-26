/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 20:23:15 by tmerlier          #+#    #+#             */
/*   Updated: 2014/06/16 18:37:42 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include <libft.h>
#include <sh42.h>

static void		move_input(char key[4])
{
	if ((K2 == 68 || K2 == 67) && K3 == 0)
		cursor_move(key);
	else if (K2 == 72 && K3 == 0)
		move_home(lst_cursor());
	else if (K2 == 65 && K3 == 0)
		history_up();
	else if (K2 == 66 && K3 == 0)
		history_down();
	else if (K2 == 70 && K3 == 0)
		move_end(lst_cursor());
	else
		return ;
}

static void		exec_key(char key[4])
{
	static int	del = 0;

	if (K0 == 27 && K1 == 91 && K2 == 51 && K3 == 0)
	{
		del = 1;
		delete_input(lst_cursor());
	}
	else if (K0 == 27 && K1 == 91 && K2 > 64)
		move_input(key);
	else if (K0 == 127 && K1 == 0 && K2 == 0 && K3 == 0)
		backspace_input(lst_cursor());
	else if (K0 == -61 && K1 == -91 && K2 == 0 && K3 == 0)
		move_left(lst_cursor());
	else if (K0 == -30 && K1 == -120 && K2 == -126 && K3 == 0)
		move_right(lst_cursor());
	else if (K0 == 4 && K1 == 0 && K2 == 0 && K3 == 0)
		signal_eof(0);
	else if (K1 == 0 && K2 == 0 && ft_isprint(K0) && K3 == 0 && del == 0)
		add_char(K0);
	else
		del = 0;
}

char			*get_line(void)
{
	static char		key[10] = { 0 };
	char			*cmdline;

	cmdline = NULL;
	init_cursor_lst();
	while (read(0, key, 3) && !(K0 == 10 && K1 == 0 && K2 == 0))
	{
		exec_key(key);
		ft_bzero(key, 10);
	}
	cmdline = lst_to_str(lst_cursor()->start);
	if (ft_strlen(cmdline) != 0)
	{
		add_history(&(glob()->hist), cmdline);
		glob()->pos = glob()->hist;
	}
	return (cmdline);
}

void			add_char(char c)
{
	tputs(tgetstr("ic", NULL), 1, term_putchar);
	add_chara_lst(lst_cursor(), c);
	write(1, &c, 1);
}
