/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:29:31 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/10 12:00:24 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/execution.h"

void	ft_sign_alpha_place(t_raycast *ray_inf)
{
	ray_inf->alpha = ray_inf->castray
		- ((int)(ray_inf->castray / 90) * 90);
	if ((((int)ray_inf->castray % 360) >= 0)
		&& (((int)ray_inf->castray % 360) < 180))
	{
		ray_inf->up = 1;
		ray_inf->y = 0;
		ray_inf->ysign = -1;
	}
	if (((int)ray_inf->castray % 360) >= 90
		&& ((int)ray_inf->castray % 360) < 270)
	{
		ray_inf->left = 1;
		ray_inf->x = 0;
		ray_inf->xsign = -1;
	}
}

void	ft_init_values(t_raycast *ray_inf)
{
	ray_inf->is_hori = 0;
	ray_inf->up = 0;
	ray_inf->left = 0;
	ray_inf->y = 64;
	ray_inf->x = 64;
	ray_inf->xsign = 1;
	ray_inf->ysign = 1;
	ft_sign_alpha_place(ray_inf);
}

void	ft_rayrelated(t_raycast *ray_inf)
{
	ray_inf->rayangle = remainder(ray_inf->rayangle, 360);
	if (ray_inf->rayangle < 0)
		ray_inf->rayangle = 360 + ray_inf->rayangle;
	ray_inf->castray = ray_inf->rayangle + ((FOV / 2));
}

int	ft_execute(t_exec *cub)
{
	// key_hook(cub);
	ft_rayrelated(cub->ray_inf);
	cub->ray_inf->wall.pixel = 0;
	while (cub->ray_inf->wall.pixel < S_WIDTH)
	{
		if (cub->ray_inf->castray < 0)
			cub->ray_inf->castray = 360 - cub->ray_inf->castray;
		ft_init_values(cub->ray_inf);
		ft_raycast(cub->ray_inf, cub);
		draw_img(&(cub->ray_inf->wall), cub, cub->ray_inf);
		cub->ray_inf->wall.pixel++;
		cub->ray_inf->castray -= cub->subray_ang;
	}
	mlx_clear_window(cub->mlx.p_mlx, cub->mlx.p_win);
	mlx_put_image_to_window(cub->mlx.p_mlx, cub->mlx.p_win,
		cub->mlx.p_img, 0, 0);
	return (1);
}
