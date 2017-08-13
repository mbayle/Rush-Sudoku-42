/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 21:18:42 by gbetting          #+#    #+#             */
/*   Updated: 2017/08/13 22:06:50 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int checkcharcase(char array[9][9],int x,int y)
{
	int xmax = x+2;
	int ymax = y+2;
	int number[10] = {0};  

	while(y <= ymax)
	{
		if (array[y][x] >= '1' && array[y][x] <= '9')
		{
			if (number[array[y][x] - 48])
				return(0);
			else
				number[array[y][x] - 48]++;
		}
		x++;
		if(x > xmax)
		{
			x -= 3;
			y ++;
		}
	}
	return (1);
}

int checkcharline(char array[9][9],int y)
{
	int number[10] = {0};
	int x = 0;

	while(x < 9)
	{
		if (array[y][x] >= '1' && array[y][x] <= '9')
		{
			if (number[array[y][x] - 48])
				return(0);
			else
				number[array[y][x] - 48]++;
			}
			x++;
		}
	return (1);
}

int checkcharcolone(char array[9][9],int x)
{
	int number[10] = {0};
	int y = 0;
	
	while(y < 9)
	{
		if (array[y][x] >= '1' && array[y][x] <= '9')
		{
			if (number[array[y][x] - 48])
				return(0);
			else
				number[array[y][x] - 48]++;
			}
			y++;
		}
	return (1);
}

int errorchar(char array[9][9])
{
		int cursor_x = 0;
		int cursor_y = 0;
		while(cursor_y <= 8)
		{
		    if (!checkcharcase(array,cursor_x,cursor_y))
				return (0);
			cursor_x += 3;
			if (cursor_x >= 8)
			{
				cursor_x = 0;
				cursor_y += 3;
			}
		}
		cursor_x = 0;
		cursor_y = 0;
		while(cursor_x <= 8)
		    if (!checkcharcolone(array,cursor_x++))
				return(0);
		while(cursor_y <= 8)
			if(!checkcharline(array,cursor_y++))
				return(0);
		return (1);
}

int errorint(int array[9][9])
{
	char charray[9][9];
	int x;
	int y;
	while (y <= 8)
	{
		charray[y][x] = array[y][x];
		x++;
		if (x == 9)
		{
			x = 0;
			y++;
		}
	}
	if(errorchar(charray))
		return (0);
	return (1);
}
