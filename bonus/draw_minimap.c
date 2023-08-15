/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:09:53 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/08 16:24:49 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(t_exec *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->mlx.p_maddr + ((x * (cub->tools.m_bits_per_pixel / 8))
			+ (cub->tools.m_size_line * y));
	*(unsigned int *)dst = color;
}

int	check_color(double x, double y, t_exec *cub)
{
	int	x1;
	int	y1;

	x1 = floor (x / MTS_HEIGHT);
	y1 = floor (y / MTS_HEIGHT);
	if (x1 < 0 || y1 < 0 || x1 >= cub -> infos.row_len
		|| y1 >= cub -> infos.col_len || cub -> infos.map[y1][x1] == ' ')
		return (cub -> tools.color_e);
	else if (cub -> infos.map[y1][x1] != '1')
		return (cub -> tools.color_mf);
	else
		return (cub -> tools.color_mw);
}	

void	draw_player(t_exec *cub)
{
	int	x1;
	int	y1;
	int	x;
	int	y;
	int	i;

	i = -1;
	x1 = (MS_WIDTH / 2) - (MTS_HEIGHT / 6);
	x = -1;
	while (++x < MTS_HEIGHT / 3)
	{
		y = -1;
		y1 = (MS_HEIGHT / 2) - (MTS_HEIGHT / 6);
		while (++y < MTS_HEIGHT / 3)
			put_pixel(cub, x1, y1++, 0xFFFF00);
		x1++;
	}
	while (++i < 9)
	{
		put_pixel(cub,
			(MS_WIDTH / 2) + (i * cos(cub->ray_inf->rayangle * M_PI / 180)),
			(MS_HEIGHT / 2) - (i * sin(cub->ray_inf->rayangle * M_PI / 180)),
			0xFFFF00);
	}
}

void	draw_minimap(t_exec *cub)
{
	int		x;
	double	x1;
	int		color;
	int		y;
	double	y1;

	x = -1;
	x1 = ((cub -> ray_inf-> px / TS_HEIGHT) * MTS_HEIGHT) - (MS_WIDTH / 2) - 1;
	while (++x < MS_WIDTH)
	{
		y = -1;
		y1 = ((cub -> ray_inf-> py / TS_HEIGHT)
				* MTS_HEIGHT) - (MS_HEIGHT / 2) - 1;
		while (++y < MS_HEIGHT)
		{
			color = check_color(x1, y1++, cub);
			put_pixel(cub, x, y, color);
		}
		x1++;
	}
	draw_player(cub);
}
