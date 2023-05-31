/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:48:18 by gpiriou           #+#    #+#             */
/*   Updated: 2022/11/30 18:01:14 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*s_dup;

	i = 0;
	len = ft_strlen(s);
	s_dup = malloc((len + 1) * sizeof(char));
	if (!s_dup)
		return (NULL);
	while (s[i])
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = 0;
	return (s_dup);
}
