/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:18:25 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:21:06 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u(t_flag flags, va_list list, t_string **result)
{
	t_package package;

	ft_bzero(&package, sizeof(package));
	package.flag = flags;
	package.string = (t_string*)malloc(sizeof(t_string));
	package.string->str =
		ft_unsignedlltoa_base(va_arg(list, unsigned long long), 10);
    t_string_mom(package.string);
	//mom(package.string);
	//mom(package.string->str);
	package.string->len = ft_strlen(package.string->str);
	d_formatter(&package);
	*result = t_string_join(**result, *(package.string));
	t_string_mom(*result);
	return (0);
}
