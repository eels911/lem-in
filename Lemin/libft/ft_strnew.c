/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:45:10 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:45:12 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *c;

	if ((c = (char *)malloc(size + 1)))
	{
		ft_memset(c, '\0', size + 1);
		return (c);
	}
	return (NULL);
}
