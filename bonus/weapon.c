/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:29:21 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/09 19:46:44 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_weapon(t_exec *cub, int frame)
{
	t_w	w;

	w.factor_x = (float)cub->weapon[frame].width / S_WIDTH * 10;
	w.factor_y = (float)cub->weapon[frame].height / S_HEIGHT * 10;
	w.x = (S_WIDTH / 2) - (cub->weapon[frame].width / 2);
	w.x = w.x - (w.factor_x * w.x);
	w.b = (S_WIDTH / 2) - w.x;
	w.x2 = w.x;
	while (w.x < S_WIDTH / 2 + w.b)
	{
		w.y = S_HEIGHT - cub ->weapon[frame].height;
		w.y = w.y - (w.factor_y * w.y) - 1;
		w.x1 = (w.x - w.x2) * ((float)cub->weapon[frame].width / (w.b * 2));
		w.y2 = w.y;
		while (++w.y < S_HEIGHT)
		{
			w.y1 = (w.y - w.y2) * ((float)cub->weapon[frame].height
					/ (S_HEIGHT - w.y2));
			w.color = get_color_texel(&(cub->weapon[frame]), w.x1, w.y1);
			if (w.color != 0x980088)
				my_put_pixel_to_img(w.x, w.y, cub, w.color);
		}
		w.x++;
		w.x1++;
	}
}
