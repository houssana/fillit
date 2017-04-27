/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbullain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:57:28 by rbullain          #+#    #+#             */
/*   Updated: 2017/04/27 19:05:56 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** description:
*/

t_point		*create_point(int x, int y)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	return (new);
}
