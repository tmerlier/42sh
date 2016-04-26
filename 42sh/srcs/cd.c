/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 17:12:18 by amazie            #+#    #+#             */
/*   Updated: 2014/06/19 17:12:19 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

static char	*istild(char **str)
{
	char	*temp;
	char	*tmp;
	char	*path;

	temp = *str;
	if (!ft_strncmp(temp, "~/", 2))
	{
		tmp = NULL;
		tmp = ft_strdup(ft_getenv("HOME"));
		if (!tmp)
			return (*str);
		path = ft_strjoin(tmp, *(str) + 1);
		free(tmp);
		tmp = NULL;
		free(*str);
		*str = path;
	}
	return (*str);
}

static char	*ft_chg_path(char *str, char *dest, char *path)
{
	char	*dir;
	char	*temp;
	char	*temp1;
	size_t	i;

	temp1 = NULL;
	dir = ft_getcwd();
	if ((temp = ft_strstr(dir, str)))
	{
		i = ft_strlen(dir) + ft_strlen(dest) - ft_strlen(str) + 1;
		path = (char *)malloc(i * sizeof(path));
		temp1 = ft_strsub(dir, 0, temp - dir);
		ft_strcpy(path, temp1);
		ft_strcat(path, dest);
		ft_strcat(path, temp + ft_strlen(str));
	}
	else
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(str, 2);
	}
	ft_free_line(&dir);
	ft_free_line(&temp1);
	return (path);
}

int			cd(char **cmd)
{
	char	*path;

	path = NULL;
	if (!cmd[1] || (!ft_strncmp(cmd[1], "~", 2) && !cmd[2]))
		path = ft_strdup(ft_getenv("HOME"));
	else if (!ft_strcmp(cmd[1], "-") && !cmd[2])
		path = ft_strdup(ft_getenv("OLDPWD"));
	else if (!cmd[2])
		path = ft_strdup(istild(&cmd[1]));
	else if (!cmd[3])
		path = ft_chg_path(istild(&cmd[1]), istild(&cmd[2]), NULL);
	else
		ft_putendl_fd("cd: Too many arguments", 2);
	if (path)
	{
		if (glob()->pwd)
			free(glob()->pwd);
		glob()->pwd = ft_getcwd();
		ft_access(path);
	}
	if (path)
		free(path);
	return (0);
}
