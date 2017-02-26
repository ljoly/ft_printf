/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_it_bro_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:36:47 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/12 14:33:15 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_handle_binary(va_list *arg, t_specs *specs)
{
	if (SPEC == 'b')
		return (ft_print_binary_b(arg, specs));
	else if (MOD == MOD_HH && (SPEC == 'b'))
		return (ft_print_binary_char(arg, specs));
	else if (MOD == MOD_H && (SPEC == 'b'))
		return (ft_print_binary_short(arg, specs));
	else if (MOD == MOD_L && (SPEC == 'b'))
		return (ft_print_binary_long(arg, specs));
	else if (MOD == MOD_LL && (SPEC == 'b'))
		return (ft_print_binary_long_long(arg, specs));
	return (0);
}

static size_t	ft_handle_mod_hh(va_list *arg, t_specs *specs)
{
	if (MOD == MOD_HH)
	{
		if (SPEC == 'C')
			return (ft_print_wchar(arg, specs));
		else if (SPEC == 'S')
			return (ft_print_wstr(arg, specs));
		else if (SPEC == 'd')
			return (ft_print_signed_char(arg, specs));
		else if (SPEC == 'D')
			return (ft_print_unsigned_short(arg, specs));
		else if (SPEC == 'o')
			return (ft_print_oct_char(arg, specs));
		else if (SPEC == 'O')
			return (ft_print_oct_short(arg, specs));
		else if (SPEC == 'u')
			return (ft_print_unsigned_char(arg, specs));
		else if (SPEC == 'U')
			return (ft_print_unsigned_short(arg, specs));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_char(arg, specs));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_char(arg, specs));
	}
	return (ft_handle_binary(arg, specs));
}

static size_t	ft_handle_mod_ll(va_list *arg, t_specs *specs)
{
	if (MOD == MOD_LL)
	{
		if (SPEC == 'd' || SPEC == 'D')
			return (ft_print_long_long(arg, specs));
		else if (SPEC == 'u' || SPEC == 'U')
			return (ft_print_unsigned_long_long(arg, specs));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_long_long(arg, specs));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_long_long(arg, specs));
		else if (SPEC == 'o' || SPEC == 'O')
			return (ft_print_oct_long_long(arg, specs));
	}
	return (ft_handle_mod_hh(arg, specs));
}

size_t			ft_handle_mod_z(va_list *arg, t_specs *specs)
{
	if (MOD == MOD_Z)
	{
		if (SPEC == 'd')
			return (ft_print_long_long(arg, specs));
		else if (SPEC == 'D')
			return (ft_print_unsigned_short(arg, specs));
		else if (SPEC == 'u')
			return (ft_print_unsigned_long_long(arg, specs));
		else if (SPEC == 'U')
			return (ft_print_unsigned_short(arg, specs));
		else if (SPEC == 'o')
			return (ft_print_oct_long_long(arg, specs));
		else if (SPEC == 'O')
			return (ft_print_oct_short(arg, specs));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_long_long(arg, specs));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_long_long(arg, specs));
	}
	return (ft_handle_mod_ll(arg, specs));
}
