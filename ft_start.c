/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:16:05 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/03 19:16:07 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ray_direction(void)
{
	g_rayfacingdown = 0;
	g_rayfacingup = 0;
	g_rayfacingright = 0;
	g_rayfacingleft = 0;
	g_rayfacingdown = (deg(g_rotation) > 0 && deg(g_rotation) < 180) ? 1 : 0;
	g_rayfacingup = !(g_rayfacingdown) ? 1 : 0;
	g_rayfacingright = ((deg(g_rotation) > 0 && (deg(g_rotation) < 90))
	|| (deg(g_rotation) > 270 && (deg(g_rotation) < 360))) ? 1 : 0;
	g_rayfacingleft = !(g_rayfacingright) ? 1 : 0;
	return (0);
}

double		distance_between_horver(int x1, int y1, int x2, int y2)
{
	return (sqrtf(powf((x2 - x1), 2) + powf((y2 - y1), 2)));
}

void		ft_intial_variable(void)
{
	g_wallhitx = 0;
	g_wallhity = 0;
	g_distance = 0;
	g_sprite = 0;
	g_sprite_indicator = 0;
	g_wallhorihit = 0;
	ray_direction();
}

int			loop_key(void)
{
	if (ft_strcmp(g_chorfi, "--save") != 0)
	{
		mlx_hook(g_win_ptr, 2, 0, mlx_key_press, 0);
		mlx_hook(g_win_ptr, 3, 0, key_release, 0);
		mlx_hook(g_win_ptr, 17, 0L, ft_exit, 0);
	}
	deal_key();
	if (g_swiitch == 1)
		mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_image, 0, 0);
	return (0);
}

int			ft_last_line(void)
{
	int		i;

	i = 0;
	while (ft_strchr("1 ", g_line[g_inde][i]))
	{
		i++;
		if (g_line[g_inde][i] == ' ' && g_line[g_inde - 1][i] == '0')
			break ;
		if (g_line[g_inde][i] == '\0')
			return (1);
	}
	ft_putstr("errormap\n");
	exit(0);
	return (0);
}
