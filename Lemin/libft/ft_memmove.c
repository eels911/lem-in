/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:41:45 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:41:46 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*res;
	unsigned char	*orig;
	size_t			i;

	i = 0;
	res = (unsigned char *)dst;
	orig = (unsigned char *)src;
	if (src < dst)
	{
		while (n > 0)
		{
			n--;
			*(res + n) = *(orig + n);
		}
	}
	else
	{
		while (i < n)
		{
			*(res + i) = *(orig + i);
			i++;
		}
	}
	return (res);
}
