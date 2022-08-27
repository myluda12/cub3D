/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:50:46 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/22 16:32:17 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			cw(char *str, char c)
{
	int				g_indicator;
	int				nb;

	g_indicator = 0;
	nb = 0;
	while (str[g_indicator])
	{
		if (((g_indicator == 0) || str[g_indicator - 1]
			== c) && str[g_indicator] != c)
			nb++;
		g_indicator++;
	}
	return (nb);
}

static void			ft_freedom(char **g_pointer, int g_dp)
{
	while (g_dp)
	{
		free(g_pointer[g_dp]);
		g_dp--;
	}
	free(g_pointer);
}

static char			*get_word(char *str, int g_indicator, char c)
{
	int				len;
	int				g_dp;
	char			*word;

	g_dp = g_indicator;
	len = 0;
	while ((str[g_dp] != c) && str[g_dp])
	{
		len++;
		g_dp++;
	}
	if (!(word = (char *)malloc(sizeof(char) * (len + 1))))
	{
		return (NULL);
	}
	g_dp = 0;
	while ((str[g_indicator] != c) && str[g_indicator])
	{
		word[g_dp] = str[g_indicator];
		g_indicator++;
		g_dp++;
	}
	word[g_dp] = '\0';
	return (word);
}

char				**ft_split(char const *str, char c)
{
	g_counter = 0;
	g_indicator = 0;
	g_dp = 0;
	if (!str)
		return (NULL);
	if (!(g_pointer = (char **)malloc(sizeof(char *) *
		(cw((char *)str + g_indicator, c) + 1))))
		return (NULL);
	while (str[g_indicator])
	{
		if (((g_indicator == 0) || str[g_indicator - 1]
			== c) && str[g_indicator] != c)
		{
			if (!(g_pointer[g_dp] = (get_word((char *)str, g_indicator, c))))
			{
				ft_freedom(g_pointer, g_dp - 1);
				return (NULL);
			}
			g_dp++;
			g_counter++;
		}
		g_indicator++;
	}
	g_pointer[g_dp] = 0;
	return (g_pointer);
}
