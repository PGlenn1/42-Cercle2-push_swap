#include "push_swap.h"

int	push_swap(char **input)
{
	t_root	*root;

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
		printf("PROUT\n");
		sort_stacks(root);
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