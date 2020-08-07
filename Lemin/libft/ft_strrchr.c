/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:45:23 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:45:24 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*d;
	char	*last;
	int		flag;

	flag = 0;
	d = (char *)s;
	if ((char)c == '\0')
		return (d + ft_strlen(s));
	while (*d)
	{
		if ((char)c == *d)
		{
			last = d;
			flag = 1;
		}
		d++;
	}
	if (flag)
		return (last);
	return (NULL);
}
