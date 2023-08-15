/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:35:49 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/10 10:29:37 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "maindatory/include/parsing.h"
# include "maindatory/include/execution.h"
# include <mlx.h>

typedef struct s_weapon
{
	int		x;
	int		x1;
	int		y;
	int		y2;
	int		y1;
	int		x2;
	int		b;
	int		color;
	double	factor_x;
	double	factor_y;
}	t_w;

#endif