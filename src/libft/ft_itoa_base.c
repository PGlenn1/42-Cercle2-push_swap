/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:25:04 by gpiriou           #+#    #+#             */
/*   Updated: 2021/04/15 13:54:51 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_to_a_base(int n, char *s, char *base, int is_negative)
{
	int	i;
	int	len_n_base;

	i = 0;
	len_n_base = ft_len_n_base(base, n);
	if (n == 0)
		s[0] = '0';
	else
	{
		while (i < len_n_base)
		{
			s[len_n_base - 1 - i++] = base[n % ft_strlen(base)];
			n /= ft_strlen(base);
		}
	}
	if (is_negative)
		s[0] = '-';
	s[i] = 0;
	return (s);
}

char	*ft_itoa_base(char *base, int n)
{
	int		len_n_base;
	int		n_parsed;
	int		is_negative;
	char	*res;

	if (!ft_valid_base(base))
		return (NULL);
	len_n_base = ft_len_n_base(base, n);
	res = malloc((len_n_base + 1) * sizeof(char));
	if (!res)
		return (NULL);
	n_parsed = n;
	is_negative = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			res = "-80000000";
			return (res);
		}
		is_negative = 1;
		n_parsed *= -1;
	}
	res = ft_to_a_base(n_parsed, res, base, is_negative);
	return (res);
}
