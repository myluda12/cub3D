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

void		ft_mouvement_up(void)
{
	int		p;

	g_x_remainder = g_x_player;
	g_y_remainder = g_y_player;
	g_x_remainder += cos(g_rotationangle) * 10;
	g_y_remainder += sin(g_rotationangle) * 10;
	p = wall_collision();
	if (p != 1)
	{
		g_x_player += cos(g_rotationangle) * 10;
		g_y_player += sin(g_rotationangle) * 10;
	}
}

void		ft_mouvement_down(void)
{
	int		p;

	g_x_remainder = g_x_player;
	g_y_remainder = g_y_player;
	g_x_remainder -= cos(g_rotationangle) * 10;
	g_y_remainder -= sin(g_rotationangle) * 10;
	p = wall_collision();
	if (p != 1)
	{
		g_x_player -= cos(g_rotationangle) * 10;
		g_y_player -= sin(g_rotationangle) * 10;
	}
}

void		ft_mouvement_left(void)
{
	int		p;

	g_x_remainder = g_x_player;
	g_y_remainder = g_y_player;
	g_x_remainder -= cos(g_rotationangle + M_PI / 2) * 10;
	g_y_remainder -= sin(g_rotationangle + M_PI / 2) * 10;
	p = wall_collision();
	if (p != 1)
	{
		g_x_player -= cos(g_rotationangle + M_PI / 2) * 10;
		g_y_player -= sin(g_rotationangle + M_PI / 2) * 10;
	}
}

void		ft_mouvement_right(void)
{
	int		p;

	g_x_remainder = g_x_player;
	g_y_remainder = g_y_player;
	g_x_remainder -= cos(g_rotationangle - M_PI / 2) * 10;
	g_y_remainder -= sin(g_rotationangle - M_PI / 2) * 10;
	p = wall_collision();
	if (p != 1)
	{
		g_x_player -= cos(g_rotationangle - M_PI / 2) * 10;
		g_y_player -= sin(g_rotationangle - M_PI / 2) * 10;
	}
}

void		ft_all_mouvement(void)
{
	if (strcmp(g_chorfi, "--save") == 0)
		screenshot();
	if (g_down == 1)
		ft_mouvement_down();
	else if (g_up == 1)
		ft_mouvement_up();
	if (g_d == 1)
		ft_mouvement_right();
	if (g_a == 1)
		ft_mouvement_left();
	if (g_left == 1)
		g_rotationangle -= rad(3);
	if (g_right == 1)
		g_rotationangle += rad(3);
}
