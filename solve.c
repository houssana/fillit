/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbullain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:58:30 by rbullain          #+#    #+#             */
/*   Updated: 2017/04/27 11:59:56 by rbullain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** description:
*/

static void	quit_tetrim(t_board *cur, int i, int j, t_tetrim *tetrim)
{
	int k;
	int new_i;
	int new_j;

	k = 0;
	while (k < 4)
	{
		new_i = i + (tetrim->points[k]->x - tetrim->root->x);
		new_j = j + (tetrim->points[k]->y - tetrim->root->y);
		if (new_i < cur->square && new_j < cur->square &&
				cur->map[new_i][new_j] == tetrim->name)
			cur->map[new_i][new_j] = '.';
		k++;
	}
}

/*
** description:
*/

static int	is_valid(t_board *cur, int i, int j, t_tetrim *tetrim)
{
	int k;
	int new_i;
	int new_j;

	k = 0;
	while (k < 4)
	{
		new_i = i + (tetrim->points[k]->x - tetrim->root->x);
		new_j = j + (tetrim->points[k]->y - tetrim->root->y);
		if (new_i >= cur->square || new_j >= cur->square ||
				cur->map[new_i][new_j] != '.')
		{
			quit_tetrim(cur, i, j, tetrim);
			return (0);
		}
		cur->map[new_i][new_j] = tetrim->name;
		k++;
	}
	return (1);
}

/*
** description:
*/

static void	fillit_rcs(t_board *cur, t_board *sol, t_tetrim **tetrims, int pos)
{
	int i;
	int j;

	if (pos == (cur->size / 2) - 1)
	{
		if ((cur->square = calc_square(cur)) < sol->square)
			clone_board(sol, cur);
		return ;
	}
	i = 0;
	while (i < cur->square)
	{
		j = 0;
		while (j < cur->square)
		{
			if (is_valid(cur, i, j, tetrims[pos]) == 1)
			{
				fillit_rcs(cur, sol, tetrims, pos + 1);
				quit_tetrim(cur, i, j, tetrims[pos]);
			}
			j++;
		}
		i++;
	}
}

/*
** description:
*/

void		fillit(t_board *solution, t_tetrim **tetrims)
{
	t_board *current;

	current = create_board(solution->size);
	fillit_rcs(current, solution, tetrims, 0);
	free_board(current);
}
