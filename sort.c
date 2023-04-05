#include "push_swap.h"


void	median_five(t_stack *stack)
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
		median_five(stack);
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

int	sort_three(t_stack *stack)
{
	int	first;
	int	sec_last;
	int	last;
	int	ops;

	printf("SORT THREE\n");
	first = stack->first->value;
	last = stack->last->value;
	sec_last = stack->last->prev->value;
	ops = 0;
	printf("PATH ");
	// print_result(stack);
	if (first < sec_last && sec_last < last)
	{
		// first < sec_last < last
		// 2 4 6
		printf("A\n");
		ops += rotate_ab(stack, A);
		ops += swap_ab(stack, A);
	}
	else if (first < last && last < sec_last)
	{
		// first < last < sec_last
		// 1 8 5
		printf("B\n");
		ops += rev_rotate_ab(stack, A);
	}
	else if (sec_last < first && first < last)
	{
		// sec_last < first < last
		// 7 3 9
		printf("C\n");
		ops += rotate_ab(stack, A);
	}
	else if (sec_last < last && last < first)
	{
		// sec_last < last < first
		// 20 15 18
		printf("D\n");
		ops += swap_ab(stack, A);
	}
	else if (last < first && first < sec_last)
	{
		// last < first < sec_last
		// 5 6 4
		printf("E\n");
		ops += rev_rotate_ab(stack, A);
		ops += swap_ab(stack, A);
	}
	else
	{
		ft_error(UNWANTED_BEHAVIOR);
	}
	return (ops);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{

}

// int	sort_five(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	ops;

// 	ops = 0;
// 	printf("SORT FIVE\n");
// 	get_median(stack_a);
// 	while (stack_a->size > 3)
// 	{
// 		if (stack->last->value < stack->median)
// 			stack_a->operator = PUSH;
// 		// ops += push_ab(root->stack_a, root->stack_b, B);
// 		else
// 			stack_a->operator = ROT;
// 		// ops += rotate_ab(root->stack_a, A);
// 	}
// 	if (is_sorted(stack_b))
// 		stack_b->operator = ROT;
// 	call_exec(stack_a, stack_b);
// 	// ops += rotate_ab(root->stack_b, B);
// 	if (!is_sorted(stack_a))
// 		ops += sort_three(stack_a);
// 	ops += push_ab(stack_b, stack_a, A);
// 	ops += push_ab(stack_b, stack_a, A);
// 	return (ops);
// }

int	pick_algo(t_root *root) /// LAST MUST BE SMALLEST
{
	if (root->stack_a->size == 2)
	{
		printf("SORT TWO\n");
		root->ops += swap_ab(root->stack_a, A);
	}
	else if (root->stack_a->size == 3)
		root->ops += sort_three(root->stack_a);
	else if (root->stack_a->size <= 5)
		root->ops += sort_five(root->stack_a, root->stack_b);
	// print_both(root);
	if (is_sorted(stack->stack_a))
		return (1);
	return (0);
}
