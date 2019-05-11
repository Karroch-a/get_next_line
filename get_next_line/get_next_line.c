/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:36:19 by aazeroua          #+#    #+#             */
/*   Updated: 2019/05/10 17:56:47 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		count_word(char **str, int fd)
{
	int i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	return (i);
}
int		get_next_line(const int fd, char **line)
{
	static char	*tab;
	int 		i;
	char		buff[BUFF_SIZE + 1];
	while (read (fd, buff, BUFF_SIZE))
	{	
		if (ft_strchr(buff, '\n'))
		{
			i = 0;
			while(buff[i] != '\n')
				i++;
			*line = ft_strsub(buff, 0, i);
		}
	}
	return (1);
}
int main()
{
	int i;
	int fd = open("file_ds", O_RDONLY);
	char *line;
	get_next_line(fd, &line);
	printf("%s\n", line);
	/*get_next_line(fd, &line);
	printf("%s\n", line);*/
	return (0);
}
