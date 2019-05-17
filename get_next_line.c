/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:36:19 by aazeroua          #+#    #+#             */
/*   Updated: 2019/05/17 00:55:20 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		get_next_line(const int fd, char **line)
{
	int 		i;
	int			rd;
	char		buff[BUFF_SIZE + 1];
	static char	*tab[4864];
	char *tm;

	if (fd < 1 || !line || fd > 4864 || BUFF_SIZE < 1)
		return (-1);
	if (!tab[fd])
		tab[fd] = ft_strnew(0);
	i = 0;
	while ((!ft_strchr(tab[fd], '\n')) && (rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		tm = ft_strjoin(tab[fd], buff);
		free(tab[fd]);
		tab[fd] = ft_strdup(tm);
		free(tm);
	}
	if (rd < 1 && !*tab[fd])
		return (rd);
	while (tab[fd][i] != '\n' && tab[fd][i] != '\0')
		    i++;
	*line = ft_strsub(tab[fd], 0, i);
	if (tab[fd][i] == '\n')
	{
		tm = ft_strdup(&tab[fd][i + 1]);
		free(tab[fd]);
		tab[fd] = ft_strdup(tm);
		free(tm);
	}
	else
	{
		tm = ft_strdup("\0");
		free(tab[fd]);
		tab[fd] = ft_strdup(tm);
		free(tm);
	}
	return (1);
}