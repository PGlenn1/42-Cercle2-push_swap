#include "push_swap.h"

void	set_segments(t_root *root, int size)
{
	if (size <= 5)
	{
		root->stack_a->median = root->array[size / 2];
	}
	else if (size <= 100)
	{
		// root->stack_a->median =
	}
}

int	push_swap(char **input)
{
	t_root	*root;

	root = init_root(input);
	if (!root)
		ft_error(MALLOC_FAIL);
	if (root->stack_a->order == INCREASING)
	{
		ft_error(ALREADY_SORTED);
	}
	print_both(root);
	sort_stacks(root);
	print_both(root);
	if (final_is_sorted(root))
	{
		printf("OPS:%d\n", root->ops);
		return (1);
	}
	return (0);
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