/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:35:58 by hbenabad          #+#    #+#             */
/*   Updated: 2023/08/11 12:21:38 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../include/parsing.h"
# include <math.h>
# include <mlx.h>
# define S_WIDTH	1200
# define S_HEIGHT	900
# define MS_HEIGHT	180
# define MS_WIDTH	240
# define TS_HEIGHT	64
# define MTS_HEIGHT	16
# define P_HEIGHT	32
# define FOV		60
# define SPEED		5

typedef struct s_wall
{
	double	wall_d;
	double	ceiling_d;
	double	floor_d;
	int		pixel;
}	t_wall;

typedef struct s_grid
{
	double	g_x;
	double	g_y;
	double	x;
	double	y;
	int		i;
	int		j;
	int		out_bounds;
}	t_grid;

typedef struct s_raycast
{
	double	px;
	double	py;
	double	ph_d;
	double	pv_d;
	float	alpha;
	float	rayangle;
	float	castray;
	float	endray;
	int		up;
	int		left;
	int		w_side;
	int		is_hori;
	int		len_row;
	int		len_col;
	int		x;
	int		y;
	double	projp_d;
	int		xsign;
	int		ysign;
	t_grid	h_grid;
	t_grid	v_grid;
	t_wall	wall;
}	t_raycast;

typedef struct s_mlx
{
	void		*p_win;
	void		*p_mlx;
	void		*p_mimg;
	char		*p_maddr;
	void		*p_img;
	char		*p_addr;
}	t_mlx;

typedef struct s_draw
{
	int			color_f;
	int			color_c;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			m_bits_per_pixel;
	int			m_size_line;
	int			m_endian;
	int			x;
	int			y;
	int			a;
	int			color_w;
	int			color_mw;
	int			color_e;
	int			color_mf;
	double		my_width;
	double		my_height;
}	t_draw;

typedef struct s_texture
{
	void		*img_text;
	char		*my_img;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}	t_texture;

typedef struct s_exec
{
	t_texture	*text;
	t_infos		infos;
	t_mlx		mlx;
	t_draw		tools;
	t_raycast	*ray_inf;
	size_t		i;
	double		subray_ang;
	int			mouse_x;
	int			mouse_y;
	t_texture	*weapon;
	int			rot_left;
	int			rot_right;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			move_weapon;
	int			state_pis;
}	t_exec;

void		ft_errmsg(void);
void		ft_raycast(t_raycast *ray_inf, t_exec *cub);
int			ft_execute(t_exec *cub);
void		ft_first_gridlines(t_raycast *ray_inf);

void		init_tools(t_exec *cub);
void		draw_img(t_wall *infos, t_exec *cub, t_raycast *ray_inf);
int			key_hook(t_exec *cub);
t_raycast	*ft_rayinit(t_infos2 *player);
int			convert_rgb_to_n(int t, int r, int g, int b);
int			get_color_texel(t_texture *text, int x, int y);
void		my_put_pixel_to_img(int i, int j, t_exec *cub, int color);

void		draw_minimap(t_exec *cub);
int			mouse_move(int x, int y, t_exec *cub);
void		init_bonus(t_exec *cub);
int			key_press(int key, t_exec *cub);
int			key_release(int key, t_exec *cub);
void		draw_weapon(t_exec *cub, int frame);
void		ft_player_move(t_exec *cub);
void		init_for_wind(t_exec *cub);
void		init_bonus_tools(t_exec *cub);
void		ft_init_keys(t_exec *cub);

#endif
