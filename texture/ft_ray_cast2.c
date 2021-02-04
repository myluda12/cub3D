/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_nec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:15:15 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/04 12:15:18 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_find_intercept1(void)
{
	int		g_check;

	while (g_nexthorix >= 0 && g_nexthorix < g_mapcount[0].lenghtx *
		50 && g_nexthoriy >= 0 && g_nexthoriy < g_inde * 50)
	{
		g_sprite = 0;
		g_check = wall_checker();
		if (g_sprite == 1)
			ft_sprite_exist1();
		if (g_check == 1)
		{
			g_wallverthit = 1;
			g_vertwallhitx = g_nexthorix;
			g_vrtwallhity = g_nexthoriy;
			break ;
		}
		else
		{
			g_nexthorix += g_xstep;
			g_nexthoriy += g_ystep;
		}
	}
}

void		ft_yx_intercept1(void)
{
	g_wallverthit = 0;
	ray_direction();
	g_xintercept = (int)(g_x_player / g_wall) * g_wall;
	g_xintercept += g_rayfacingright ? g_wall : 0;
	g_yintercept = g_y_player - (g_x_player - g_xintercept) * tan(g_rotation);
	g_xstep = g_wall;
	g_xstep *= g_rayfacingleft ? -1 : 1;
	g_ystep = g_xstep * tan(g_rotation);
	g_nexthorix = g_xintercept;
	g_nexthoriy = g_yintercept;
	if (g_rayfacingleft)
		g_nexthorix--;
}

void		ft_check_errormap1(void)
{
	if (g_dontenteragain == 10 && g_mapcount[g_t - 1].mapx == 0)
	{
		ft_putstr("invalid mapox");
		exit(0);
	}
}

void		ft_free_l3alam(char **g_tab)
{
	int		g_j;

	g_j = 0;
	while (g_tab[g_j])
	{
		free(g_tab[g_j]);
		g_j++;
	}
	free(g_tab);
}

void		ft_return(void)
{
	if (g_direction.c != 1 || g_direction.we != 1 || g_direction.ea != 1
		|| g_direction.f != 1 || g_direction.su != 1 || g_direction.no != 1
		|| g_direction.r != 1 || g_direction.s != 1)
	{
		ft_putstr("missing or multiple parameter");
		exit(0);
	}
}
