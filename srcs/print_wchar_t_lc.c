/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t_lc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:58:14 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 17:03:10 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_wchar_to_print(wchar_t c, int size, t_specs *specs)
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
	ft_putwchar(c);
	len += ft_char_print_right(specs);
	return (len);
}

size_t			ft_print_wchar(va_list *arg, t_specs *specs)
{
	wchar_t		c;
	size_t		len;
	int			size;

	len = 0;
	c = va_arg(*arg, wchar_t);
	size = ft_wchar_size(c);
	len += size;
	len += ft_wchar_to_print(c, size, specs);
	return (len);
}
