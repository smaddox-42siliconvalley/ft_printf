/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:18:13 by smaddox           #+#    #+#             */
/*   Updated: 2019/09/08 19:56:46 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s(t_flag flags, va_list list, t_string **result)
{
	t_string	*temp;

	temp = (t_string*)malloc(sizeof(t_string));
	mom(temp);
	temp->str = va_arg(list, char*);
	if (!temp->str)
		temp->str = "(null)";
	temp->len = ft_strlen(temp->str);
	str_precision(&flags, &temp);
	str_min_width(&flags, &temp);
	*result = t_string_join(**result, *temp);
	t_string_mom((*result));
	return (0);
}

void	str_precision(t_flag *flags, t_string **string)
{
	char *temp;

	if ((*string)->len > flags->precision)
	{
		(*string)->len = flags->precision;
		temp = ft_strnew(flags->precision);
		mom(temp);
		temp = ft_strncpy(temp, (*string)->str, flags->precision);
		(*string)->str = temp;
	}
}

void	str_min_width(t_flag *flags, t_string **string)
{
	t_string	newstr;

	newstr.len = flags->min_width - (*string)->len;
	if (newstr.len > 0)
	{
		newstr.str = ft_strnew(newstr.len);
		mom(newstr.str);
		if ((contains('-', flags->h_flag, NUM_H_FLAGS)) != -1)
		{
			ft_memset(newstr.str, 32, newstr.len);
			*string = t_string_join(**string, newstr);
			t_string_mom(*string);
		}
		else
		{
			if ((contains('0', flags->h_flag, NUM_H_FLAGS)) != -1)
				ft_memset(newstr.str, 48, newstr.len);
			else
				ft_memset(newstr.str, 32, newstr.len);
			*string = t_string_join(newstr, **string);
			t_string_mom(*string);
		}
	}
}
