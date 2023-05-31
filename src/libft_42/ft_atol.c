/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:18:50 by glpiriou          #+#    #+#             */
/*   Updated: 2023/05/31 16:18:51 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	res;
	int		is_negative;

	res = 0;
	if (!ft_strcmp((char *)nptr, "-9223372036854775808"))
		return (-9223372036854775807L);
	is_negative = 0;
	i = ft_is_whitespace((char *)nptr);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			is_negative = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (is_negative)
		res *= -1;
	return (res);
}
