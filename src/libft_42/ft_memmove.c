/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:39:08 by gpiriou           #+#    #+#             */
/*   Updated: 2022/11/30 17:46:09 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (src2 > dest2)
			dest2[i] = src2[i];
		else if (dest2 > src2)
			dest2[n - i - 1] = src2[n - i - 1];
		i++;
	}
	return (dest);
}
