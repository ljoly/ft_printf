/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:45:20 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/03 18:05:54 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_wstr_to_print(wchar_t *s, int size, t_specs *specs)
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
	ft_putwstr(s);
	len += ft_char_print_right(specs);
	return (len);
}

size_t			ft_print_wstr(va_list *arg, t_specs *specs)
{
	wchar_t		*s;
	size_t		len;
	int			size;

	len = 0;
	s = va_arg(*arg, wchar_t*);
	if (s == NULL && !IS_PRECISION)
	{
		ft_putstr("(null)");
		return (6);
	}
	size = ft_wstr_size(s);
	len += size;
	len += ft_wstr_to_print(s, size, specs);
	return (len);
}
