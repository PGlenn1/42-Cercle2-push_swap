/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:39:17 by gpiriou           #+#    #+#             */
/*   Updated: 2022/11/30 17:48:10 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	char_c;
	unsigned char	*s2;

	char_c = (unsigned char)c;
	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s2[i] = char_c;
		i++;
	}
	return (s);
}
