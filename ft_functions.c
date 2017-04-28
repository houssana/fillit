/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbullain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:46:45 by rbullain          #+#    #+#             */
/*   Updated: 2017/04/28 17:10:34 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** description:
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** description:
*/

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*
** description:
*/

int		ft_mathmin(int x, int y)
{
	return ((x < y) ? x : y);
}

/*
** description:
*/

int		ft_mathmax(int x, int y)
{
	return ((x > y) ? x : y);
}

/*
** description:
*/

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
