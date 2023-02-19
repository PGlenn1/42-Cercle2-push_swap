#include "push_swap.h"

// check_input TODO

t_stack **init_stack_a(char **split_tab)
{
    t_stack *first;
    t_stack *new;
    t_stack **head;

    printf("INIT STACK A\n");
    if (!split_tab)
        return (NULL);
    first = ps_lstnew(split_tab[0]);
    head = &first;
    printf("head:%p\n", head);
    printf("*head:%p\n", *head);
    new = NULL;
    int i = 1;
    while (split_tab[i])
    {
        new = ps_lstnew(split_tab[i]);
        // printf("new_str:%s\n", new->content);
        ps_lstadd_back(head, new);
        i++;
    }
    printf("*head:%p\n", *head);
    printf("END INIT STACK A\n\n");
    return (head);
}

void print_stack(t_stack **stack)
{
    t_stack *current;

    printf("PRINT STACK\n");
    current = *stack;
    printf("stack:%p\n", stack);
    while (current)
    {
        printf("*stack:%p\n", *stack);
        printf("current:%p\n", current);
        // printf("str:%s\n", current->content);
        printf("current->next:%p\n", current->next);
        current = current->next;
    }
    printf("END PRINT STACK\n\n");
}

// void push_swap(t_stack **stack_a, t_stack **stack_b)
// {

// }

int main(int argc, char **argv)
{
    char **split_input;
    t_stack **stack_a;
    t_stack **stack_b;
    t_stack *b0_init;

    (void)argc;
    printf("MAIN\n");
    split_input = ft_split(argv[1], ' ');
    printf("str:%s\n", split_input[0]);
    if (!split_input)
        return (-1);
    stack_a = init_stack_a(split_input);
    printf("head:%p\n", stack_a);
    printf("*stack_a:%p\n", *stack_a);
    b0_init = ps_lstnew(NULL);
    stack_b = &b0_init;
    // push_swap(stack_a, stack_b);
    // printf("head:%p\n", *stack_a);
    print_stack(stack_a);
    return (0);
}