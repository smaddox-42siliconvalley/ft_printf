/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:17:18 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:17:20 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		d(t_flag flags, va_list list, t_string **result)
{
	t_package	package;

	ft_bzero(&package, sizeof(package));
	package.string = (t_string*)malloc(sizeof(t_string));
	package.flag = flags;
	if ((ft_strequ(flags.l_flag, "hh")))
		package.string->str = ft_itoa_base((signed char)va_arg(list, int), 10); //hh flag didn't overflow until cast to signed char
	else if ((ft_strequ(flags.l_flag, "h")))
		package.string->str = ft_shorttoa_base(va_arg(list, int), 10);
	else if ((ft_strequ(flags.l_flag, "ll")))
		package.string->str = ft_longlongtoa_base(va_arg(list, long long), 10);
	else if ((ft_strequ(flags.l_flag, "l")))
		package.string->str = ft_longlongtoa_base(va_arg(list, long), 10);
	else
		package.string->str = ft_itoa_base(va_arg(list, int), 10);
    t_string_mom(package.string);
	//mom(package.string);
	//mom(package.string->str);
	package.string->len = ft_strlen(package.string->str);
	d_formatter(&package);
	*result = t_string_join(**result, *(package.string));
	t_string_mom(*result); //testing
	return (0);
}

void	d_adjust_precision(t_package *package)
{
	t_string temp;

	ft_bzero(&temp, sizeof(t_string));
	if (package->flag.precision == 0 && package->string->str[0] == '0')
		package->string->len = 0;
	if (package->flag.precision < 9999 &&
			package->flag.precision > package->string->len)
	{
		temp.len = (package->flag.precision) - (package->string->len);
		temp.str = ft_strnew(temp.len);
		mom(temp.str);
		ft_memset(temp.str, 48, temp.len);
	}
	package->string = t_string_join(temp, *(package->string));
	t_string_mom(package->string);
}

void	d_formatter(t_package *package)
{
	d_sign(package);
	d_adjust_precision(package);
	d_min_width(package);
	if (package->mws)
		package->mws->len -= package->sign.len;
	dhelper(package);
}

void	d_sign(t_package *package)
{
	if (package->string->str[0] == '-')
	{
		package->sign.str = "-";
		package->sign.len = 1;
		package->string->str = ft_strsub(package->string->str,
				1, (package->string->len - 1));
		package->string->len = ft_strlen(package->string->str);
		mom(package->string->str);
	}
	else if (contains('+', package->flag.h_flag, NUM_H_FLAGS) != -1)
	{
		package->sign.str = "+";
		package->sign.len = 1;
	}
	else if (contains(32, package->flag.h_flag, NUM_H_FLAGS) != -1)
	{
		package->sign.str = " ";
		package->sign.len = 1;
	}
}

void	d_min_width(t_package *package)
{
	if ((package->flag.min_width) - (package->string->len) > 0)
	{
		package->mws = (t_string*)malloc(sizeof(t_string));
		//mom(package->mws);
		package->mws->len = (package->flag.min_width) - (package->string->len);
		package->mws->str = ft_strnew(package->mws->len);
		t_string_mom(package->mws);
		//mom(package->mws->str);
		if (((contains('0', package->flag.h_flag, NUM_H_FLAGS)) != -1) &&
			((contains('-', package->flag.h_flag, NUM_H_FLAGS)) == -1) &&
			package->flag.precision == 9999)
			ft_memset(package->mws->str, 48, package->mws->len);
		else
			ft_memset(package->mws->str, 32, package->mws->len);
	}
}
