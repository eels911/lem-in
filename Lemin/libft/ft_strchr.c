/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:43:03 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:43:05 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *d;

	d = (char *)s;
	if ((char)c == '\0')
		return (d + ft_strlen(s));
	while (*d)
	{
		if ((char)c == *d)
			return (d);
		d++;
	}
	return (NULL);
}
