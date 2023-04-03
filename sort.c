#include "push_swap.h"

// int    get_median_value(int first, int middle, int last)
// {
//     if ((first < middle && middle < last) || (last < middle
// && middle < first)) {
//         return (middle);
//     }
//     else if ((middle < first && first < last) || (last < first
// && first < middle)) {
//         return (first);
//     }
//     else {
//         return (last);
//     }
// }

// int median(t_stack *stack)
// {

// }

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

void	sort_three(t_root *root, t_stack *stack)
{
	int	first;
	int	sec_last;
	int	last;

	printf("SORT THREE\n");
	// (void)root;
	first = stack->first->value;
	sec_last = stack->sec_last->value;
	last = stack->last->value;
	printf("CHOICE PATH\n");
	print_result(stack);
	if (first < sec_last && sec_last < last)
	{
		// first < sec_last < last
		// 2 4 6
		rotate_ab(root, A);
		printf("A\n");
		swap_ab(root, A);
	}
	else if (first < last && last < sec_last)
	{
		// first < last < sec_last
		// 1 8 5
		printf("B\n");
		rev_rotate_ab(root, A);
	}
	else if (sec_last < first && first < last)
	{
		// sec_last < first < last
		// 7 3 9
		printf("C\n");
		rotate_ab(root, A);
	}
	else if (sec_last < last && last < first)
	{
		// sec_last < last < first
		// 20 15 18
		printf("D\n");
		swap_ab(root, A);
	}
	else if (last < first && first < sec_last)
	{
		// last < first < sec_last
		// 5 6 4
		printf("E\n");
		rev_rotate_ab(root, A);
		swap_ab(root, A);
	}
	else
	{
		ft_error(UNWANTED_BEHAVIOR);
	}
}

void	sort_five(t_root *root, t_stack *stack)
{
	(void)root, (void)stack;
	// printf("SORT FIVE\n");
	// get_median(stack);
	// while (stack->size > 3)
	// {
	//     if (stack->last->value < stack->median)
	//         push_ab(root, B);
	//     else
	//         rotate_ab(root, A);
	// }
	// print_both(root);
	// if (is_sorted(root->stack_b))
	//     swap_ab(root, B);
	// if (!is_sorted(stack))
	//     sort_three(root, stack);
	// push_ab(root, stack);
	// push_ab(root, A);
	// swap_ab(root, ab);
}

int	pick_algo(t_root *root, t_stack *stack) /// LAST MUST BE SMALLEST
{
	stack_ab ab;

	if (stack == root->stack_a)
		ab = A;
	else
		ab = B;
	printf("\nPICK ALGO %c\n", ab == A ? 'A' : 'B');
	push_ab(root->stack_a, root->stack_b);
	print_both(root);
	// if (stack->size == 2)
	// {
	//     printf("SORT TWO\n");
	// 	swap_ab(root, ab);
	// }
	// else if (stack->size == 3)
	// 	sort_three(root, stack);
	// else if (stack->size <= 5)
	// sort_five(root, stack);
	// push_ab(root->stack_a, root->stack_b);
	// push_ab(root->stack_a, root->stack_b);
	// push_ab(root->stack_a, root->stack_b);
	// push_ab(root->stack_a, root->stack_b);
	print_both(root);
	// push_ab(root->stack_a, root->stack_b);
	// push_ab(root->stack_a, root->stack_b);
	// push_ab(root->stack_a, root->stack_b);
	print_both(root);
	// printf("PUSH A TEST\n");
	// print_both(root);
	if (is_sorted(stack))
		return (1);
	return (0);
}
