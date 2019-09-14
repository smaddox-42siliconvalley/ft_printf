/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:25:30 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/18 19:27:42 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *duplicate;

	duplicate = (char*)malloc(((ft_strlen(s) + 1) * sizeof(char)));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	ft_strcpy(duplicate, s);
	return (duplicate);
}
