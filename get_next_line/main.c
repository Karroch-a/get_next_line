/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 04:47:44 by aazeroua          #+#    #+#             */
/*   Updated: 2019/05/14 23:50:33 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	char *line;

	fd = open("file_ds", O_RDONLY);
	// get_next_line(fd, &line);
	// printf("%s\n", line);
	// free(line);
	// get_next_line(fd, &line);
	// printf("%s\n", line);
	// free(line);
	// get_next_line(fd, &line);
	// printf("%s\n", line);
	// free(line);
	while ((get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	return (0);
}
