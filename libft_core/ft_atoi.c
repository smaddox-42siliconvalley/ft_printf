/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:07:27 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/03 19:41:44 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	total;
	int		sign;
	int		i;

	sign = 1;
	total = 0;
	i = 0;
	while ((*(nptr + i) >= 8 && *(nptr + i) <= 13) || *(nptr + i) == 32)
	{
		i++;
	}
	if (*(nptr + i) == '-')
	{
		sign = -1;
		i++;
	}
	else if (*(nptr + i) == '+')
	{
		i++;
	}
	while (*(nptr + i) && *(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		total = (total * 10) + (*(nptr + i++) - '0');
	}
	return ((int)total * sign);
}
