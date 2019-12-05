/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 01:56:40 by hseffian          #+#    #+#             */
/*   Updated: 2019/07/22 03:28:11 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tbl(char **t, int ret_isvalid)
{
	int i;

	i = -1;
	while (++i < ret_isvalid)
		ft_strdel(&t[i]);
	free(t);
}

void	free_matrix(char **tmp)
{
	int i;

	i = -1;
	while (tmp[++i])
		ft_strdel(&tmp[i]);
	free(tmp);
}

void	ft_free_mat(int **tmp)
{
	int i;

	i = -1;
	while (++i < 4)
		free(tmp[i]);
	free(tmp);
}

void	free_every(char *str, char **matrice)
{
	free(str);
	free_matrix(matrice);
}

void	free_arr(int ***arr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_free_mat(arr[i]);
	free(arr);
}
