/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:04:06 by cchabeau          #+#    #+#             */
/*   Updated: 2022/12/20 16:03:48 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert(char type, va_list ap)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_print_char(va_arg(ap, int));
	if (type == 's')
		len += ft_print_str(va_arg(ap, char *));
	if (type == 'p')
	{
		len += ft_print_str("0x")
			+ ft_print_nbr_base(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	if (type == 'd' || type == 'i')
		len += ft_print_nbr(va_arg(ap, int));
	if (type == 'u')
		len += ft_print_nbr_base(va_arg(ap, unsigned), "0123456789");
	if (type == 'x')
		len += ft_print_nbr_base(va_arg(ap, unsigned), "0123456789abcdef");
	if (type == 'X')
		len += ft_print_nbr_base(va_arg(ap, unsigned), "0123456789ABCDEF");
	if (type == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;
	size_t	i;

	va_start(ap, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (len);
			len += ft_convert(format[i + 1], ap);
			i++;
		}
		else
		{
			if (format[i] == '\0')
				return (len);
			len += ft_print_char(format[i]);
		}
	}
	va_end(ap);
	return (len);
}
