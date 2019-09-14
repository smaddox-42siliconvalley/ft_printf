/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:17:40 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:17:42 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		o(t_flag flags, va_list list, t_string **result)
{
	t_package	package;

	ft_bzero(&package, sizeof(t_package));
	package.flag = flags;
	package.string = (t_string*)malloc(sizeof(t_string));
	package.string->str = ft_unsignedlltoa_base(va_arg(list,
				unsigned long long), 8);
    t_string_mom(package.string);
	//mom(package.string);
	//mom(package.string->str);
	if ((contains('#', flags.h_flag, NUM_H_FLAGS)
				!= -1) && package.string->str[0] != '0')
		package.string->str = ft_strjoin("0", package.string->str);
	package.string->len = ft_strlen(package.string->str);
	o_formatter(&package);
	*result = t_string_join(**result, *(package.string));
	t_string_mom(*result);
	return (0);
}

void	o_formatter(t_package *package)
{
	d_sign(package);
	o_adjust_precision(package);
	d_min_width(package);
	if (package->mws)
		package->mws->len -= package->sign.len;
	dhelper(package);
}

void	o_adjust_precision(t_package *package)
{
	t_string temp;

	ft_bzero(&temp, sizeof(t_string));
	if (package->flag.precision == 0 && package->string->str[0] == '0')
	{
		if (contains('#', package->flag.h_flag, NUM_H_FLAGS) != -1)
			package->string->len = 1;
		else
			package->string->len = 0;
	}
	if (package->flag.precision < 9999 &&
			package->flag.precision > package->string->len)
	{
		temp.len = package->flag.precision - package->string->len;
		temp.str = ft_strnew(temp.len);
		mom(temp.str);
		ft_memset(temp.str, 48, temp.len);
	}
	package->string = t_string_join(temp, *(package->string));
	t_string_mom(package->string);
}
