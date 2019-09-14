/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:17:13 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:17:15 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dhelper(t_package *package)
{
	if (package->sign.str)
	{
		if (!((package->mws)) || package->mws->str[0] == 32)
		{
			package->string = t_string_join(package->sign, *(package->string));
			t_string_mom(package->string);
			//mom(package->string);
		}
		else if (package->mws)
		{
			package->mws = t_string_join(package->sign, *(package->mws));
			t_string_mom(package->mws);
			//mom(package->mws);
		}
	}
	if (package->mws)
	{
		package->string = (contains('-',
					package->flag.h_flag, NUM_H_FLAGS) != -1) ?
			t_string_join(*(package->string), *(package->mws)) :
			t_string_join(*(package->mws), *(package->string));
		t_string_mom(package->string);
	}
}
