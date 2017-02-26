/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:25:45 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/07 14:16:47 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_oct_size(size_t o)
{
	int				size;

	size = 1;
	while (o >= 8)
	{
		o /= 8;
		size++;
	}
	return (size);
}

static size_t		ft_oct_to_print(unsigned int o, int size, t_specs *specs)
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
	ft_print_octal(o);
	len += ft_oct_print_right(specs);
	return (len);
}

size_t				ft_print_oct(va_list *arg, t_specs *specs)
{
	unsigned int	o;
	size_t			len;
	int				size;

	len = 0;
	o = va_arg(*arg, unsigned int);
	if (o == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		if (SHARP)
		{
			ft_putchar('0');
			len++;
		}
		return (len + WIDTH);
	}
	if (o == 0)
		SHARP = 0;
	size = ft_oct_size(o);
	len += size;
	len += ft_oct_to_print(o, size, specs);
	return (len);
}
