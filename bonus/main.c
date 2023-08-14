/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:49:47 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/10 09:22:33 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"	

int	close_window2(t_exec *cub)
{
	mlx_destroy_window(cub ->mlx.p_mlx, cub -> mlx.p_win);
	exit (0);
	return (0);
}

void	ft_rayang(t_raycast *ray_inf, char spaw_orient)
{
	if (spaw_orient == 'N')
		ray_inf->rayangle = 90;
	else if (spaw_orient == 'W')
		ray_inf->rayangle = 180;
	else if (spaw_orient == 'S')
		ray_inf->rayangle = 270;
	else if (spaw_orient == 'E')
		ray_inf->rayangle = 360;
}

t_raycast	*ft_rayinit(t_infos2 *player)
{
	t_raycast	*ray_inf;

	ray_inf = malloc(sizeof(t_raycast));
	if (!ray_inf)
		ft_errmsg();
	ray_inf->px = (player->info[1] * 64) + P_HEIGHT;
	ray_inf->py = (player->info[0] * 64) + P_HEIGHT;
	ft_rayang(ray_inf, player->type[0]);
	return (ray_inf);
}

int	main(int ac, char **av)
{
	t_exec	cub;

	init(&(cub.infos));
	if (ac != 2)
	{
		printf("Error\nOnly 1 argument\n");
		exit (1);
	}
	else
	{
		map(av[1], &(cub.infos));
		init_bonus_tools(&cub);
		mlx_loop_hook(cub.mlx.p_mlx, ft_execute, &cub);
		mlx_hook(cub.mlx.p_win, 17, 0, close_window2, &cub);
		mlx_hook(cub.mlx.p_win, 2, 0, key_press, &cub);
		mlx_hook(cub.mlx.p_win, 3, 0, key_release, &cub);
		mlx_hook(cub.mlx.p_win, 6, 0, mouse_move, &cub);
		mlx_loop(cub.mlx.p_mlx);
	}
}
