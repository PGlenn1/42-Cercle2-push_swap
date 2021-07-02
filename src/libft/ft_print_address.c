/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:01:32 by gpiriou           #+#    #+#             */
/*   Updated: 2021/04/15 13:02:59 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_address(void *ptr)
{
	char			*ptr_to_str;
	char			*str;
	unsigned long	ptr2;
	int				len_str;
	int				str_diff;

	ptr2 = (unsigned long)ptr;
	ptr_to_str = ft_itoa_base_lu("0123456789abcdef", ptr2);
	len_str = ft_strlen(ptr_to_str);
	str = (char *)malloc((17) * sizeof(char));
	if (!str)
		return ;
	str = ft_memset(str, '0', 16);
	str[16] = '\0';
	str_diff = 16 - len_str;
	write(1, "0x", 2);
	write(1, str, str_diff);
	write(1, ptr_to_str, len_str);
	write(1, "\n", 1);
}
