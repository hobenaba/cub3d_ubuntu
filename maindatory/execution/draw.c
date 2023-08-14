/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:19:20 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/08 16:16:39 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"
#include <time.h>

int	get_color_texel(t_texture *text, int x, int y)
{
	char	*dst;

	dst = text ->my_img + ((x * (text ->bits_per_pixel / 8))
			+ (text->size_line * y));
	return (*(unsigned int *)dst);
}

void	my_put_pixel_to_img(int i, int j, t_exec *cub, int color)
{
	char	*dst;

	dst = cub->mlx.p_addr + ((i * (cub->tools.bits_per_pixel / 8))
			+ (cub->tools.size_line * j));
	*(unsigned int *)dst = color;
}

int	which_side_of_wall(t_raycast *ray_inf, t_exec *cub)
{
	if (ray_inf -> is_hori == 0)
	{
		if (cub -> infos.player->info[1] - cub -> ray_inf -> v_grid.x >= 0)
			return (3);
		return (2);
	}
	else
	{
		if (cub -> infos.player->info[0] - cub -> ray_inf -> h_grid.y >= 0)
			return (1);
		return (0);
	}
}

void	draw_textures(t_wall *wall_inf, t_exec *cub, int *i)
{
	int	tmp;
	int	dst;

	tmp = wall_inf -> wall_d;
	while (*i < wall_inf->wall_d + wall_inf->ceiling_d && *i < S_HEIGHT)
	{
		if (wall_inf -> ceiling_d < 0)
			dst = wall_inf -> wall_d + wall_inf -> ceiling_d;
		else
			dst = wall_inf -> wall_d;
		cub -> tools.y = ((tmp - dst) * ((float)TS_HEIGHT / wall_inf ->wall_d))
			* ((float)cub -> text[cub -> tools.a].height / TS_HEIGHT);
		cub -> tools.color_w = get_color_texel(&(cub -> text[cub -> tools.a]),
				cub -> tools.x, cub -> tools.y);
		my_put_pixel_to_img(wall_inf->pixel, (*i)++, cub, cub->tools.color_w);
		tmp++;
	}
}

void	draw_img(t_wall *wall_inf, t_exec *cub, t_raycast *ray_inf)
{
	int	i;

	i = 0;
	cub -> tools.a = which_side_of_wall(ray_inf, cub);
	while (i < wall_inf->ceiling_d && i < S_HEIGHT)
		my_put_pixel_to_img(wall_inf->pixel, i++, cub, cub->tools.color_c);
	if (ray_inf -> is_hori == 1)
		cub -> tools.x = fmod(ray_inf -> h_grid.g_x, TS_HEIGHT)
			* ((float)cub -> text[cub -> tools.a].width / TS_HEIGHT);
	else
		cub -> tools.x = fmod(ray_inf -> v_grid.g_y, TS_HEIGHT)
			* ((float)cub -> text[cub->tools.a].width / TS_HEIGHT);
	draw_textures(wall_inf, cub, &i);
	while (i < S_HEIGHT)
		my_put_pixel_to_img(wall_inf->pixel, i++, cub, cub->tools.color_f);
}
