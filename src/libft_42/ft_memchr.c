/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:36:30 by gpiriou           #+#    #+#             */
/*   Updated: 2022/11/27 22:05:34 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	char_c;
	size_t			i;

	s2 = (unsigned char *)s;
	char_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s2[i] == char_c)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
