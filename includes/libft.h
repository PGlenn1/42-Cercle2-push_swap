/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:30:41 by gpiriou           #+#    #+#             */
/*   Updated: 2021/04/15 17:01:31 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(char *str);
unsigned long	ft_atoi_lu(char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_free_tab(char **tab);
void			*ft_free_all(char **tab);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isupper(int c);
char			*ft_itoa(int n);
char			*ft_itoa_ui(unsigned int n);
char			*ft_itoa_base(char *base, int n);
char			*ft_itoa_base_lu(char *base, unsigned long n);
char			*ft_itoa_base_ui(char *base, unsigned int n);
int				ft_len_n_base(char *base, int n);
int				ft_len_n_base_lu(char *base, unsigned long n);
int				ft_len_n_base_ui(char *base, unsigned int n);
int				ft_len_n(int n);
int				ft_len_n_ui(unsigned int n);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lt, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			*ft_memccpy(void *dst, void *src, int c, size_t n);
void			*ft_memchr(void *s, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);
void			*ft_memcpy(void	*dst, void *src, size_t n);
void			*ft_memmove(void *dst, void *src, size_t len);
void			*ft_memset(void *s, int c, size_t len);
void			ft_print_list(t_list **lst);
void			ft_print_address(void *ptr);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_base(char *base, int nbr, char *str, int index);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_skip_non_printable(char *str);
int				ft_skip_whitespace(char *str);
char			**ft_split(char *s, char c);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *s1);
char			*ft_strndup(char *s1, int n);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
int				ft_strlen(char *str);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strnstr(char *haystack, char *needle, size_t len);
char			*ft_strrchr(char *s, int c);
char			*ft_strtrim(char *s1, char *set);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			ft_swap(char **str1, char **str2);
int				ft_tolower(int c);
char			*ft_str_toupper(char *str);
int				ft_toupper(int c);
int				ft_valid_base(char *base);
int				ft_word_count(char *s, char c);

#endif
