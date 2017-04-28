/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbullain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:53:47 by rbullain          #+#    #+#             */
/*   Updated: 2017/04/27 19:09:20 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** description:
*/

static int	are_adjacent(t_point *p1, t_point *p2)
{
	int links;

	links = 0;
	if (p1->x == p2->x && (p1->y - p2->y) == 1)
		links++;
	if (p1->x == p2->x && (p1->y - p2->y) == -1)
		links++;
	if (p1->y == p2->y && (p1->x - p2->x) == 1)
	   links++;
	if (p1->y == p2->y && (p1->x - p2->x) == -1)
	   links++;
	return (links);
}

/*
** description:
*/

static int	is_valid_tetrim(t_tetrim *t)
{
	int i;
	int j;
	int min[2];
	int	links;

	i = -1;
	links = 0;
	min[0] = 5;
	min[1] = 5;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (j != i && are_adjacent(t->points[i], t->points[j]))
				links += are_adjacent(t->points[i], t->points[j]);
		min[0] = ft_mathmin(min[0], t->points[i]->x);
		min[1] = ft_mathmin(min[1], t->points[i]->y);
	}
	if (links < 6)
		return (0);
	t->root->x = min[0];
	t->root->y = min[1];
	return (1);
}

/*
** description:
*/

static int	try_parse_points(char *buffer, int start, t_tetrim *tetrim)
{
	int i;
	int count_points;

	i = 0;
	count_points = 0;
	while (i < 20)
	{
		while (buffer[start + i] && i % 5 < 4)
		{
			if (count_points < 4 && buffer[start + i] == '#')
			{
				tetrim->points[count_points]->x = i % 5;
				tetrim->points[count_points]->y = i / 5;
				count_points++;
			}
			else if (buffer[start + i] != '.')
				return (0);
			i++;
		}
		if (buffer[start + i] != '\n' || i % 5 != 4)
			return (0);
		i++;
	}
	return (count_points == 4);
}

/*
** description:
*/

int			try_parse(char *buffer, int length, t_tetrim **tetrims)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	while (i < length)
	{
		if (i != 0)
		{
			if (buffer[i] != '\n')
				return (0);
			i++;
		}
		if (try_parse_points(buffer, i, tetrims[pos]) == 0)
			return (0);
		if (is_valid_tetrim(tetrims[pos]) == 0)
			return (0);
		pos++;
		i += 20;
	}
	return (1);
}
