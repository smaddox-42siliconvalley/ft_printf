/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:18:08 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:18:10 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p(t_flag flags, va_list list, t_string **result)
{
	t_string			*string;

	string = (t_string*)malloc(sizeof(t_string));
	//mom(string);
	string->str = ft_unsignedlltoa_base(va_arg(list, unsigned long long), 16);
	string->len = ft_strlen(string->str);
	t_string_mom(string);
	//mom(string->str);
	p_min_width(&flags, &string);
	*result = t_string_join(**result, *string);
	t_string_mom(*result);
	return (0);
}

void	p_min_width(t_flag *flags, t_string **string)
{
	t_string	newstr;
	t_string	append;

	append.str = "0x";
	append.len = 2;
	newstr.len = flags->min_width - ((*string)->len + 2);
	if (newstr.len > 0)
	{
		newstr.str = ft_strnew(newstr.len);
		mom(newstr.str);
		ft_memset(newstr.str, 32, newstr.len);
		helper(flags, string, &newstr);
	}
	else
	{
		*string = t_string_join(append, **string);
		t_string_mom(*string);
	}
}

void	helper(t_flag *flags, t_string **string, t_string *newstr)
{
	t_string	append;

	append.str = "0x";
	append.len = 2;
	if ((contains('-', flags->h_flag, NUM_H_FLAGS)) != -1)
	{
		*string = t_string_join(append, **string);
		t_string_mom(*string);
		*string = t_string_join(**string, *newstr);
		t_string_mom(*string);
	}
	else
	{
		if ((contains('0', flags->h_flag, NUM_H_FLAGS)) != -1)
		{
			ft_memset(newstr->str, 48, newstr->len);
			newstr->str = ft_strjoin(append.str, newstr->str);
		}
		else
			newstr->str = ft_strjoin(newstr->str, append.str);
		mom(newstr->str);
		newstr->len = ft_strlen(newstr->str);
		*string = t_string_join(*newstr, **string);
		t_string_mom(*string);
	}
}
