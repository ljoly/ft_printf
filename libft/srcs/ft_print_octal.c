/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:53:58 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/03 12:07:25 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_octal(size_t nb)
{
	char	*tab;

	tab = "01234567";
	if (nb < 8)
		ft_putchar(tab[nb]);
	if (nb >= 8)
	{
		ft_print_octal(nb / 8);
		ft_putchar(tab[nb % 8]);
	}
}