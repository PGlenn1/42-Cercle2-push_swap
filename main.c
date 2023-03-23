#include "push_swap.h"

void	push_swap(t_root *root)
{
	update_stack_ptrs(root);
	// push_ab(root, A);
	// push_ab(root, B);
	// swap_ab(root, A);
	// swap_ab(root, B);
	// ss(root);
	print_both(root);
	// rotate_ab(root, B);
	// rotate_ab(root, A);
	// print_both(root);

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