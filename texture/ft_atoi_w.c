/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:11:37 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/04 12:11:39 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		condition(long result, int sign)
{
	if (result > 2147483648 && sign == -1)
		return (0);
	if (result > 2147483647 && sign == 1)
		return (2550);
	return (0);
}

int				ft_atoi_w(const char *str)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && ((str[i] >= 8 && str[i] <= 13) || (str[i] == ' ')))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
		if ((result > 2147483647 && sign == 1)
				|| (result > 2147483648 && sign == -1))
			return (condition(result, sign));
	}
	return (result * sign);
}
