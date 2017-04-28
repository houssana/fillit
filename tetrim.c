/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbullain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:02:03 by rbullain          #+#    #+#             */
/*   Updated: 2017/04/28 17:11:49 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** description:
*/

void		free_tetrim(t_tetrim *tetrim)
{
	int		i;

	ft_memdel((void**)&(tetrim->root));
	i = 0;
	while (i < 4)
	{
		ft_memdel((void**)&(tetrim->points[i]));
		i++;
	}
	ft_memdel((void**)&(tetrim->points));
	ft_memdel((void**)&tetrim);
}

/*
** description:
*/

t_tetrim	*create_tetrim(char name)
{
	t_tetrim	*new;
	int			i;

	new = (t_tetrim*)malloc(sizeof(t_tetrim));
	new->name = name;
	new->root = create_point(0, 0);
	new->points = (t_point**)malloc(4 * sizeof(t_point*));
	i = 0;
	while (i < 4)
	{
		new->points[i] = create_point(0, 0);
		i++;
	}
	return (new);
}
