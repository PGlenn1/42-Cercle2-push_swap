/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:18:15 by glpiriou          #+#    #+#             */
/*   Updated: 2023/05/31 19:44:36 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(char **input)
{
	t_root	*root;

	root = init_root(input);
	if (root->stack_a->order == INCREASING)
		ft_free_all(root, 1);
	sort_stacks(root);
	if (final_is_sorted(root))
	{
		ft_free_all(root, 0);
		return (1);
	}
	ft_free_all(root, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (push_swap(argv))
		return (0);
	return (1);
}
