/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:58 by cchabeau          #+#    #+#             */
/*   Updated: 2022/10/22 21:34:29 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;
	int		slen;

	slen = ft_strlen(s);
	result = malloc((sizeof(char) * slen) + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		result[i] = s[i];
	result[i] = '\0';
	return (result);
}
