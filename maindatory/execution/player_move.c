/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:56 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/10 19:36:40 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_change_playerxy(double adja, double oppo, t_exec *cub)
{
	int	i;

	i = 0;
	while (++i <= (SPEED * 2))
	{
		if (cub->infos.map[(int)(cub->ray_inf->py + (oppo * i)) / TS_HEIGHT]
			[(int)(cub->ray_inf->px + (adja * i)) / TS_HEIGHT] == '1'
			|| (cub->infos.map[(int)(cub->ray_inf->py) / TS_HEIGHT]
			[(int)(cub->ray_inf->px + (adja * i)) / TS_HEIGHT] == '1'
			&& cub->infos.map[(int)(cub->ray_inf->py + (oppo * i)) / TS_HEIGHT]
			[(int)(cub->ray_inf->px) / TS_HEIGHT] == '1'))
			return ;
	}
	cub->ray_inf->py += (oppo * SPEED);
	cub->ray_inf->px += (adja * SPEED);
}

void	ft_xy_change(t_exec *cub, int xsign, int ysign, int hori)
{
	double	adja;
	double	oppo;

	adja = xsign * cos((cub->ray_inf->rayangle - (hori * 90)) * M_PI / 180);
	oppo = ysign * sin((cub->ray_inf->rayangle - (hori * 90)) * M_PI / 180);
	ft_change_playerxy(adja, oppo, cub);
}

void	ft_player_move(t_exec *cub)
{
	if (cub->move_up)
		ft_xy_change(cub, 1, -1, 0);
	else if (cub->move_down)
		ft_xy_change(cub, -1, 1, 0);
	else if (cub->move_left)
		ft_xy_change(cub, -1, 1, 1);
	else
		ft_xy_change(cub, 1, -1, 1);
}
