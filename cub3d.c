/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:57:55 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/31 22:14:02 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			abs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

void		ft_nizar_calcul(void)
{
	if (g_mhah)
	{
		if (g_rayfacingdown)
			g_rightleftupdown = 1;
		else if (g_rayfacingup)
			g_rightleftupdown = 2;
	}
	else if (!g_mhah)
	{
		if (g_rayfacingleft)
			g_rightleftupdown = 3;
		else if (g_rayfacingright)
			g_rightleftupdown = 4;
	}
}

int			main(int argc, char **argv)
{
	int		i;

	g_sprite_number = 0;
	g_n = 0;
	g_t = 0;
	g_wall = 50;
	g_k = 0;
	g_remaind = 50;
	g_none = 1;
	g_swiitch = 1;
	g_rotationangle = 0;
	g_split = 0;
	g_dontenteragain = 0;
	if (argc == 2 || argc == 3)
		ft_check_arg(argv, argc);
	i = 0;
	g_remain_argc = argc;
	ft_variable_init_calcul_lengh(argv);
	ft_map_traitement(argv);
	ft_graphic_variable(argc);
	ft_render_map(i);
	mlx_loop_hook(g_mlx_ptr, loop_key, 0);
	mlx_loop(g_mlx_ptr);
}
