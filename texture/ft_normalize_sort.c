/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_mouvement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:45:51 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/04 11:45:52 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		ft_normalize_angle(double angle)
{
	while (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	while (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void		sorting(void)
{
	int		indd;
	int		g_j;

	indd = 1;
	g_j = 0;
	while (indd < g_sprite_count)
	{
		while (g_j < g_sprite_count - indd)
		{
			if (g_sprites[g_j].g_distance > g_sprites[g_j + 1].g_distance)
			{
				g_sprites_temp = g_sprites[g_j];
				g_sprites[g_j] = g_sprites[g_j + 1];
				g_sprites[g_j + 1] = g_sprites_temp;
			}
			g_j++;
		}
		g_j = 0;
		indd++;
	}
	g_sprites[g_sprite_count].g_distance = '\0';
}

void		ft_directions(int g_j, int i)
{
	if (g_line[g_j][i] == 'N')
		g_rotationangle = 3 * (M_PI) / 2;
	else if (g_line[g_j][i] == 'S')
		g_rotationangle = M_PI / 2;
	else if (g_line[g_j][i] == 'W')
		g_rotationangle = 0;
	else if (g_line[g_j][i] == 'E')
		g_rotationangle = M_PI;
}

void		ft_check_c1(void)
{
	if (g_counter != 3 || ft_atoi(g_check[0]) > 255 || ft_atoi(g_check[0]) < 0
		|| ft_atoi(g_check[1]) > 255 || ft_atoi(g_check[1]) < 0
		|| ft_atoi(g_check[2]) > 255 || ft_atoi(g_check[2]) < 0)
	{
		ft_putstr("INVALID g_map\n");
		exit(0);
	}
}

void		ft_check_f1(void)
{
	if (g_counter != 3 || ft_atoi(g_check[0]) > 255 || ft_atoi(g_check[0]) < 0
	|| ft_atoi(g_check[1]) > 255 || ft_atoi(g_check[1]) < 0
	|| ft_atoi(g_check[2]) > 255 || ft_atoi(g_check[2]) < 0)
	{
		ft_putstr("INVALID g_map\n");
		exit(0);
	}
}
