/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:17:27 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/04 14:17:29 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		rad(double x)
{
	return ((x * M_PI) / 180);
}

double		deg(double x)
{
	return ((x * 360) / (2 * M_PI));
}