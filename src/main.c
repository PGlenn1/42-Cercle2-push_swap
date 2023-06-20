/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:18:15 by glpiriou          #+#    #+#             */
/*   Updated: 2023/06/20 15:14:19 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(char **input)
{
	t_root	*root;

	root = init_root(input);
	if (root->stack_a->order == INCREASING)
		ft_free_all(root, 0);
	sort_stacks(root);
	if (final_is_sorted(root))
	{
		ft_free_all(root, 0);
		return (1);
	}
	ft_free_all(root, 1);
	return (0);
}

int	check_single_input(char *str)
{
	int	i;
	int	n;

	i = ft_is_whitespace(str);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (0);
	n = ft_atol(&str[i]);
	if (n > INT_MAX || n < INT_MIN || !check_len(&str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	i += ft_is_whitespace(&str[i]);
	if (str[i])
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		if (argc == 1)
			return (1);
		else if (!check_single_input(argv[1]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		return (0);
	}
	if (push_swap(argv))
		return (0);
	return (1);
}
