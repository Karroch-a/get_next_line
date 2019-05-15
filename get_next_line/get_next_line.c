/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:36:19 by aazeroua          #+#    #+#             */
/*   Updated: 2019/05/14 23:51:43 by aazeroua         ###   ########.fr       */
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

	if (fd < 0 || !line || !fd)
		return (-1);
	if (!tab)
		tab = ft_strnew(0);
	i = 0;
	if (!ft_strchr(tab, '\n'))
	{
		while ((rd = read(fd, buff, BUFF_SIZE)))
		{
			buff[rd] = '\0';
			tab = ft_strjoin(tab, buff);
			if (ft_strchr(buff, '\n'))
				break ;
		}
	}
	while (tab[i] != '\n')
		i++;
	*line = ft_strsub(tab, 0, i);
	tab = ft_strdup(&tab[i + 1]);
	return (1);
}
