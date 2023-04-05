#include "push_swap.h"

int	push_swap(char **input)
{
	t_root	*root;

	root = init_root(input);
	if (!root)
		ft_error(MALLOC_FAIL);
	if (is_sorted(root->stack_a))
		ft_error(ALREADY_SORTED);
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