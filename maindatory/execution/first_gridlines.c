/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_gridlines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:37:53 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/02 14:30:10 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_xy_contrary_sign(t_raycast *ray_inf)
{
	ray_inf->h_grid.g_x = ray_inf->px + ((ray_inf->py - ray_inf->h_grid.g_y)
			/ tan((ray_inf->alpha * M_PI) / 180));
	ray_inf->h_grid.x = ray_inf->xsign * TS_HEIGHT
		/ tan(ray_inf->alpha * M_PI / 180);
	ray_inf->v_grid.g_y = ray_inf->py + ((ray_inf->px - ray_inf->v_grid.g_x)
			* tan((ray_inf->alpha * M_PI) / 180));
	ray_inf->v_grid.y = ray_inf->ysign * TS_HEIGHT
		* tan((ray_inf->alpha * M_PI) / 180);
}

void	ft_xy_same_sign(t_raycast *ray_inf)
{
	ray_inf->h_grid.g_x = ray_inf->px + ((ray_inf->h_grid.g_y - ray_inf->py)
			* tan((ray_inf->alpha * M_PI) / 180));
	ray_inf->h_grid.x = ray_inf->xsign * TS_HEIGHT
		* tan(ray_inf->alpha * M_PI / 180);
	ray_inf->v_grid.g_y = ray_inf->py + ((ray_inf->v_grid.g_x - ray_inf->px)
			/ tan((ray_inf->alpha * M_PI) / 180));
	ray_inf->v_grid.y = ray_inf->ysign * TS_HEIGHT
		/ tan((ray_inf->alpha * M_PI) / 180);
}

void	ft_first_gridlines(t_raycast *ray_inf)
{	
	ray_inf->h_grid.g_y = floor(ray_inf->py / TS_HEIGHT)
		* TS_HEIGHT + ray_inf->y;
	ray_inf->v_grid.g_x = floor(ray_inf->px / TS_HEIGHT)
		* TS_HEIGHT + ray_inf->x;
	ray_inf->h_grid.y = ray_inf->ysign * TS_HEIGHT;
	ray_inf->v_grid.x = ray_inf->xsign * TS_HEIGHT;
	if ((ray_inf->up && !ray_inf->left) || (!ray_inf->up && ray_inf->left))
		ft_xy_contrary_sign(ray_inf);
	else
		ft_xy_same_sign(ray_inf);
}
