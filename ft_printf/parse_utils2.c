/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:17:52 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:17:54 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		contains(char c, char *str, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (c == str[i])
			return (i);
	}
	return (-1);
}

int		str_num_len(const char *format)
{
	int len;

	len = 0;
	while (format[len] && ft_isdigit(format[len]))
		len++;
	return (len);
}
