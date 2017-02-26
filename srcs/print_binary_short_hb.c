/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary_short_hb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:10:07 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 16:41:59 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t		ft_binary_to_print(unsigned short b, int size,
		t_specs *specs)
{
	size_t			len;
	int				add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_oct_flags_left(size, add_precision, specs);
	ft_oct_flags_right(size, specs);
	LEFT_Z += add_precision;
	RIGHT_B -= add_precision;
	len += ft_oct_print_left(size, specs);
	ft_print_binary(b);
	len += ft_oct_print_right(specs);
	return (len);
}

size_t				ft_print_binary_short(va_list *arg, t_specs *specs)
{
	size_t			b;
	size_t			len;
	int				size;

	len = 0;
	b = va_arg(*arg, size_t);
	if (b == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		if (SHARP)
		{
			ft_putchar('0');
			len++;
		}
		return (len + WIDTH);
	}
	if (b == 0)
	{
		ft_putchar('0');
		return (len = 1);
	}
	size = ft_binary_size((unsigned short)b);
	len += size;
	len += ft_binary_to_print(b, size, specs);
	return (len);
}
