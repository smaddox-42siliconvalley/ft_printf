/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:17:46 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:17:49 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*set_h_flags(const char *format, t_flag *flags)
{
	int		i;

	format++;
	if (*format == '%')
		return (format);
	while (*format)
	{
		if ((i = contains(*format, H_FLAGS, NUM_H_FLAGS)) != -1)
			flags->h_flag[i] = H_FLAGS[i];
		else
			break ;
		format++;
	}
	return (format);
}

const char		*set_min_width(const char *format, t_flag *flags)
{
	int		len;
	char	*str;

	len = 0;
	len = str_num_len(format);
	if (len)
	{
		str = ft_strsub(format, 0, len);
		flags->min_width = ft_atoi(str);
		if (str)
			free(str);
		return (format + len);
	}
	else
		return (format);
}

const char		*set_precision(char const *format, t_flag *flags)
{
	char	*str;
	int		len;

	if (*format == '.')
	{
		format++;
		len = str_num_len(format);
		if (len)
		{
			str = ft_strsub(format, 0, len);
			flags->precision = (ft_atoi(str));
			if (str)
				free(str);
			return (format + len);
		}
		flags->precision = 0;
	}
	return (format);
}

const char		*set_l_flags(const char *format, t_flag *flags)
{
	char flag;

	flag = *format;
	if ((contains(flag, L_FLAGS, NUM_L_FLAGS) != -1))
	{
		flags->l_flag[0] = flag;
		format++;
		if (*format == flag)
		{
			flags->l_flag[1] = flag;
			format++;
		}
	}
	return (format);
}

const char		*set_arg_type(const char *format, t_flag *flags,
		int *code, t_dispatch_table dispatch)
{
	int i;

	i = -1;
	*code = -1;
	while (++i < TABLE_LEN)
	{
		if (*format == dispatch.table[i].key)
		{
			flags->arg_type = *format;
			format++;
			*code = i;
			break ;
		}
	}
	return (format);
}
