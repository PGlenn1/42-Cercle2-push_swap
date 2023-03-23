#include "push_swap.h"

// check_input TODO


void	push_swap(t_root *root)
{
	print_both(root);
	// swap(root->first_a, 'A');
	push_b(root);
	push_b(root);
	push_b(root);
	push_b(root);
	push_b(root);
	push_b(root);
	push_b(root);
	push_b(root);
	push_b(root);
	print_both(root);
	push_a(root);
	push_b(root);
	push_b(root);
	print_both(root);
	push_a(root);
	push_a(root);
	push_a(root);
	push_a(root);
	push_a(root);
	push_a(root);
	push_a(root);
	push_a(root);
	print_both(root);
	// swap(root->first_a);
	// print_both(root);
	// swap_b(root->first_a);
	// rrr(root);
	// print_both(root);
	// rrr(root);
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