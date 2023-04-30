#include "push_swap.h"

int	push_swap(char **input)
{
	t_root	*root;

	root = init_root(input);
	if (!root)
		ft_error(MALLOC_FAIL);
	if (stack_is_sorted(root->stack_a) == INCREASING)
	{
		ft_error(ALREADY_SORTED);
	}
	while (!final_is_sorted(root))
		sort_stacks(root);
	print_both(root);
	if (final_is_sorted(root))
		return (1);
	else
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