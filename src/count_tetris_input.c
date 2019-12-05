/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetris_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:59:03 by hseffian          #+#    #+#             */
/*   Updated: 2019/07/22 15:02:53 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_tetris_input(const char *file)
{
	int	cmp;
	int	i;
	int	len;

	len = ft_strlen(file);
	if (len < 20 || (file[0] != '.' && file[0] != '#'))
		return (0);
	i = 0;
	if (file[len - 1] != '\n' || (file[len - 2] != '.' && file[len - 2] != '#'))
		return (0);
	cmp = 0;
	while (file[i])
	{
		if (i == len - 2)
			break ;
		if (file[i] == '\n' && file[i + 1] == '\n'
				&& (file[i + 2] == '.' || file[i + 2] == '#'))
			cmp++;
		if (file[i] == '\n' && file[i + 1] == '\n'
				&& (file[i + 2] != '.' && file[i + 2] != '#'))
			return (0);
		i++;
	}
	return (++cmp);
}
