#include "push_swap.h"

// check_input TODO

t_stack **init_stack_a(char **split_tab)
{
    t_stack *first;
    t_stack *new;
    t_stack **head;

    if (!split_tab)
        return (NULL);
    first = ps_lstnew(split_tab[0]);
    head = &first;
    new = NULL;
    int i = 1;
    while (split_tab[i])
    {
        new = ps_lstnew(split_tab[i]);
        // printf("new_str:%s\n", new->content);
        ps_lstadd_back(head, new);
        i++;
    }
    return (head);
}

void print_stack(t_stack **stack)
{
    t_stack *current;

	printf("\nPRINT STACK\n");
    current = *stack;
    while (current)
    {
        printf("str:%s\n", current->content);
        current = current->next;
    }
	printf("\nEND PRINT STACK\n");
}

void push_swap(char **split_input)
{
    t_stack **stack_a;
	t_stack **stack_b;
	t_stack *b_elem0;

    stack_a = init_stack_a(split_input);
    print_stack(stack_a);
	b_elem0 = ps_lstnew(NULL);
	stack_b = &b_elem0;
	print_stack(stack_b);
}

int main(int argc, char **argv)
{
    char **split_input;

    (void)argc;
    split_input = ft_split(argv[1], ' ');
    if (!split_input)
	{
        return (-1);
	}
	push_swap(split_input);
    return (0);
}