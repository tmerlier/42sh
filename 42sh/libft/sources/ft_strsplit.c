/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 19:06:14 by amazie            #+#    #+#             */
/*   Updated: 2014/02/06 14:52:22 by amazie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_word(char *temp, char c)
{
	int		i;

	i = 0;
	while (*temp)
	{
		while (*temp == c && *temp)
			temp++;
		if (*temp)
			i++;
		while (*temp != c && *temp)
			temp++;
	}
	return (i + 1);
}

char		*ft_word_sub(char *s, char c)
{
	char	*temp;
	char	*str;
	int		i;

	i = 0;
	temp = s;
	while (*temp != c && *temp)
	{
		temp++;
		i++;
	}
	str = (char *)malloc((i + 1) * sizeof(str));
	temp = str;
	while (*s && *s != c)
		*str++ = *s++;
	*str = '\0';
	return (temp);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*temp;
	char	**str_t;

	if (!s)
		return (NULL);
	temp = (char *)s;
	str = (char **)malloc(ft_word(temp, c) * sizeof(str));
	str_t = str;
	while (*temp)
	{
		while (*temp == c && *temp)
			temp++;
		if (*temp)
		{
			*str = ft_word_sub(temp, c);
			str++;
		}
		while (*temp != c && *temp)
			temp++;
	}
	*str = 0;
	return (str_t);
}
