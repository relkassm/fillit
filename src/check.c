/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:15:34 by relkassm          #+#    #+#             */
/*   Updated: 2019/07/22 15:15:23 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			check_lines(char *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (j == 21)
			j = 0;
		if ((j - 4) % 5 == 0 || j == 20)
		{
			if (buff[i] != '\n')
				return (0);
		}
		else if (buff[i] != '#' && buff[i] != '.')
			return (0);
		i++;
		j++;
	}
	return (1);
}

static int			surrounding(char *buff, int *count, int i, int j)
{
	int c;

	c = 0;
	if (buff[i] == '#')
	{
		if (buff[i + 1] == '#')
			c++;
		if (buff[i - 1] == '#')
			c++;
		if (buff[i - 5] == '#' && j - 5 >= 0)
			c++;
		if (buff[i + 5] == '#' && j + 5 < 21)
			c++;
		if (c == 0)
			return (0);
		if (c > *count)
			*count = c;
	}
	return (1);
}

static int			check_valid_tetri(char *buff, int bytes)
{
	int i;
	int count;
	int j;

	i = 0;
	while (buff[i])
	{
		j = 0;
		count = 0;
		while (j < 21)
		{
			if (!surrounding(buff, &count, i, j))
				return (0);
			j++;
			i++;
			if (i == bytes)
				break ;
		}
		if (count < 2)
			return (0);
	}
	return (1);
}

static int			check_nb_tetri(char *buff, int bytes)
{
	int i;
	int nbr;
	int	j;

	j = 0;
	nbr = 0;
	i = 0;
	while (buff[i])
	{
		if (j == 21)
		{
			j = 0;
			nbr = 0;
		}
		if (buff[i] == '#')
			nbr++;
		if (j == 18 && nbr != 4)
			return (0);
		j++;
		i++;
	}
	return (check_valid_tetri(buff, bytes));
}

int					check(char *buff, int bytes)
{
	if (buff[bytes - 1] != '\n'
			|| (buff[bytes - 1] == '\n' && buff[bytes - 2] == '\n')
			|| bytes > 545 || (bytes + 1) % 21 != 0)
		return (0);
	return (check_lines(buff) && check_nb_tetri(buff, bytes));
}
