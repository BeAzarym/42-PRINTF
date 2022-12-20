/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:00:36 by cchabeau          #+#    #+#             */
/*   Updated: 2022/12/20 15:15:13 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
int		ft_print_char(char c);
int		ft_print_str(char *str);
size_t	ft_print_nbr(long int n);
size_t	ft_print_nbr_base(unsigned long int n, const char *base);

#endif