#include "push_swap.h"

void	push_swap(t_root *root)
{
	update_stacks(root);
	print_both(root);
	push_ab(root, B);
	push_ab(root, B);
	push_ab(root, B);
	push_ab(root, B);
	push_ab(root, B);
	push_ab(root, B);
	push_ab(root, B);
	push_ab(root, B);
	push_ab(root, B);
	print_both(root);
	// push_ab(root, A);
	// push_ab(root, A);
	// push_ab(root, A);
	// push_ab(root, A);
	// push_ab(root, A);
	// push(root, B);
	// push(root, B);
	// swap(root, A);
	// swap(root, B);
	// push_b(root);
	// push_b(root);
	print_both(root);
	// ss(root);
	// rotate_a(root);
	// rotate_b(root);
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