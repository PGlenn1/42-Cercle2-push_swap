/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:43:31 by gpiriou           #+#    #+#             */
/*   Updated: 2021/04/15 13:01:09 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_index(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_real_split(char **tab, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = ft_strndup(&s[i], ft_word_index(&s[i], c));
			if (!tab[j])
			{
				ft_free_tab(tab);
				return (NULL);
			}
			j++;
		}
		i += ft_word_index(&s[i], c);
		if (s[i] != '\0')
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!tab)
		return(NULL);
	tab = ft_real_split(tab, s, c);
	return (tab);
}
