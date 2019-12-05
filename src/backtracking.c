/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 01:07:22 by hseffian          #+#    #+#             */
/*   Updated: 2019/07/22 03:29:48 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_can_fill(char **matrice, int **tetris, t_pos index)
{
	int l;
	int size;

	size = ft_strlen(*matrice);
	l = -1;
	while (++l < 4)
	{
		if (tetris[l][0] + index.i >= size | tetris[l][1] + index.j >= size
			|| matrice[tetris[l][0] + index.i][tetris[l][1] + index.j] != '.')
			return (0);
	}
	return (1);
}

void	fill_it(char **matrice, int **tetris, t_pos index, int l)
{
	int k;

	k = -1;
	while (++k < 4)
		matrice[tetris[k][0] + index.i][tetris[k][1] + index.j] = l + 65;
}

void	delete_tetris(char **matrice, int i, int s)
{
	int l;
	int d;

	d = -1;
	while (++d < s)
	{
		l = -1;
		while (++l < s)
		{
			if (matrice[d][l] == 'A' + i)
				matrice[d][l] = '.';
		}
	}
}

int		backtracking(char **matrix, int ***arr, int l, t_pos xy)
{
	t_pos		index;
	int			res;

	if (l == xy.k)
		return (1);
	index.i = -1;
	res = 0;
	while (++(index.i) < xy.size)
	{
		index.j = -1;
		while (++(index.j) < xy.size)
			if (check_can_fill(matrix, arr[l], index) == 1)
			{
				fill_it(matrix, arr[l], index, l);
				res = 1;
				if (!backtracking(matrix, arr, l + 1, xy))
				{
					delete_tetris(matrix, l, xy.size);
					res = 0;
				}
				else
					return (1);
			}
	}
	return (res);
}
