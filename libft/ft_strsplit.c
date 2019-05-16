/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:33:30 by aazeroua          #+#    #+#             */
/*   Updated: 2019/04/20 23:55:08 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
	}
	return (j + 1);
}

static int		count_char(char const *s, char c, int *i)
{
	int j;

	j = 0;
	while (s[j] != c && s[j])
	{
		j++;
		(*i)++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (word_count(s, c)))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			s = s + i;
			j = count_char(s, c, &i);
			if (!(tab[k] = (char *)malloc(j + 1)))
				return (NULL);
			tab[k++] = ft_strsub(s, 0, j);
			i = j;
		}
	}
	tab[k] = 0;
	return (tab);
}
