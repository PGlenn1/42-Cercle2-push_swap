#include "../includes/push_swap.h"

int	push_swap(char **input)
{
	t_root	*root;

	root = init_root(input);
	if (root->stack_a->order == INCREASING)
		ft_free_all(root);
	// print_both(root);
	sort_stacks(root);
	if (final_is_sorted(root))
	{
		// print_both(root);
		ft_free_all(root);
		return (1);
	}
	// print_both(root);
	// printf("FAIL\n");
	ft_free_all(root);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	if (push_swap(argv))
		return (0);
	return (1);
}
