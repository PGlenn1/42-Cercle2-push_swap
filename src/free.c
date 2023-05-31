/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:17:34 by glpiriou          #+#    #+#             */
/*   Updated: 2023/05/31 16:17:37 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_elem	*probe;
	t_elem	*tmp;

	probe = stack->first;
	tmp = probe;
	while (probe)
	{
		tmp = probe;
		probe = probe->next;
		free(tmp);
	}
	free(stack);
}

void	ft_free_all(t_root *root, int error)
{
	if (root->stack_a)
		ft_free_stack(root->stack_a);
	if (root->stack_b)
		ft_free_stack(root->stack_b);
	if (root->limits)
		free(root->limits);
	free(root);
	if (error)
		ft_putstr_fd("Error\n", 2);
	exit(error);
}
