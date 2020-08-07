/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:41:08 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:41:10 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*res;
	unsigned char		*orig;
	unsigned char		f;
	size_t				i;

	f = (unsigned char)c;
	i = 0;
	res = (unsigned char *)dst;
	orig = (unsigned char *)src;
	while (i < n)
	{
		if (orig[i] == f)
		{
			*(res + i) = *(orig + i);
			return (res + i + 1);
		}
		else
		{
			*(res + i) = *(orig + i);
			i++;
		}
	}
	return (NULL);
}
