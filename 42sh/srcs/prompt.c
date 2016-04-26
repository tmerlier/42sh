/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 15:12:17 by tmerlier          #+#    #+#             */
/*   Updated: 2014/06/16 19:08:31 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <sh42.h>

static void	prompt_path(void)
{
	char	*path;
	char	*home;
	char	*t_path;

	path = NULL;
	home = ft_getenv("HOME");
	if ((path = ft_getcwd()))
	{
		ft_putstr_color(GREEN, "[ ", 1);
		if (home && (t_path = ft_strstr(path, home)))
			ft_puttext_fd(CYAN, "~", t_path + ft_strlen(home), 1);
		else
			ft_putstr_color(BLUE, path, 1);
		ft_putstr_color(GREEN, " ] ", 1);
	}
	if (path)
		free(path);
	path = NULL;
}

static int	get_prompt(void)
{
	prompt_path();
	if (glob()->user)
		ft_putstr_color(BLUE, glob()->user, 1);
	ft_putstr_color(RESET, " $> ", 1);
	return (0);
}

int			prompt(void)
{
	tputs(tgetstr("up", NULL), 1, term_putchar);
	tputs(tgetstr("do", NULL), 1, term_putchar);
	tputs(tgetstr("ce", NULL), 1, term_putchar);
	get_prompt();
	return (0);
}
