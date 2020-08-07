/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:41:30 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:41:32 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*res;
	const char	*orig;
	size_t		i;

	i = 0;
	res = dst;
	orig = src;
	while (i < n)
	{
		*(res + i) = *(orig + i);
		i++;
	}
	return (res);
}
