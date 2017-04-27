/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbullain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:40:11 by rbullain          #+#    #+#             */
/*   Updated: 2017/04/27 19:12:10 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** description:
*/

static void		free_tetrims(t_tetrim **tetrims, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free_tetrim(tetrims[i]);
		i++;
	}
	ft_memdel((void**)&tetrims);
}

/*
** description:
*/

static t_tetrim	**create_tetrims(int size)
{
	t_tetrim	**new;
	int			i;

	if (!(new = (t_tetrim**)malloc(size * sizeof(t_tetrim))) || size > 26)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = create_tetrim('A' + i);
		i++;
	}
	return (new);
}

/*
** description:
*/

static int		read_file(char *src, char *buffer)
{
	int fd;
	int length;

	length = -1;
	if ((fd = open(src, O_RDONLY)) != -1)
	{
		if ((length = read(fd, buffer, BUFFER_SIZE)) != -1)
			buffer[length] = '\0';
	}
	close(fd);
	return (length);
}

/*
** description:
*/

static int		msg_error(int type, char *buffer, t_tetrim **tetrims, int len)
{
	if (type == 0)
		ft_putstr("usage: fillit target_file\n");
	else
	{
		if (type == 1)
			ft_memdel((void**)&buffer);
		if (type == 2)
		{
			ft_memdel((void**)&buffer);
			free_tetrims(tetrims, (len + 1) / 21);
		}
		ft_putstr("error\n");
	}
	return (1);
}

int				main(int ac, char **as)
{
	char		*buffer;
	int			length;
	t_tetrim	**tetrims;
	t_board		*solution;

	if (ac != 2)
		return (msg_error(0, NULL, NULL, 0));
	buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
	if ((length = read_file(as[1], buffer)) == -1)
		return (msg_error(1, buffer, NULL, 0));
	tetrims = create_tetrims((length + 1) / 21);
	if (try_parse(buffer, length, tetrims) == 0)
		return (msg_error(2, buffer, tetrims, length));
	solution = create_board((((length + 1) / 21) + 1) * 2);
	fillit(solution, tetrims);
	print_board(solution);
	free_board(solution);
	free_tetrims(tetrims, (length + 1) / 21);
	ft_memdel((void**)&buffer);
	return (0);
}
