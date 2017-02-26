/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:51:19 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 15:05:04 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_binary_size(size_t b)
{
	int				size;

	size = 1;
	while (b >= 2)
	{
		b /= 2;
		size++;
	}
	return (size);
}

static size_t		ft_binary_to_print(unsigned int b, int size, t_specs *specs)
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

size_t				ft_print_binary_b(va_list *arg, t_specs *specs)
{
	unsigned int	b;
	size_t			len;
	int				size;

	len = 0;
	b = va_arg(*arg, unsigned int);
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
	size = ft_binary_size(b);
	len += size;
	len += ft_binary_to_print(b, size, specs);
	return (len);
}
