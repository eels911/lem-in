/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:43:38 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:43:40 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_strlen(str);
	if (!(str2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		str2[i] = str[i];
	str2[i] = '\0';
	return (str2);
}
