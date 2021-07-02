/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_n_base_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:00:12 by gpiriou           #+#    #+#             */
/*   Updated: 2021/04/15 13:00:27 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_n_base_ui(char *base, unsigned int n)
{
	int	base_len;
	int	len_n_base;

	if (n == 0)
		return (1);
	base_len = ft_strlen(base);
	len_n_base = 0;
	while (n != 0)
	{
		n /= base_len;
		len_n_base++;
	}
	return (len_n_base);
}
