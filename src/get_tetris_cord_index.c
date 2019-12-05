/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetris_cord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:29:18 by hseffian          #+#    #+#             */
/*   Updated: 2019/07/22 03:31:42 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_one_tetris(char *pieces, int pos)
{
	int		i;
	int		cmp;
	char	*tetris;

	i = -1;
	cmp = 0;
	if (pos == 0)
	{
		tetris = ft_strsub(pieces, 0, 20);
		return (tetris);
	}
	while (pieces[++i])
		if (pieces[i] == '\n' && pieces[i + 1] == '\n')
		{
			cmp++;
			if (pos == cmp)
				break ;
		}
	return (ft_strsub(pieces, i + 2, 20));
}

char	**get_tetris_cord(char *tetris, int *x, int *y)
{
	int		i;
	int		j;
	char	**matrice;

	matrice = ft_strsplit(tetris, '\n');
	i = -1;
	*x = 4;
	*y = 3;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (matrice[i][j] == '#')
			{
				if (j < *x)
					*x = j;
				if (i < *y)
					*y = i;
			}
	}
	return (matrice);
}

void	move_tetris_up(char **matrix, int *x, int *y)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (matrix[i][j] == '#')
			{
				c = matrix[i - *y][j - *x];
				matrix[i - *y][j - *x] = matrix[i][j];
				matrix[i][j] = c;
			}
	}
}

int		**allocation_42(void)
{
	int i;
	int **cord;

	cord = (int **)malloc(sizeof(int *) * 4);
	i = -1;
	if (!cord)
		return (NULL);
	while (++i < 4)
	{
		cord[i] = (int *)malloc(sizeof(int) * 2);
		if (!cord[i])
			return (NULL);
	}
	return (cord);
}

int		**get_index_tetris(char **matrice)
{
	int **cord;
	int i;
	int j;
	int k;

	k = 0;
	i = -1;
	cord = allocation_42();
	if (!cord)
		return (NULL);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (matrice[i][j] == '#')
			{
				cord[k][0] = i;
				cord[k][1] = j;
				k++;
			}
	}
	return (cord);
}
