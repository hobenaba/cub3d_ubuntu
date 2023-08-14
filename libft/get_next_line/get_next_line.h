/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:51:26 by hobenaba          #+#    #+#             */
/*   Updated: 2023/07/11 11:26:02 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

int		ft_strlen(const char *s);
char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strstop(char *s);
char	*ft_rem(char *s);

#endif
