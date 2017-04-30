/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbullain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:49:51 by rbullain          #+#    #+#             */
/*   Updated: 2017/04/29 17:10:15 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 4096

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_mathmin(int x, int y);
int				ft_mathmax(int i, int j);
void			ft_memdel(void **ap);

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

t_point			*create_point(int x, int y);

typedef struct	s_tetrim
{
	char	name;
	t_point	*root;
	t_point	**points;
}				t_tetrim;

t_tetrim		*create_tetrim(char name);
void			free_tetrim(t_tetrim *tetrim);

typedef struct	s_board
{
	int		size;
	int		square;
	char	**map;
}				t_board;

t_board			*create_board(int size);
void			free_board(t_board *board);
void			clone_board(t_board *dest, t_board *src);
int				calc_square(t_board *board);
void			print_board(t_board *board);

int				try_parse(char *buffer, int length, t_tetrim **tetrims);

void			fillit(t_board *solution, t_tetrim **tetrims);
void			ft_putnbr(int nbr);
#endif
