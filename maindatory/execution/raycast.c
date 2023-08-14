/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:19:29 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/08 17:25:11 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int	ft_out_ofbounds(t_grid *grid, t_exec *cub, int which)
{
	if (which == 1)
	{
		grid->i = (grid->g_y / TS_HEIGHT) - cub->ray_inf->up;
		grid->j = grid->g_x / TS_HEIGHT;
	}
	else
	{
		grid->i = grid->g_y / TS_HEIGHT;
		grid->j = (grid->g_x / TS_HEIGHT) - cub->ray_inf->left;
	}
	if (grid->i < 0 || grid->j < 0 || grid->j >= cub->infos.row_len
		|| grid->i >= cub->infos.col_len
		|| cub->infos.map[grid->i][grid->j] == ' ')
		return (1);
	return (0);
}

double	ft_pythagore_theo(double leg1, double leg2)
{
	double	hypo;

	hypo = sqrt(pow(leg1, 2) + pow(leg2, 2));
	return (hypo);
}

double	ft_floor_distance(t_raycast *ray_inf)
{
	ray_inf->ph_d = ft_pythagore_theo(ray_inf->h_grid.g_x - ray_inf->px,
			ray_inf->h_grid.g_y - ray_inf->py);
	ray_inf->pv_d = ft_pythagore_theo(ray_inf->v_grid.g_x - ray_inf->px,
			ray_inf->v_grid.g_y - ray_inf->py);
	if (ray_inf->ph_d < ray_inf->pv_d)
	{
		ray_inf->is_hori = 1;
		return (ray_inf->ph_d
			* cos(((ray_inf->rayangle - ray_inf->castray) * M_PI) / 180));
	}
	return (ray_inf->pv_d
		* cos(((ray_inf->rayangle - ray_inf->castray) * M_PI) / 180));
}

void	ft_fill_distances(t_raycast *ray_inf)
{
	ray_inf->wall.floor_d = ft_floor_distance(ray_inf);
	if (!ray_inf->wall.floor_d)
		ray_inf->wall.wall_d = (TS_HEIGHT * ray_inf -> projp_d);
	else
		ray_inf->wall.wall_d = ((TS_HEIGHT * ray_inf -> projp_d)
				/ ray_inf->wall.floor_d);
	ray_inf->wall.ceiling_d = ((S_HEIGHT - ray_inf->wall.wall_d) / 2);
}

void	ft_raycast(t_raycast *ray_inf, t_exec *cub)
{
	ft_first_gridlines(ray_inf);
	while (!ft_out_ofbounds(&ray_inf->h_grid, cub, 1)
		&& ((cub->infos.map[ray_inf->h_grid.i][ray_inf->h_grid.j] != '1')))
	{
		ray_inf->h_grid.g_x += ray_inf->h_grid.x;
		ray_inf->h_grid.g_y += ray_inf->h_grid.y;
	}
	while (!ft_out_ofbounds(&ray_inf->v_grid, cub, 0)
		&& ((cub->infos.map[ray_inf->v_grid.i][ray_inf->v_grid.j] != '1')))
	{
		ray_inf->v_grid.g_x += ray_inf->v_grid.x;
		ray_inf->v_grid.g_y += ray_inf->v_grid.y;
	}
	ft_fill_distances(ray_inf);
}
