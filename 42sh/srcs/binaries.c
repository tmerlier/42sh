/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 13:16:30 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:16:31 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

char		**bin(char *cmd, char *path_env)
{
	char	**path;
	char	**temp;

	if (!path_env)
		return (ft_strsplit(cmd, ' '));
	path = ft_strsplit(path_env, ':');
	temp = path;
	path_env = NULL;
	while (*temp)
	{
		path_env = ft_strjoin(*temp, "/");
		free(*temp);
		*temp = ft_strjoin(path_env, cmd);
		free(path_env);
		path_env = NULL;
		temp++;
	}
	return (path);
}
