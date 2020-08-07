/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:45:35 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:45:37 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*seno;
	char	*igla;
	int		i;
	int		j;

	i = 0;
	j = 0;
	seno = (char *)haystack;
	igla = (char *)needle;
	if (*seno == '\0' && *needle == '\0')
		return (&(seno[i]));
	while (seno[i])
	{
		while (igla[j] && seno[i + j] && (seno[i + j] == igla[j]))
		{
			j++;
		}
		if (igla[j] == '\0')
			return (&(seno[i]));
		i++;
		j = 0;
	}
	return (NULL);
}
