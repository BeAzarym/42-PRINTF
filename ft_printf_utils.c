/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:23:46 by cchabeau          #+#    #+#             */
/*   Updated: 2022/12/20 23:15:10 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	return (write(1, str, len));
}

size_t	ft_print_nbr(long int n)
{
	size_t	sign;
	size_t	len;

	sign = 1;
	len = 0;
	if (n < 0)
	{
		len += ft_print_char('-');
		sign = -1;
	}
	n *= sign;
	if (n < 10)
		len += ft_print_char(n + 48);
	else
	{
		len += ft_print_nbr(n / 10);
		len += ft_print_nbr(n % 10);
	}
	return (len);
}

size_t	ft_print_nbr_base(unsigned long int n, const char *base)
{
	size_t	base_len;
	size_t	len;

	if (!base || ft_strlen(base) < 2)
		return (0);
	base_len = ft_strlen(base);
	len = 0;
	if (n < base_len)
		len += ft_print_char(base[n]);
	else
	{
		len += ft_print_nbr_base(n / base_len, base);
		len += ft_print_nbr_base(n % base_len, base);
	}
	return (len);
}
