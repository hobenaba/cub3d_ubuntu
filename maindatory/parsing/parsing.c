/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:31:41 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/10 10:36:42 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	texture(t_infos *cub, char **str, int i, char *s)
{
	int		j;

	j = -1;
	while (str[i][++j] && str[i][j] == ' ')
		;
	while (str[i][++j] && (ft_strchr(s, str[i][j])))
		;
	while (str[i][++j] && str[i][j] == ' ')
		;
	ft_lstaddback(&(cub ->map_tex),
		ft_lstnew(s, ft_substr(str[i], j, ft_strlen(str[i]))));
}

void	color(t_infos *cub, char **str, int i, char **s)
{
	int		j;
	char	*s1;
	char	**c;
	int		a;
	int		*info;

	if (check_comma(str[i]))
		print_error(4);
	s1 = ft_strchr(str[i], s[1][0]);
	c = ft_split(s1, ',');
	info = malloc(3 * sizeof(int));
	j = -1;
	while (++j < 3 && c[j] != NULL)
	{
		a = 0;
		info[j] = ft_atoi(c[j]);
		while (c[j][a] && (c[j][a] == ' ' || c[j][a] == '+' || (c[j][a] == '0'
			&& (c[j][a + 1] != '\0' && ft_isdigit(c[j][a + 1])))))
			a++;
		if (my_countnbr(info[j]) != space(c[j]) - a
			&& ft_strcmp(c[j], "-0"))
			print_error(4);
	}
	ft_lstaddback2(&(cub -> map_col), ft_lstnew2(s[0], info));
	free_dlptr(c);
}

void	real_map(t_infos *cub, char **str, int i)
{
	check_tex_valid(cub -> map_tex);
	check_col_valid(cub -> map_col);
	cub -> player = malloc(sizeof(t_infos2));
	cub -> player->info = malloc(sizeof(int) * 2);
	check_char(str, i, &(cub -> player));
	cub->map = save_this_map(str, i);
	(cub -> player)->info[0] -= i;
	check_walls(save_this_map(str, i), cub->player);
}

char	**save_map(char *map)
{
	int		fd;
	char	*str;
	char	**s2;
	char	*s1;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_error(9);
	str = get_next_line (fd);
	s1 = the_process(str, fd);
	s2 = ft_split(s1, '\n');
	return (free (s1), s2);
}

void	map(char *map, t_infos *cub)
{
	int			i;
	char		**str;
	char		**s;

	i = 0;
	check_map_format(map);
	str = save_map(map);
	if (str == NULL)
		print_error(0);
	s = ft_split(str[0], ' ');
	while (str[i] && ft_atoi(str[i]) == 0
		&& (ft_strlen(s[0]) == 1 || ft_strlen(s[0]) == 2))
	{
		if (ft_strlen(s[0]) == 1 && s[1] != NULL)
			color(cub, str, i, s);
		else if (ft_strlen(s[0]) == 2 && s[1] != NULL)
			texture (cub, str, i, s[0]);
		free_dlptr(s);
		s = ft_split (str[++i], ' ');
	}
	free_dlptr(s);
	real_map(cub, str, i);
	cub -> col_len = dl_strlen(cub -> map, 0);
	cub -> row_len = ft_strlen (cub -> map[0]);
	free_dlptr(str);
}
