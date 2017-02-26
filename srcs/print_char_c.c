/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:59:49 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/03 15:06:38 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_char_to_print(char c, int size, t_specs *specs)
{
	size_t		len;
	int			add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_char_flags_left(size, specs);
	ft_char_flags_right(size, specs);
	RIGHT_B -= add_precision;
	len += ft_char_print_left(specs);
	len += add_precision;
	ft_putchar(c);
	len += ft_char_print_right(specs);
	return (len);
}

size_t			ft_print_char(va_list *arg, t_specs *specs)
{
	int			c;
	size_t		len;

	len = 1;
	c = va_arg(*arg, int);
	len += ft_char_to_print(c, 1, specs);
	return (len);
}
