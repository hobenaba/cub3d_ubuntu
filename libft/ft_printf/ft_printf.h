/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:05:08 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/14 15:47:21 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_char_printf(char c);
int		ft_nb_printf(int n);
int		ft_str_printf(const char *str);
int		ft_unb_printf(unsigned int nb);
int		ft_adress_printf(unsigned long n);
int		ft_hexa_printf(unsigned long n, char c);
int		ft_printf(const char *format, ...);
int		ft_len(long n);
int     ft_strlen(const char *str);

#endif
