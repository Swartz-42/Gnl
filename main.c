/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducas <aducas@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 15:49:30 by aducas       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 15:58:32 by aducas      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int ret, fd, fd2;
	char *line;
	int ligne;

	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);

	ligne = 0;
	(void)ac;
	while (1)
	{
		if (ligne % 2 == 0)
		{
			ret = get_next_line(fd, &line);
			printf("[%d] [%d] '%s'\n", fd, ret, line);
		}
		else
		{
			ret = get_next_line(fd2, &line);
			printf("[%d] [%d] '%s'\n", fd2, ret, line);
		}
		free(line);
		if (ret <= 0)
			break ;
		ligne++;
	}
	close(fd);
}
