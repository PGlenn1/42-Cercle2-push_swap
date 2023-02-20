#include "push_swap.h"

// check_input TODO

t_stack	**init_stack_a(int *int_values, int arr_size)
{
	t_stack	*first;
	t_stack	*new;
	t_stack	**head;
	int		i;

	if (!int_values)
		return (NULL);
	first = ps_lstnew(int_values[0], 0);
	head = &first;
	new = NULL;
	i = 1;
	while (i < arr_size)
	{
		new = ps_lstnew(int_values[i], i);
		ps_lstadd_back(head, new);
		i++;
	}
	return (head);
}

void	print_stack(t_stack **stack)
{
	t_stack	*current;

	printf("\nPRINT STACK\n");
	current = *stack;
	while (current)
	{
		printf("\n");
		printf("value:%d\n", current->value);
		printf("index:%d\n", current->index);
		current = current->next;
	}
	printf("\nEND PRINT STACK\n");
}

void	push_swap(int *int_values, int arr_size)
{
	t_stack	**stack_a;

	// t_stack **stack_b;
	stack_a = init_stack_a(int_values, arr_size);
	print_stack(stack_a);
	// print_stack(stack_b);
}

int	main(int argc, char **argv)
{
	char **split_input;
	int *int_values;
	int arr_size;
	int i;

	(void)argc;
	split_input = ft_split(argv[1], ' ');
	if (!split_input)
	{
		return (-1);
	}
	arr_size = 0;
	while (split_input[arr_size])
		arr_size++;
	int_values = malloc(sizeof(int) * (arr_size + 1));
	if (!int_values)
		return (-1);
	i = 0;
	while (i < arr_size)
	{
		int_values[i] = ft_atoi(split_input[i]);
		i++;
	}
	free(split_input);
	push_swap(int_values, arr_size);
	free(int_values);
	return (0);
}