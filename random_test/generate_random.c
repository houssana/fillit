/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_random.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 13:56:12 by houssana          #+#    #+#             */
/*   Updated: 2017/04/30 13:01:46 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

char	*concat(char *s1, char *s2)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc(sizeof(char) * 50);
	while (*s1)
		s[i++] = *(s1++);
	while (*s2)
		s[i++] = *(s2++);
	s[i] = '\0';
	return (s);
}

void	append(int fd, char *t, int i)
{
	int		td;
	int		len;
	char	*buffer;
	char	*path;

	path = concat("tetriminios/", t);
	buffer = malloc(sizeof(char) * 21);
	if (i)
		write(fd, "\n", 1);
	td = open(path, O_RDONLY);
	len = read(td, buffer, 20);
	buffer[len] = '\0';
	write(fd, buffer, 20);
}

int main(int argc, char **argv)
{
	char	**t;
	int		i;
	int		nb;
	int		fd;

	i = 0;
	srand(time(NULL));
	t = malloc(15 * sizeof(char *));
	t[0] = "c";
	t[1] = "i";
	t[2] = "i1";
	t[3] = "l";
	t[4] = "l1";
	t[5] = "l2";
	t[6] = "l3";
	t[7] = "_l";
	t[8] = "_l1";
	t[9] = "_l2";
	t[10] = "_l3";
	t[11] = "z";
	t[12] = "z1";
	t[13] = "_z";
	t[14] = "_z1";
	nb = atoi(argv[1]);
	fd = open("test", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU);
	while (nb--)
		append(fd, t[rand() % 15], i++);
		//printf("%s\n", t[rand() % 15]);
	close(fd);
}
