/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:50:07 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/03 12:01:29 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_hex(size_t nb, int upper)
{
	char	*tab;

	if (upper == 1)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_print_hex(nb / 16, upper);
		ft_putchar(tab[nb % 16]);
	}
}
