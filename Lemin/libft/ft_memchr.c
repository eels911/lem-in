/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:41:16 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:41:18 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	charc;
	unsigned char	*str;

	charc = (unsigned char)c;
	str = (unsigned char *)b;
	while (len > 0)
	{
		if (charc == *str)
		{
			return (str);
		}
		str++;
		len--;
	}
	return (NULL);
}
