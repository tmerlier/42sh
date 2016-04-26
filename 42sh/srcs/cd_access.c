/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 21:13:08 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:47:04 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <sh42.h>
#include <unistd.h>
#include <stdlib.h>

static void	ft_set_pwd(void)
{
	char	*new_path;

	new_path = NULL;
	new_path = ft_getcwd();
	set_glob("OLDPWD", glob()->pwd, 6);
	set_glob("PWD", new_path, 3);
	if (new_path)
	{
		free(new_path);
		new_path = NULL;
	}
}

static void	ft_er_access(int i, char *path)
{
	if (i == 0)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (i == 1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd("permission denied: ", 2);
		ft_putendl_fd(path, 2);
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd("not a directory: ", 2);
		ft_putendl_fd(path, 2);
	}
}

int			ft_access(char *path)
{
	struct stat		file;

	if (access(path, F_OK) == -1)
	{
		ft_er_access(0, path);
		return (0);
	}
	stat(path, &file);
	if (file.st_mode & S_IFDIR)
	{
		if (chdir(path) < 0)
			ft_er_access(1, path);
		else
			ft_set_pwd();
	}
	else
		ft_er_access(2, path);
	return (0);
}
