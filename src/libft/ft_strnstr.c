/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:54:27 by gpiriou           #+#    #+#             */
/*   Updated: 2021/01/08 10:01:02 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncmp_mod(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	i = 0;
	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	while ((char_s1[i] && char_s2[i]) && i < n)
	{
		if (char_s1[i] != char_s2[i])
			return (char_s1[i] - char_s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	unsigned int	i;

	if (*needle == '\0')
		return (haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (!ft_strncmp_mod(&haystack[i], needle, len - i))
		{
			if (i + ft_strlen(needle) <= len)
				return (&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
