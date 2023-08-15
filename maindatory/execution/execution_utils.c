/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:26:40 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/09 16:57:55 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_errmsg(void)
{
	perror("Error\n");
	exit(1);
}

int	convert_rgb_to_n(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	init_for_wind(t_exec *cub)
{
	int			*floor;
	int			*ceiling;
	t_infos2	*tmp;

	cub->mlx.p_win = mlx_new_window(cub->mlx.p_mlx,
			S_WIDTH, S_HEIGHT, "CUB3D");
	cub->mlx.p_img = mlx_new_image(cub->mlx.p_mlx, S_WIDTH, S_HEIGHT);
	tmp = cub -> infos.map_col;
	if (!ft_strcmp(tmp ->type, "F"))
	{
		floor = tmp -> info;
		ceiling = tmp -> next -> info;
	}
	else
	{
		floor = tmp -> next -> info;
		ceiling = tmp -> info;
	}
	cub -> tools.color_f = convert_rgb_to_n(0, floor[0], floor[1], floor[2]);
	cub -> tools.color_c = convert_rgb_to_n
		(0, ceiling[0], ceiling[1], ceiling[2]);
	cub->mlx.p_addr = mlx_get_data_addr(cub->mlx.p_img,
			&(cub ->tools.bits_per_pixel),
			&(cub ->tools.size_line), &(cub ->tools.endian));
}

void	init_textures(t_texture *text, t_infos1 *my_text, t_mlx *mlx)
{
	text ->img_text = mlx_xpm_file_to_image(mlx -> p_mlx,
			my_text -> info, &(text -> width), &(text -> height));
	if (text -> img_text == NULL)
		print_error(10);
	text -> my_img = mlx_get_data_addr(text -> img_text,
			&(text -> bits_per_pixel), &(text -> size_line), &(text -> endian));
}

void	init_tools(t_exec *cub)
{
	t_infos1	*t;
	int			i;

	t = cub -> infos.map_tex;
	cub->text = malloc (sizeof(t_texture) * 4);
	while (t)
	{
		if (!ft_strcmp(t -> type, "NO"))
			i = 0;
		if (!ft_strcmp(t -> type, "SO"))
			i = 1;
		if (!ft_strcmp(t -> type, "WE"))
			i = 2;
		if (!ft_strcmp(t -> type, "EA"))
			i = 3;
		init_textures(&(cub -> text[i]), t, &(cub ->mlx));
		t = t -> next;
	}
	init_for_wind(cub);
	cub -> infos.col_len = dl_strlen(cub ->infos.map, 0);
	cub -> infos.row_len = ft_strlen (cub -> infos.map[0]);
	cub->subray_ang = ((float)FOV / (float)S_WIDTH);
	cub->ray_inf->projp_d = ((S_WIDTH / 2) / tan(((FOV / 2) * M_PI) / 180));
}
