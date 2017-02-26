/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags_hex_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:49:07 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 19:58:17 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_hex_print_flag(t_specs *specs)
{
	size_t		len;

	len = 0;
	if (HEX_UPPER)
	{
		ft_putstr("0X");
		len += 2;
	}
	else
	{
		ft_putstr("0x");
		len += 2;
	}
	return (len);
}

size_t			ft_hex_print_right(t_specs *specs)
{
	size_t		len;

	len = 0;
	if (RIGHT_B > 0)
	{
		ft_print_blanks(RIGHT_B);
		len += RIGHT_B;
	}
	return (len);
}

static size_t	ft_hex_print_left_end(t_specs *specs)
{
	size_t		len;

	len = 0;
	if (!SHARP && LEFT_B > 0)
	{
		ft_print_blanks(LEFT_B);
		len += LEFT_B;
	}
	if (!SHARP && LEFT_Z > 0)
	{
		ft_print_zeros(LEFT_Z);
		len += LEFT_Z;
	}
	return (len);
}

size_t			ft_hex_print_left(t_specs *specs)
{
	size_t		len;

	len = 0;
	if (SHARP)
	{
		if ((ZERO || LEFT_Z) && !MINUS)
		{
			ft_print_blanks(LEFT_B);
			len += ft_hex_print_flag(specs);
			ft_print_zeros(LEFT_Z);
			len += LEFT_Z + LEFT_B;
		}
		else if (MINUS)
		{
			len += ft_hex_print_flag(specs);
			ft_print_blanks(LEFT_B);
			len += LEFT_B;
		}
		else
		{
			ft_print_blanks(LEFT_B);
			len += ft_hex_print_flag(specs) + LEFT_B;
		}
	}
	return (len + ft_hex_print_left_end(specs));
}
