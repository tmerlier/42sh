/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isaccess.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 20:54:52 by amazie            #+#    #+#             */
/*   Updated: 2014/06/17 20:54:54 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <libft.h>

static int	isexec(char *tmp, int key)
{
	struct stat	file;

	if (!access(tmp, X_OK))
	{
		stat(tmp, &file);
		if (file.st_mode & S_IFREG)
			return (0);
		ft_puttext_fd("42sh: ", tmp, " is not a exec file\n", 2);
		if (key)
			return (5);
		exit(5);
	}
	return (1);
}

int			isexist(char *tmp, int type, int key)
{
	if (!access(tmp, F_OK))
	{
		if (!isexec(tmp, key))
			return (0);
		else
			ft_puttext_fd("42sh: permission denied: ", tmp, "\n", 2);
		if (key)
			return (6);
		exit(6);
	}
	else if (!type)
	{
		ft_puttext_fd("42sh: no such file or directory: ", tmp, "\n", 2);
		if (key)
			return (7);
		exit(7);
	}
	return (1);
}

int			isaccess(char **cmd, int type, int key)
{
	char		**tmp;
	int			i;

	i = 0;
	tmp = cmd;
	while (tmp[i])
	{
		if (!isexist(tmp[i], type, key))
			return (i);
		else
			i++;
	}
	return (-1);
}
