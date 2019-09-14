/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcflag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:18:03 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:18:04 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent(t_flag flags, va_list list, t_string **result)
{
	t_string	*str;

	if (list)
	{
		;
	}
	str = (t_string*)malloc(sizeof(t_string));
	str->len = 1;
	str->str = ft_strnew(1);
	t_string_mom(str);
	//mom(str->str);
	str->str[0] = '%';
	c_min_width(flags, &str);
	*result = t_string_join(**result, *str);
	t_string_mom(*result);
	return (0);
}
