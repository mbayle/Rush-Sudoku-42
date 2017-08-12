/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 01:31:01 by gbetting          #+#    #+#             */
/*   Updated: 2017/08/12 20:22:41 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void 	init (char carray[9][9], int iarray[9][9])
{
	int y = 0;

	while(y != 9)
	{
		stringArrayToIntArray(carray[y],iarray[y]);
		y++;
	}
}

void  stringArrayToIntArray (char *charray, int *intray)
{
	int i;

	i = 0;
	while(i < 9)
	{
		if (charray[i] >= '1' && charray[i] <= '9')
			intray[i] = charray[i] - 48;
		i++;
	}
}
