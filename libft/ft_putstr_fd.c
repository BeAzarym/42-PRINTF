/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:38:44 by cchabeau          #+#    #+#             */
/*   Updated: 2022/10/29 16:07:04 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
