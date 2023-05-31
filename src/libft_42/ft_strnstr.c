/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:54:27 by gpiriou           #+#    #+#             */
/*   Updated: 2022/11/30 18:10:53 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncmp_mod(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*char_s1;
	unsigned char		*char_s2;

	i = 0;
	char_s1 = (unsigned char *) s1;
	char_s2 = (unsigned char *) s2;
	while ((char_s1[i] && char_s2[i]) && i < n)
	{
		if (char_s1[i] != char_s2[i])
			return (char_s1[i] - char_s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;

	if ((!big || !little) && len == 0)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (!ft_strncmp_mod(&big[i], little, len - i))
		{
			if (i + ft_strlen(little) <= len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
