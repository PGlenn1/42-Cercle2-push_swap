/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:47:59 by gpiriou           #+#    #+#             */
/*   Updated: 2021/01/06 14:48:02 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	unsigned char	char_c;
	unsigned int	i;

	char_c = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == char_c)
			return (&s[i]);
		i++;
	}
	if (s[i] == char_c)
		return (&s[i]);
	else
		return (NULL);
}
