/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 20:22:30 by tmerlier          #+#    #+#             */
/*   Updated: 2014/06/16 19:06:11 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh42.h>

static int		lst_count(t_chara *lst)
{
	t_chara			*temp;
	unsigned int	i;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

char			*lst_to_str(t_chara *lst)
{
	t_chara	*temp;
	t_chara	*del;
	char	*str;
	int		i;

	i = 0;
	temp = lst;
	if (!(str = ft_memalloc(lst_count(lst) * sizeof(char))))
		malloc_error("lst_to_str");
	while (temp)
	{
		del = temp;
		str[i++] = temp->c;
		temp = temp->next;
		free(del);
	}
	lst_cursor()->start = lst_cursor()->end;
	lst_cursor()->current = lst_cursor()->end;
	str[i] = '\0';
	return (str);
}
