/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:16:00 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 16:54:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_print_width(t_specs *specs)
{
	size_t		len;

	len = 0;
	ft_print_blanks(WIDTH - 1);
	ft_putchar('%');
	len += WIDTH;
	return (len);
}

size_t			ft_print_percent(t_specs *specs)
{
	size_t		len;

	len = 0;
	if (MINUS)
	{
		ft_putchar('%');
		ft_print_blanks(WIDTH - 1);
		len += WIDTH;
	}
	else if (ZERO)
	{
		ft_print_zeros(WIDTH - 1);
		ft_putchar('%');
		len += WIDTH;
	}
	else if (WIDTH)
		len += ft_print_width(specs);
	else
	{
		ft_putchar('%');
		len++;
	}
	return (len);
}
