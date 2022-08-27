/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:04:53 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/22 17:54:40 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t				f;
	char				*dest;
	int					i;
	f = 0;
	if (!(s))
	{
		return (NULL);
	}
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = (ft_strlen(s) - start);
	while ((f < len) && (i > 0))
	{
		dest[f] = s[start];
		start++;
		f++;
	}
	dest[f] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void		bubblesort1(int g_sprite_count)
{
	int		i;
	int		g_j;
	int		temp;

	g_j = 0;
	i = 0;
	while (i < (g_sprite_count - 1))
	{
		while (g_j < g_sprite_count - 1 - i)
		{
			if (g_sprites[g_j].g_distance > g_sprites[g_j + 1].g_distance)
			{
				temp = g_sprites[g_j + 1].g_distance;
				g_sprites[g_j + 1].g_distance = g_sprites[g_j].g_distance;
				g_sprites[g_j].g_distance = temp;
			}
			g_j++;
		}
		i++;
	}
}

void		bubblesort(int inde)
{
    int		i;
	int		j;
	int		temp;

    for (i = 0; i < (inde - 1); ++i)
    {
        for (j = 0; j < inde - 1 - i; ++j)
        {
            if (g_mapcount[j].lenghtx < g_mapcount[j+1].lenghtx)
            {
                temp = g_mapcount[j+1].lenghtx;
                g_mapcount[j+1].lenghtx = g_mapcount[j].lenghtx;
                g_mapcount[j].lenghtx = temp;
            }
        }
    }
}