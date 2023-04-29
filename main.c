#include "push_swap.h"

int	push_swap(char **input)
{
	t_root		*root;
	static int	i;

	root = init_root(input);
	if (!root)
		ft_error(MALLOC_FAIL);
	is_sorted(root->stack_a);
	if (root->stack_a->order == INCREASING)
	{
		ft_error(ALREADY_SORTED);
	}
	while (root->stack_a->order != INCREASING)
	{
		sort_stacks(root);
		// is_sorted(root->stack_a);
		// rotate_ab(root->stack_a);
		if (i++ == 6)
		{
			print_both(root);
			// print_result(root->stack_a);
			printf("size:%d\n", root->stack_a->size);
			printf("i:%d\n", i);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	if (push_swap(argv))
	{
		printf("Done\n");
	}
	else
	{
		printf("Failed\n");
		return (1);
	}
	return (0);
}