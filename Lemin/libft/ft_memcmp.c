/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:41:22 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:41:24 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)b1;
	s2 = (unsigned char *)b2;
	if (len == 0)
		return (0);
	while (--len)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
	}
	return (*s1 - *s2);
}
