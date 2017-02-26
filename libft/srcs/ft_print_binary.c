/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:59:47 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 14:49:10 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_binary(size_t nb)
{
	char	*tab;

	tab = "01";
	if (nb < 2)
		ft_putchar(tab[nb]);
	if (nb >= 2)
	{
		ft_print_binary(nb / 2);
		ft_putchar(tab[nb % 2]);
	}
}
