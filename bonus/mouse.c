/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:23:43 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/10 19:20:08 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	mouse_move(int x, int y, t_exec *cub)
{
	if ((x >= 0 && x <= S_WIDTH) && (y >= 0 && y <= 1000))
	{
		if (x > cub->mouse_x)
			cub->ray_inf->rayangle = (cub->ray_inf->rayangle - SPEED);
		else
			cub->ray_inf->rayangle = (cub->ray_inf->rayangle + SPEED);
		cub->mouse_x = x;
	}
	return (0);
}
