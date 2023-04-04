#include "push_swap.h"

void	median_small(t_stack *stack)
{
	int		i;
	int		*array;
	t_elem	*probe;

	array = malloc(sizeof(int) * stack->size);
	if (!array)
		ft_error(MALLOC_FAIL);
	probe = stack->first;
	i = 0;
	while (probe)
	{
		array[i] = probe->value;
		probe = probe->next;
		i++;
	}
	array = bubble_sort(array, 5);
	stack->median = array[2];
	printf("FOUND MEDIAN:%d\n", stack->median);
	free(array);
}

void	get_median(t_stack *stack)
{
	int	first;
	int	middle;
	int	last;

	if (!stack || !stack->first)
		return ;
	(void)middle;
	first = stack->first->value;
	last = stack->first->value;
	(void)last;
	(void)first;
	if (stack->size <= 12)
		median_small(stack);
	// else if
	//     median = median_twelve(stack);
	// else
	//     median = median(stack);
}

// void    push_median(t_root *root, t_stack *stack)
// {
//     t_elem *probe;

//     probe = stack->first;
//     while (probe && !is_sorted(stack))
//     {
//         if (probe->value <= stack->median)
//             push_ab(root, B);
//         // if (!is_sorted(stack))
//         probe = probe->next;
//     }
//     if (!is_sorted(stack))
//     {
//         if (stack == root->stack_a)
//             pick_algo(root, root->stack_b);
//         else if (stack == root->stack_b)
//             pick_algo(root, root->stack_a);
//         else
//             ft_error(UNWANTED_BEHAVIOR);
//     }
// }

void	sort_three(t_stack *stack)
{
	int	first;
	int	sec_last;
	int	last;

	printf("SORT THREE\n");
	first = stack->first->value;
	last = stack->last->value;
	sec_last = stack->last->prev->value;
	printf("PATH ");
	// print_result(stack);
	if (first < sec_last && sec_last < last)
	{
		// first < sec_last < last
		// 2 4 6
		printf("A\n");
		rotate_ab(stack, A);
		swap_ab(stack, A);
	}
	else if (first < last && last < sec_last)
	{
		// first < last < sec_last
		// 1 8 5
		printf("B\n");
		rev_rotate_ab(stack, A);
	}
	else if (sec_last < first && first < last)
	{
		// sec_last < first < last
		// 7 3 9
		printf("C\n");
		rotate_ab(stack, A);
	}
	else if (sec_last < last && last < first)
	{
		// sec_last < last < first
		// 20 15 18
		printf("D\n");
		swap_ab(stack, A);
	}
	else if (last < first && first < sec_last)
	{
		// last < first < sec_last
		// 5 6 4
		printf("E\n");
		rev_rotate_ab(stack, A);
		swap_ab(stack, A);
	}
	else
	{
		ft_error(UNWANTED_BEHAVIOR);
	}
}

void	sort_five(t_root *root, t_stack *stack)
{
	printf("SORT FIVE\n");
	get_median(stack);
	while (stack->size > 3)
	{
		if (stack->last->value < stack->median)
			push_ab(root->stack_a, root->stack_b, B);
		else
			rotate_ab(root->stack_a, A);
	}
	if (is_sorted(root->stack_b))
		rotate_ab(root->stack_b, B);
	if (!is_sorted(stack))
		sort_three(stack);
	push_ab(root->stack_b, root->stack_a, A);
	push_ab(root->stack_b, root->stack_a, A);
}

// void	sort_twelve(t_root *root, t_stack *stack)
// {
// 	printf("SORT TWELVE\n");
// 	get_median(stack);

// }

int	pick_algo(t_root *root, t_stack *stack) /// LAST MUST BE SMALLEST
{
	stack_ab ab;

	if (stack == root->stack_a)
		ab = A;
	else
		ab = B;
	printf("\nPICK ALGO %c\n", ab == A ? 'A' : 'B');
	if (stack->size == 2)
	{
		printf("SORT TWO\n");
		swap_ab(root->stack_a, A);
	}
	else if (stack->size == 3)
		sort_three(stack);
	else if (stack->size <= 5)
		sort_five(root, stack);
	// print_both(root);
	if (is_sorted(stack))
		return (1);
	return (0);
}
