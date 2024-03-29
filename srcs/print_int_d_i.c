/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:16:29 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 16:44:24 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_int_size(ssize_t nb)
{
	int				size;

	size = 1;
	if (nb == ft_power(-2, 63))
		return (19);
	if (nb < 0)
		nb *= -1;
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static size_t		ft_int_to_print(ssize_t i, int nb, int size,
		t_specs *specs)
{
	size_t			len;
	int				add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_int_flags_left(nb, size, add_precision, specs);
	ft_int_flags_right(size, specs);
	LEFT_Z += add_precision;
	RIGHT_B -= add_precision;
	len += ft_int_print_left(nb, specs);
	if (i == ft_power(2, 31) || i == ft_power(-2, 31))
		ft_putstr("2147483648");
	else
		(nb < 0) ? ft_putnbr_sst(-nb) : ft_putnbr_sst(nb);
	len += ft_int_print_right(specs);
	return (len);
}

size_t				ft_print_int(va_list *arg, t_specs *specs)
{
	int				nb;
	ssize_t			i;
	int				size;
	size_t			len;

	len = 0;
	i = va_arg(*arg, ssize_t);
	nb = (int)i;
	if (nb == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		return (len = WIDTH);
	}
	size = ft_int_size(nb);
	len += size;
	len += ft_int_to_print(i, nb, size, specs);
	return (len);
}
