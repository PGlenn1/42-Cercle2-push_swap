#include "push_swap.h"

// check_input TODO

t_list **init_stack_a(char **split_tab)
{
    t_list *first;
    t_list *new;
    t_list **head;

    if (!split_tab)
        return (NULL);
    first = ft_lstnew(split_tab[0]);
    head = &first;
    new = NULL;
    int i = 1;
    while (split_tab[i])
    {
        new = ft_lstnew(split_tab[i]);
        ft_lstadd_back(head, new);
        i++;
    }
    return (head);
}

void print_stack(t_list **stack)
{
    t_list *current;

    current = *stack;
    while (current)
    {
        printf("stack:%s\n", current->content);
        current = current->next;
    }
}

void push_swap(t_list **stack_a, t_list **stack_b)
{

}

int main(int argc, char **argv)
{
    char **split_input;
    t_list **stack_a;
    t_list **stack_b;
    t_list *first_b;

    (void)argc;
    split_input = ft_split(argv[1], ' ');
    if (!split_input)
        return (-1);
    stack_a = init_stack_a(split_input);
    first_b = NULL;
    stack_b = &first_b;
    push_swap(stack_a, stack_b);
    print_stack(stack_a);
    return (0);
}