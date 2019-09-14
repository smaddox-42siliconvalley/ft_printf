/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashcan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:24:56 by smaddox           #+#    #+#             */
/*   Updated: 2019/09/08 19:54:57 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "trashcan.h"
#include <stdlib.h>

t_rash_can g_can = {.top = -1};

void	mom(void *pointer)
{
	if (!trash_overflow())
	{
		g_can.top++;
		g_can.can[g_can.top] = pointer;
	}
}

int		trash_overflow(void)
{
	if (g_can.top == DEFAULT_SIZE - 1)
        return(1);
	return (0);
}

int		trashcan_empty(void)
{
	if (g_can.top == -1)
		return (1);
	return (0);
}

void	check_duplicates(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_can.top)
	{
		j = i + 1;
		while(j < g_can.top)
		{
			if (g_can.can[i] == g_can.can[j])
				g_can.can[i] = NULL;
			++j;
		}
		++i;
	}
}

void	garbage_day(void)
{

	check_duplicates();
	while (!trashcan_empty())
	{
		if (g_can.can[g_can.top])
			free(g_can.can[g_can.top]);
		g_can.top--;
	}
}


