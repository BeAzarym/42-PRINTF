/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:52:19 by cchabeau          #+#    #+#             */
/*   Updated: 2022/10/29 15:55:13 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		str[++j] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		str[++j] = s2[i];
	str[++j] = '\0';
	return (str);
}
