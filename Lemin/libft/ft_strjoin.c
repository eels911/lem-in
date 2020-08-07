/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:44:09 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:44:11 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		if ((fresh = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		{
			ft_strcpy(fresh, s1);
			ft_strcpy(fresh + ft_strlen(s1), s2);
			return (fresh);
		}
	}
	return (NULL);
}
