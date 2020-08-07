/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:43:23 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:43:25 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned char	*orig;
	unsigned char	*res;

	orig = (unsigned char *)src;
	res = (unsigned char *)dest;
	while (*orig)
		*(res++) = *(orig++);
	*res = '\0';
	return (dest);
}
