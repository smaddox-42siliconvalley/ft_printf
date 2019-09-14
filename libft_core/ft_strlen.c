/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:23:42 by smaddox           #+#    #+#             */
/*   Updated: 2019/04/29 14:24:21 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str)
{
	size_t	counter;
	char	*temp;

	temp = (char*)str;
	counter = 0;
	while (*temp)
	{
		counter++;
		temp++;
	}
	return (counter);
}
