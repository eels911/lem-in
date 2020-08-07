/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:37:26 by mannette          #+#    #+#             */
/*   Updated: 2020/06/02 20:37:29 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int		i;
	int		sum;
	char	*ptr;
	int		flag;

	flag = 0;
	ptr = (char *)nptr;
	sum = 0;
	i = 0;
	while ((ptr[i] <= 13 && ptr[i] >= 9) || ptr[i] == 32)
		i++;
	if (ptr[i] == '-')
		flag = 1;
	if (ptr[i] == '-' || ptr[i] == '+')
		i++;
	while (ptr[i] && (ptr[i] >= '0' && ptr[i] <= '9'))
	{
		sum = (sum * 10 + (ptr[i] - 48));
		i++;
	}
	if (flag)
		return (sum * (-1));
	return (sum);
}
