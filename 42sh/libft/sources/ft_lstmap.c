/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <amazie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:04:44 by amazie            #+#    #+#             */
/*   Updated: 2014/05/23 15:27:46 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static void		ft_cpymap(t_list *new, t_list *lst, t_list *(*f)(t_list *elem))
{
	while (lst)
	{
		new->content = (f(lst))->content;
		new->content_size = sizeof((f(lst))->content);
		new = new->next;
		lst = lst->next;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	int			i;
	t_list		*cpy;
	t_list		*new;
	t_list		*ele;

	cpy = lst;
	i = 0;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	while (i > 1)
	{
		ele = ft_lstnew(NULL, 0);
		ft_lstadd(&new, ele);
		i--;
	}
	ft_cpymap(new, lst, (*f));
	return (new);
}
