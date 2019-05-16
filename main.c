/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 04:47:44 by aazeroua          #+#    #+#             */
/*   Updated: 2019/05/16 21:58:20 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	int	fd2;
	int fd3;
	char *line;

	fd = open("file_ds", O_RDONLY);
	fd2 = open("test", O_RDONLY);
	fd3 = open("test3", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	free(line);
	// while ((get_next_line(fd, &line)) > 0)
	// {
	// 	printf("%s\n", line);
	// 	free(line);
	// }
	// close (fd);
	return (0);
}