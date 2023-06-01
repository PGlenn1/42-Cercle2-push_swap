/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:17:50 by glpiriou          #+#    #+#             */
/*   Updated: 2023/05/31 16:28:09 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_numbers(char **input)
{
	int	i;

	i = 1;
	while (input[i])
	{
		if (!is_number(input[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (i > 11)
			return (0);
		i++;
	}
	return (1);
}

void	assign_index(t_stack *stack_a, int *array)
{
	int		i;
	t_elem	*probe;

	i = 0;
	while (i < stack_a->size)
	{
		probe = stack_a->first;
		while (probe->value != array[i])
			probe = probe->next;
		if (probe->value == array[i])
			probe->index = i;
		i++;
	}
}

int	pre_sort(t_stack *stack)
{
	int		i;
	int		*array;
	t_elem	*probe;

	array = malloc(sizeof(int) * stack->size);
	if (!array)
		return (0);
	probe = stack->first;
	i = 0;
	while (probe)
	{
		array[i] = probe->value;
		probe = probe->next;
		i++;
	}
	bubble_sort(array, stack->size);
	assign_index(stack, array);
	free(array);
	return (1);
}

int	check_input(char **input)
{
	int		i;
	int		j;
	long	value;

	i = 1;
	j = i + 1;
	value = 0;
	if (!check_numbers(input))
		return (0);
	while (input[i])
	{
		value = ft_atol(input[i]);
		if (value > INT_MAX || value < INT_MIN || !check_len(input[i]))
			return (0);
		j = i + 1;
		while (input[j])
		{
			if (value == ft_atol(input[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
