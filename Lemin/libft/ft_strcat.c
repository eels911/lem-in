/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:42:58 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:42:59 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t k;

	k = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[k])
		dest[i++] = src[k++];
	dest[i] = '\0';
	return (dest);
}
