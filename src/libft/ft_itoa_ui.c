/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:36:19 by gpiriou           #+#    #+#             */
/*   Updated: 2021/04/15 11:36:50 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_to_a_ui(char *s, unsigned int n)
{
	int	i;
	int	n_parsed;

	n_parsed = n;
	i = 0;
	while (i < ft_len_n(n))
	{
		s[ft_len_n(n) - 1 - i] = ((n_parsed % 10) + '0');
		n_parsed = n_parsed / 10;
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*ft_itoa_ui(unsigned int n)
{
	char	*s;
	char	*res;

	s = malloc((ft_len_n(n) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	res = ft_to_a_ui(s, n);
	return (res);
}
