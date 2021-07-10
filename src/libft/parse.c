#include "libft.h"
//#include <push_swap.h>

int check_val(char **tab_s) 
{
    int i;
 
    i = 0;                                          //////////  QUE des 0 et string vide
    while (tab_s[i])
    {
        if (!ft_strncmp(tab_s[i], "-0", ft_strlen(tab_s[i])))
        {
            i++;
            continue;
        }
        else if (ft_strncmp(tab_s[i], ft_itoa(ft_atoi(tab_s[i])), ft_strlen(tab_s[i])))
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

char    **join_tabs(char ***tab_arg)
{
    int i;
    int j;
    int n;
    int number;
    int index;
    char **tab_s;

    number = 0;
    n = 0;
    while (tab_arg[n])
    {
        printf("tab_arg[n][0]: %s\n", tab_arg[n][0]);
        printf("size of tab_arg[n][0]: %s\n", 
        number += sizeof(tab_arg[n]);
        n++;
    }
    printf("number: %d\n", number);
    tab_s = malloc((number + 1) * sizeof(char *));
    if (!tab_s)
        return NULL;
    i = 0;
    index = 0;
    while (tab_arg[i])
    {
        j = 0;
        while (tab_arg[i][j])
        {
            tab_s[index] = tab_arg[i][j];
            j++;

        }
        index += j;
        printf("index: %d\n", index);
        i++;
    }
    printf("index: %d\n", index);
    tab_s[index] = NULL;
   // printf("tab[index]: %s\n", tab_s[index - -10]);
    
    return tab_s;
}

//char    **parse_args(int argc, char **argv)
//{
//    char ***tab_arg;
//    char **tab_s;
//    int i;
//    int n;
//
//    if (argc > 1)
//    {
//        n = 0;
//        while (argv[n++]);
//        tab_arg = malloc((n + 1) * sizeof(char **));
//        if (!tab_arg)
//            return (NULL);
//        i = 0;
//        while (i < n)
//        {
//            tab_arg[i] = ft_split(argv[i], ' ');
//            i++;
//        }
//        tab_arg[i] = NULL;
//        tab_s = join_tabs(tab_arg);
//    }
//}

int    main(void)
{
    char **tab_arg[5];
    char *tab_a[5];
    char *tab_b[4];
    char *tab_c[4];

    char **tab_res;

    tab_a[0] = "salut";
    tab_a[1] = "ca";
    tab_a[2] = "va";
    tab_a[3] = "mec";
    tab_a[4] = NULL;

    tab_b[0] = "moi";
    tab_b[1] = "nickel";
    tab_b[2] = "frerot";
    tab_b[3] = NULL;

    tab_c[0] = "cool";
    tab_c[1] = "alors";
    tab_c[2] = "gros";
    tab_c[3] = NULL;

    tab_arg[0] = tab_a;
    tab_arg[1] = tab_b;
    tab_arg[2] = tab_c;
    tab_arg[3] = NULL;

    tab_res = join_tabs(tab_arg);
    //printf("SIZEOF tab_res: %lu\n", sizeof(tab_res));
    int i = 0;
    //while (tab_res[i++]);
    //printf("i: %d\n", i);
    while (tab_res[i])
    {
        printf("str[%d]: %s\n", i, tab_res[i]);
        i++;
    }
    return (0);
}