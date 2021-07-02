/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:33:05 by gpiriou           #+#    #+#             */
/*   Updated: 2021/04/15 12:48:08 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_to_a(char *s, int n, int is_negative)
{
	int		i;
	int		n_parsed;

	n_parsed = n;
	if (is_negative)
		n_parsed *= -1;
	i = 0;
	while (i < ft_len_n(n))
	{
		s[ft_len_n(n) - 1 - i] = ((n_parsed % 10) + '0');
		n_parsed = n_parsed / 10;
		i++;
	}
	if (is_negative)
		s[0] = '-';
	s[i] = 0;
	return (s);
}

char	*ft_itoa(int n)
{
	int		is_negative;
	char	*s;
	char	*res;

	is_negative = 0;
	s = malloc((ft_len_n(n) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_memcpy(s, "-2147483648", 12);
			return (s);
		}
		is_negative = 1;
	}
	res = ft_to_a(s, n, is_negative);
	return (res);
}
