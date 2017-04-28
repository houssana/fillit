/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbullain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:42:32 by rbullain          #+#    #+#             */
/*   Updated: 2017/04/28 16:54:58 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** description:
*/

void		print_board(t_board *board)
{
	int i;
	int j;

	i = 0;
	while (i < board->square)
	{
		j = 0;
		while (j < board->square)
		{
			ft_putchar(board->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/*
** description:
*/

int			calc_square(t_board *board)
{
	int i;
	int j;
	int square;

	i = 0;
	square = 0;
	while (i < board->size)
	{
		j = 0;
		while (j < board->size)
		{
			if (board->map[i][j] != '.' && (i > square || j > square))
				square = ft_mathmax(i, j);
			j++;
		}
		i++;
	}
	return (square + 1);
}

/*
** description:
*/

void		clone_board(t_board *dest, t_board *src)
{
	int i;
	int j;

	i = 0;
	while (i < dest->size)
	{
		j = 0;
		while (j < dest->size)
		{
			dest->map[i][j] = src->map[i][j];
			j++;
		}
		i++;
	}
	dest->square = src->square;
}

/*
** description:
*/

void		free_board(t_board *board)
{
	int i;

	i = 0;
	while (i < board->size)
	{
		ft_memdel((void**)&(board->map[i]));
		i++;
	}
	ft_memdel((void**)&(board->map));
	ft_memdel((void**)&board);
}

/*
** description:
*/

t_board		*create_board(int size)
{
	t_board	*new;
	int		i;
	int		j;

	new = (t_board*)malloc(sizeof(t_board));
	new->size = size;
	new->square = size;
	i = 0;
	new->map = (char**)malloc((size + 1) * sizeof(char*));
	while (i < size)
	{
		new->map[i] = (char*)malloc(size * sizeof(char));
		j = 0;
		while (j < size)
		{
			new->map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (new);
}
