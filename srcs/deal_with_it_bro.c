/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_it_bro.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:49:42 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 16:36:39 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_handle_mod_j(va_list *arg, t_specs *specs)
{
	if (MOD == MOD_J)
	{
		if (SPEC == 'd')
			return (ft_print_intmax_t(arg, specs));
		else if (SPEC == 'D')
			return (ft_print_unsigned_short(arg, specs));
		else if (SPEC == 'o')
			return (ft_print_oct_long_long(arg, specs));
		else if (SPEC == 'O')
			return (ft_print_oct_short(arg, specs));
		else if (SPEC == 'u')
			return (ft_print_uintmax_t(arg, specs));
		else if (SPEC == 'U')
			return (ft_print_unsigned_short(arg, specs));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_long_long(arg, specs));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_long_long(arg, specs));
	}
	return (ft_handle_mod_z(arg, specs));
}

static size_t	ft_handle_mod_h(va_list *arg, t_specs *specs)
{
	if (MOD == MOD_H)
	{
		if (SPEC == 'd')
			return (ft_print_short(arg, specs));
		else if (SPEC == 'D' || SPEC == 'u')
			return (ft_print_unsigned_short(arg, specs));
		else if (SPEC == 'U')
			return (ft_print_unsigned_long(arg, specs));
		else if (SPEC == 'o')
			return (ft_print_oct_short(arg, specs));
		else if (SPEC == 'O')
			return (ft_print_oct_long(arg, specs));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_short(arg, specs));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_short(arg, specs));
	}
	return (ft_handle_mod_j(arg, specs));
}

static size_t	ft_handle_mod_l(va_list *arg, t_specs *specs)
{
	if (MOD == MOD_L || (MOD == NO_MOD && (SPEC == 'C' || SPEC == 'S' ||
					SPEC == 'D' || SPEC == 'U' || SPEC == 'O')))
	{
		if (SPEC == 'c' || SPEC == 'C')
			return (ft_print_wchar(arg, specs));
		else if (SPEC == 's' || SPEC == 'S')
			return (ft_print_wstr(arg, specs));
		else if (SPEC == 'd' || SPEC == 'D')
			return (ft_print_long(arg, specs));
		else if (SPEC == 'u' || SPEC == 'U')
			return (ft_print_unsigned_long(arg, specs));
		else if (SPEC == 'o' || SPEC == 'O')
			return (ft_print_oct_long(arg, specs));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_long(arg, specs));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_long(arg, specs));
	}
	return (ft_handle_mod_h(arg, specs));
}

size_t			ft_handle_spec(va_list *arg, t_specs *specs)
{
	SPEC == 'i' ? SPEC = 'd' : SPEC;
	if (MOD == NO_MOD)
	{
		if (SPEC == 'p')
			return (ft_print_pointer(arg, specs));
		if (SPEC == '%')
			return (ft_print_percent(specs));
		else if (SPEC == 'c')
			return (ft_print_char(arg, specs));
		else if (SPEC == 's')
			return (ft_print_str(arg, specs));
		else if (SPEC == 'd')
			return (ft_print_int(arg, specs));
		else if (SPEC == 'u')
			return (ft_print_unsigned_int(arg, specs));
		else if (SPEC == 'x')
			return (ft_print_hex_lower(arg, specs));
		else if (SPEC == 'X')
			return (ft_print_hex_upper(arg, specs));
		else if (SPEC == 'o')
			return (ft_print_oct(arg, specs));
	}
	return (ft_handle_mod_l(arg, specs));
}
