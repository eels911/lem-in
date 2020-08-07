/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:45:29 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:45:30 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_findlen(const char *s, size_t i, char c)
{
	size_t	wordlen;

	wordlen = 0;
	while (s[i] != c && s[i])
	{
		i++;
		wordlen++;
	}
	return (wordlen);
}

static size_t	ft_wordnum(const char *s, char c)
{
	size_t	wordnum;
	size_t	i;
	int		flag;

	flag = 0;
	i = 0;
	wordnum = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			i += ft_findlen(s, i, c);
			wordnum++;
		}
	}
	return (wordnum);
}

char			**ft_just_to_fit_in_25(char const *s, char c,
size_t i, char **ar)
{
	size_t	j;

	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			ar[j] = ft_strsub(s, i, ft_findlen(s, i, c));
			j++;
			if (s[i] != '\0')
				i = i + ft_findlen(s, i, c);
		}
		if (s[i] != '\0')
			i++;
	}
	ar[j] = NULL;
	return (ar);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ar;
	size_t	i;

	if (!s || !c)
		return (NULL);
	i = 0;
	if ((ar = ft_memalloc(sizeof(char*) * (ft_wordnum(s, c) + 1))))
		return (ft_just_to_fit_in_25(s, c, i, ar));
	else
	{
		ft_strdel(ar);
		return (NULL);
	}
}
