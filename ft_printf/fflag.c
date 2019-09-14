/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:17:26 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/21 23:34:58 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f(t_flag flags, va_list list, t_string **result)
{
	t_package package;

	ft_bzero(&package, sizeof(package));
	if (flags.precision == 9999)
		flags.precision = 6;
	package.flag = flags;
	package.string = (t_string*)malloc(sizeof(t_string));
	if (contains('L', flags.l_flag, 3) != -1)
		package.string->str = ft_longdtoa(va_arg(list,
					long double), package.flag.precision);
	else
		package.string->str = ft_dtoa(va_arg(list,
					double), package.flag.precision);
	t_string_mom(package.string);
	package.string->len = ft_strlen(package.string->str);
	package.flag.precision = 9999;
	f_formatter(&package);
	*result = t_string_join(**result, *(package.string));
	t_string_mom(*result);
	return (0);
}

void	f_formatter(t_package *package)
{
	f_limit(package);
	d_sign(package);
	if ((contains('#', package->flag.h_flag, NUM_H_FLAGS) != -1) &&
			(contains('.', package->string->str, package->string->len) == -1))
	{
		package->string->str = ft_strjoin(package->string->str, ".");
		package->string->len++;
		mom(package->string->str);
	}
	d_min_width(package);
	if (package->mws)
		package->mws->len -= package->sign.len;
	dhelper(package);
}

void	f_limit(t_package *package)
{
	if (ft_strequ(package->string->str, "inf") ||
			ft_strequ(package->string->str, "-inf") ||
			ft_strequ(package->string->str, "nan"))
	{
		package->flag.h_flag[2] = 0;
		package->flag.h_flag[1] = 0;
	}
}
