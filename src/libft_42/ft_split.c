/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:43:31 by gpiriou           #+#    #+#             */
/*   Updated: 2022/12/01 17:24:42 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char *s1, int *n, char c)
{
	char	*s1_dup;
	int		i;
	int		sep_index;

	sep_index = 0;
	while (s1[sep_index] && s1[sep_index] != c)
		sep_index++;
	s1_dup = malloc((sep_index + 1) * sizeof(char));
	if (!s1_dup)
		return (NULL);
	i = 0;
	while (s1[i] && i < sep_index)
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	*n += i;
	return (s1_dup);
}

static int	ft_word_count(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i] && s[i] != c)
		words++;
	while (s[i])
	{
		if (s[i + 1] && s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

static void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**fill_tab(char **tab, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = ft_strndup(&s[i], &i, c);
			if (!tab[j])
			{
				ft_free_tab(tab);
				return (NULL);
			}
			j++;
		}
		while (s[i] && s[i] == c)
		{
			i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((ft_word_count((char *)s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = fill_tab(tab, (char *)s, c);
	return (tab);
}
