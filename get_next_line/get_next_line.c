/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:36:19 by aazeroua          #+#    #+#             */
/*   Updated: 2019/05/16 20:23:52 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line)
{
	int 		i;
	int			rd;
	char		buff[BUFF_SIZE + 1];
	static char	*tab;
	char *tm;

	if (fd < 0 || !line || !fd)
		return (-1);
	if (!tab)
		tab = ft_strnew(0);
	i = 0;
	while ((!ft_strchr(tab, '\n')) && (rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		tm = ft_strjoin(tab, buff);
		free(tab);
		tab = tm;
		free(tm);
	}
	if (rd == 0 && *tab == '\0')
		return (0);
	while (tab[i] != '\n' && tab[i] != '\0')
		    i++;
	*line = ft_strsub(tab, 0, i);
	//tm = tab;
	if (tab[i] == '\n')
		tab = ft_strdup(&tab[i + 1]);
	else
		tab = ft_strdup("\0");
	//free(tm);
	return (1);
}
