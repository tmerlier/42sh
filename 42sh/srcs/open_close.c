/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 21:13:08 by amazie            #+#    #+#             */
/*   Updated: 2014/06/21 13:47:04 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sh42.h>
#include <libft.h>

int		open_file(char *str, int type)
{
	int	fd;

	if (type == 1)
		fd = open(str, O_RDONLY);
	else if (type == 2)
		fd = open(str, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		isexist(str, 0, 1);
		return (-1);
	}
	else
		return (fd);
}
