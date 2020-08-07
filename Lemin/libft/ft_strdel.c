/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:43:32 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:43:34 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	return (0);
}
