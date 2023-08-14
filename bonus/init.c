/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:07:24 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/10 12:06:51 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_texture(t_texture *texture, char *str, t_mlx *mlx)
{
	texture->img_text = mlx_xpm_file_to_image(mlx->p_mlx,
			str, &(texture->width), &(texture->height));
	texture->my_img = mlx_get_data_addr(texture->img_text,
			&(texture->bits_per_pixel),
			&(texture->size_line), &(texture->endian));
}

void	init_bonus(t_exec *cub)
{
	int		i;
	char	*str;

	i = -1;
	cub->mlx.p_maddr = mlx_get_data_addr(cub->mlx.p_mimg,
			&(cub->tools.m_bits_per_pixel),
			&(cub->tools.m_size_line), &(cub->tools.m_endian));
	cub->tools.color_mw = 0;
	cub->tools.color_mf = convert_rgb_to_n(25, 128, 128, 128);
	cub->tools.color_e = convert_rgb_to_n(150, 255, 255, 255);
	cub->weapon = malloc (sizeof(t_texture) * 5);
	while (++i < 5)
	{
		if (i == 0)
			str = "textures/00_frame.xpm";
		else if (i == 1)
			str = "textures/01_frame.xpm";
		else if (i == 2)
			str = "textures/02_frame.xpm";
		else if (i == 3)
			str = "textures/03_frame.xpm";
		else
			str = "textures/04_frame.xpm";
		init_texture(&(cub->weapon[i]), str, &(cub->mlx));
	}
}

void	init_bonus_tools(t_exec *cub)
{
	cub->mouse_x = 0;
	cub->mouse_y = 0;
	cub->state_pis = 0;
	cub->ray_inf = ft_rayinit(cub->infos.player);
	cub->mlx.p_mlx = mlx_init();
	cub->mlx.p_win = mlx_new_window(cub->mlx.p_mlx,
			S_WIDTH, S_HEIGHT, "CUB3D");
	cub->mlx.p_img = mlx_new_image(cub->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	cub->mlx.p_mimg = mlx_new_image(cub->mlx.p_mlx, MS_WIDTH, MS_HEIGHT);
	init_tools(cub);
	init_bonus(cub);
}
