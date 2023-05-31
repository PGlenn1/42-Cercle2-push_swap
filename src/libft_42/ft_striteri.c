/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:30:26 by glpiriou          #+#    #+#             */
/*   Updated: 2022/11/30 17:48:38 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	len_s;

	if (!s || !f)
		return ;
	len_s = ft_strlen(s);
	i = 0;
	while (i < len_s)
	{
		f(i, &s[i]);
		i++;
	}
}
