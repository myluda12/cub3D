/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:18:05 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/04 11:18:06 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_sprite_exist(void)
{
	g_sprites[g_sprite_count].xcentre =
		((int)g_nexthorix / 50 * 50) + 25;
	g_sprites[g_sprite_count].ycentre =
		((int)g_nexthoriy / 50 * 50) + 25;
	g_sprites[g_sprite_count].g_x = g_nexthorix;
	g_sprites[g_sprite_count].g_y = g_nexthoriy;
	g_sprites[g_sprite_count].g_distance = sqrtf(powf(g_y_player -
		g_sprites[g_sprite_count].g_y, 2) +
		powf(g_x_player - g_sprites[g_sprite_count].g_x, 2));
	g_sprites[g_sprite_count].g_rotation = atan2(g_y_player
		- g_nexthoriy, g_x_player - g_nexthorix);
	g_sprite_count++;
}

void		ft_find_intersec(void)
{
	int		g_check;

	while (g_nexthorix >= 0 && g_nexthorix < g_mapcount[0].lenghtx * 50 &&
		g_nexthoriy >= 0 && g_nexthoriy < g_inde * 50)
	{
		g_sprite = 0;
		g_check = wall_checker();
		if (g_sprite == 1)
			ft_sprite_exist();
		if (g_check == 1)
		{
			g_wallhorihit = 1;
			g_horizwallhitx = g_nexthorix;
			g_horizwallhity = g_nexthoriy;
			break ;
		}
		else
		{
			g_nexthorix += g_xstep;
			g_nexthoriy += g_ystep;
		}
	}
}

void		ft_yx_intercept(void)
{
	ft_intial_variable();
	g_yintercept = (int)(g_y_player / g_wall) * g_wall;
	g_yintercept += g_rayfacingdown ? g_wall : 0;
	g_xintercept = g_x_player + (g_yintercept - g_y_player) / tan(g_rotation);
	g_ystep = g_wall;
	g_ystep *= g_rayfacingup ? -1 : 1;
	g_xstep = g_ystep / tan(g_rotation);
	g_nexthorix = g_xintercept;
	g_nexthoriy = g_yintercept;
	if (g_rayfacingup)
		g_nexthoriy--;
}

void		ft_sprite_exist1(void)
{
	g_sprites[g_sprite_count].xcentre =
		((int)g_nexthorix / 50 * 50) + 25;
	g_sprites[g_sprite_count].ycentre =
		((int)g_nexthoriy / 50 * 50) + 25;
	g_sprites[g_sprite_count].g_rotation =
		atan2(g_y_player - g_nexthoriy, g_x_player - g_nexthorix);
	g_sprites[g_sprite_count].g_x = g_nexthorix;
	g_sprites[g_sprite_count].g_y = g_nexthoriy;
	g_sprites[g_sprite_count].g_distance = sqrtf(powf(g_y_player -
		g_sprites[g_sprite_count].g_y, 2) + powf(g_x_player -
		g_sprites[g_sprite_count].g_x, 2));
	g_sprite_count++;
}

int			ft_cast_ray(void)
{
	int		g_check;

	ft_yx_intercept();
	ft_find_intersec();
	ft_yx_intercept1();
	ft_find_intercept1();
	g_horzhitdistance = (g_wallhorihit) ? distance_between_horver(g_x_player,
		g_y_player, g_horizwallhitx, g_horizwallhity) : MAX_INT;
	g_verthitdistance = (g_wallverthit) ? distance_between_horver(g_x_player,
		g_y_player, g_vertwallhitx, g_vrtwallhity) : MAX_INT;
	g_wallhitx = (g_horzhitdistance) <
		(g_verthitdistance) ? g_horizwallhitx : g_vertwallhitx;
	g_wallhity = (g_horzhitdistance) <
		(g_verthitdistance) ? g_horizwallhity : g_vrtwallhity;
	g_distance = (g_horzhitdistance) <
		(g_verthitdistance) ? g_horzhitdistance : g_verthitdistance;
	g_mhah = g_distance == g_horzhitdistance ? 1 : 0;
	g_washitvertical = (g_verthitdistance) < (g_horzhitdistance);
	g_darkcolor = 0x006400;
	g_darkcolor = check_opacity(g_darkcolor);
	return (0);
}
