#include "push_swap.h"

// check_input TODO


void	push_swap(t_root *root)
{
	print_both(root);
	push_b(root);
	print_both(root);
}

int	main(int argc, char **argv)
{
	t_root *root;

	if (argc < 2)
		return (0);
	root = init_root(argv);
	if (!root)
		return (1);
	push_swap(root);
	return (0);
}