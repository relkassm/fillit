/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:20:15 by hseffian          #+#    #+#             */
/*   Updated: 2019/07/22 14:57:29 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**new_matrix(int size)
{
	char	**matrix;
	int		i;
	int		j;

	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < size)
		matrix[i] = ft_strnew(size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			matrix[i][j] = '.';
	}
	matrix[i] = 0;
	return (matrix);
}

static	int		ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 1;
	if (nb < 0)
		return (0);
	while (sqrt * sqrt < nb)
		++sqrt;
	return (sqrt);
}

void			suit(t_m *a, t_pos *index)
{
	index->k = count_tetris_input(a->buff);
	index->size = ft_sqrt(index->k * 4);
	a->matrix = new_matrix(index->size);
}

void			every(t_m a)
{
	t_pos index;

	a.l = -1;
	suit(&a, &index);
	a.arr = (int***)malloc(index.k * sizeof(int**));
	while (++a.l < index.k)
	{
		a.str = get_one_tetris(a.buff, a.l);
		a.matrice = get_tetris_cord(a.str, &a.x, &a.y);
		move_tetris_up(a.matrice, &a.x, &a.y);
		a.mat = get_index_tetris(a.matrice);
		a.arr[a.l] = a.mat;
		free_every(a.str, a.matrice);
	}
	while ((backtracking(a.matrix, a.arr, 0, index)) == 0)
	{
		free_matrix(a.matrix);
		a.matrix = new_matrix(++index.size);
	}
	index.i = -1;
	while (++(index.i) < index.size)
		ft_putendl(a.matrix[index.i]);
	free_matrix(a.matrix);
	free_arr(a.arr, index.k);
}

int				main(int ac, char **av)
{
	t_m	a;

	if (ac == 2)
	{
		a.fd = open(av[1], O_RDONLY);
		a.bytes = read(a.fd, a.buff, BUFF_SIZE);
		if (a.bytes == -1)
		{
			ft_putendl("error");
			return (0);
		}
		a.buff[a.bytes] = '\0';
		a.file = (av[1]);
		if (check(a.buff, a.bytes) == 1)
			every(a);
		else
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
		ft_putstr("usage :  ./fillit fileName.\n");
	return (0);
}
