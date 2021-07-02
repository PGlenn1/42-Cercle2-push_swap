/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:56:12 by gpiriou           #+#    #+#             */
/*   Updated: 2021/04/15 12:51:54 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list **lst)
{
	int				i;
	struct s_list	*probe;

	probe = *lst;
	i = 0;
	while (probe)
	{
		write(1, "node[", 5);
		ft_putnbr_fd(i, 1);
		write(1, "]: ", 3);
		ft_print_address(probe);
		probe = probe->next;
		i++;
	}
}
