#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int check_val(char **tab)
{
    int i;
 
    i = 0;
    while (tab[i])
    {
        if (ft_strncmp(tab[i], ft_itoa(ft_atoi(tab[i])), ft_strlen(tab[i])))
            return (0);
        i++;
    }
    return (1);
}

int *get_val(char **tab_s)
{
    int    i;
    int    *tab_n;

    i = 0;
    while (tab_s[i++]);
    tab_n = malloc(i * sizeof(int));
    if (!tab_n)
    {
        ft_free_tab(tab_s);
        return (NULL);
    }
    if (check_val(tab_s))    
    {
        i = 0;
        while (tab_s[i])
        {
            tab_n[i] = ft_atoi(tab_s[i]);
            i++;
        }
    }
    else
    {
        write(1, "Error\n", 6);
        return (NULL);
    }
    return (tab_n);
}
