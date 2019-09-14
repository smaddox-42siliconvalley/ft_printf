/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxflag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:18:35 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:18:40 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	capital(t_package *package)
{
	int i;

	i = -1;
	while (++i < package->string->len)
		package->string->str[i] =
			ft_toupper(package->string->str[i]);
}

int		xx(t_flag flags, va_list list, t_string **result)
{
	t_package package;

	ft_bzero(&package, sizeof(t_package));
	package.flag = flags;
	package.string = (t_string*)malloc(sizeof(t_string));
	package.string->str =
		ft_unsignedlltoa_base(va_arg(list,
					unsigned long long), 16);
	mom(package.string);
	mom(package.string->str);
	package.string->len = ft_strlen(package.string->str);
	x_formatter(&package);
	capital(&package);
	*result = t_string_join(**result, *(package.string));
	t_string_mom(*result);
	return (0);
}
