/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:15:46 by hseffian          #+#    #+#             */
/*   Updated: 2019/07/22 15:38:04 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 600

typedef	struct		s_post
{
	int		i;
	int		j;
	int		size;
	int		k;
}					t_pos;

typedef	struct		s_parameters
{
	int		x;
	int		y;
	char	**matrice;
	char	*str;
	int		**mat;
	int		***arr;
	char	**matrix;
	int		l;
	char	buff[BUFF_SIZE];
	int		bytes;
	int		fd;
	char	*file;
}					t_m;

int					count_tetris_input(const char *file);
char				*get_one_tetris(char *pieces, int pos);
char				**get_tetris_cord(char *tetris, int *x, int *y);
void				move_tetris_up(char **matrix, int *x, int *y);
int					**get_index_tetris(char **matrice);
int					backtracking(char **matrix, int ***arr, int l, t_pos xy);
void				free_every(char *str, char **matrice);
void				free_matrix(char **tmp);
void				free_arr(int ***arr, int size);
void				free_tbl(char **t, int ret_isvalid);
int					check(char *buff, int bytes);

#endif
