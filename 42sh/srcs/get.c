/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 21:13:08 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:47:04 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <sh42.h>

char		*ft_getcwd(void)
{
	char	*path;
	int		i;

	i = 1;
	while (42)
	{
		path = NULL;
		if (!(path = (char *)ft_memalloc(i * sizeof(path))))
			return (NULL);
		if (getcwd(path, i))
			return (path);
		free(path);
		i += 1;
		if (i > 255)
			return (NULL);
	}
}

char		*ft_getenv(char *name)
{
	t_env	*temp;

	temp = glob()->env;
	while (temp)
	{
		if (ft_strcmp(name, temp->name) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
