/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:37:06 by hobenaba          #+#    #+#             */
/*   Updated: 2023/07/07 20:29:57 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*savein;
	int		j;

	savein = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!savein)
		return (NULL);
	j = 1;
	while (!ft_strstop(str) && j != 0)
	{
		j = read(fd, savein, BUFFER_SIZE);
		if (j == -1)
			return (free(savein), free(str), NULL);
		savein[j] = '\0';
		str = ft_strjoin2(str, savein);
	}	
	free(savein);
	return (str);
}

char	*ft_trimmer(char *str)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	p = malloc(i + 1 * sizeof(char));
	while (j < i)
	{
		p[j] = str[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_rem(char *s)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	if (!s[i])
		return (free(s), NULL);
	p = malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[j] = s[i];
		j++;
		i++;
	}
	p[j] = '\0';
	return (free(s), p);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*out;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (str == NULL)
		return (NULL);
	out = ft_trimmer(str);
	str = ft_rem(str);
	return (out);
}
