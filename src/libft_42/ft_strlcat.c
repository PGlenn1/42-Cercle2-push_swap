/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:07:29 by gpiriou           #+#    #+#             */
/*   Updated: 2022/11/30 17:24:01 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if ((!dst || !src) && size == 0)
		return (0);
	dst_len = ft_strlen((char *)dst);
	src_len = ft_strlen((char *)src);
	i = dst_len;
	if (dst_len >= size || size == 0)
		return (src_len + size);
	while (*src && i + 1 < size)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
