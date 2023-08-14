/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:51:13 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/10 19:19:35 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int	key_hook(t_exec *cub)
{
	if (cub->rot_right)
		cub->ray_inf->rayangle = (cub->ray_inf->rayangle - SPEED);
	else if (cub->rot_left)
		cub->ray_inf->rayangle = (cub->ray_inf->rayangle + SPEED);
	else if (cub->move_up || cub->move_left
		|| cub->move_down || cub->move_right)
		ft_player_move(cub);
	return (0);
}

int	key_press(int key, t_exec *cub)
{
	if (key == 53)
	{
		mlx_destroy_window(cub ->mlx.p_mlx, cub -> mlx.p_win);
		exit (0);
	}
	if (key == 0)
		cub->move_left = 1;
	else if (key == 1)
		cub->move_down = 1;
	else if (key == 2)
		cub->move_right = 1;
	else if (key == 13)
		cub->move_up = 1;
	else if (key == 123)
		cub->rot_left = 1;
	else if (key == 124)
		cub->rot_right = 1;
	else if (key == 49)
		cub->move_weapon = 1;
	return (0);
}

int	key_release(int key, t_exec *cub)
{
	if (key == 0)
		cub->move_left = 0;
	else if (key == 1)
		cub->move_down = 0;
	else if (key == 2)
		cub->move_right = 0;
	else if (key == 13)
		cub->move_up = 0;
	else if (key == 123)
		cub->rot_left = 0;
	else if (key == 124)
		cub->rot_right = 0;
	else if (key == 49)
		cub->move_weapon = 0;
	return (0);
}
