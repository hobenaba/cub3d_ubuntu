/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:04:14 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/10 10:36:37 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include "../../libft/libft.h"

typedef struct s_infos1
{
	char			*type;
	char			*info;
	struct s_infos1	*next;
}	t_infos1;

typedef struct s_infos2
{
	char			*type;
	int				*info;
	struct s_infos2	*next;
}	t_infos2;

typedef struct s_infos
{
	t_infos2	*player;
	t_infos1	*map_tex;
	t_infos2	*map_col;
	char		**map;
	int			row_len;
	int			col_len;
}	t_infos;

// function utils that helps me ou in the work
void		print_error(int num);
char		*bring_last_dot(char *map);
char		**save_map(char *map);
void		save_player(int i, int j, t_infos2 **player, char c);
int			dl_strlen(char **str, int i);
char		**save_this_map(char **str, int i);

// function parsing to check if map is valid
void		check_map_format(char *map);
void		map(char *map, t_infos *cub);

// lists that im gonnna work with
t_infos1	*ft_lstnew(char *type, char *info);
void		ft_lstaddback(t_infos1 **lst, t_infos1 *new);
t_infos2	*ft_lstnew2(char *type, int *info);
void		ft_lstaddback2(t_infos2 **lst, t_infos2 *new);
int			my_countnbr(int n);
// function checkers that help me out to check if valid or not

void		check_col_valid(t_infos2 *map_col);
int			check_rgb(t_infos2 *map_col);
void		check_tex_valid(t_infos1 *map_tex);
void		check_map_format(char *map);
void		check_char(char **str, int i, t_infos2 **player);
void		check_walls(char **map, t_infos2 *player);
void		check_xpm_file(char *info);
int			just_check(char *str);
char		*the_process(char *str, int fd);
int			check_comma(char *str);

// functions that i have used for freeing reasons

void		free_dlptr(char **str);
void		free_tex(t_infos1 *map_tex);
void		free_col(t_infos2 *map_col);

// to initialize 
void		init(t_infos *cub);
int			space(char *str);

#endif
