/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:57:22 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 20:09:33 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_hex_size(size_t x)
{
	int				size;

	size = 1;
	while (x >= 16)
	{
		x /= 16;
		size++;
	}
	return (size);
}

static size_t		ft_hex_to_print(unsigned int x, int size, t_specs *specs)
{
	size_t			len;
	int				add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_hex_flags_left(size, add_precision, specs);
	ft_hex_flags_right(size, specs);
	LEFT_Z += add_precision;
	RIGHT_B -= add_precision;
	len += ft_hex_print_left(specs);
	ft_print_hex(x, HEX_UPPER);
	len += ft_hex_print_right(specs);
	return (len);
}

size_t				ft_print_hex_upper(va_list *arg, t_specs *specs)
{
	unsigned int	x;
	size_t			len;
	int				size;

	len = 0;
	HEX_UPPER = 1;
	x = va_arg(*arg, unsigned int);
	if (x == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		return (len = WIDTH);
	}
	if (x == 0)
		SHARP = 0;
	size = ft_hex_size(x);
	len += size;
	len += ft_hex_to_print(x, size, specs);
	return (len);
}

size_t				ft_print_hex_lower(va_list *arg, t_specs *specs)
{
	unsigned int	x;
	size_t			len;
	int				size;

	len = 0;
	x = va_arg(*arg, unsigned int);
	if (x == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		return (len = WIDTH);
	}
	if (x == 0)
		SHARP = 0;
	size = ft_hex_size(x);
	len += size;
	len += ft_hex_to_print(x, size, specs);
	return (len);
}
