/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags_oct_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:16:32 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/07 14:42:13 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_oct_print_flag(int size, t_specs *specs)
{
	size_t		len;

	len = 0;
	if (PRECISION <= size)
	{
		ft_putchar('0');
		len++;
	}
	return (len);
}

size_t			ft_oct_print_right(t_specs *specs)
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

static size_t	ft_oct_print_left_end(t_specs *specs)
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

size_t			ft_oct_print_left(int size, t_specs *specs)
{
	size_t		len;

	len = 0;
	if (SHARP)
	{
		if ((ZERO || LEFT_Z) && !MINUS)
		{
			ft_print_blanks(LEFT_B);
			len += ft_oct_print_flag(size, specs);
			ft_print_zeros(LEFT_Z);
			len += LEFT_Z + LEFT_B;
		}
		else if (MINUS)
		{
			len += ft_oct_print_flag(size, specs);
			ft_print_blanks(LEFT_B);
			len += LEFT_B;
		}
		else
		{
			ft_print_blanks(LEFT_B);
			len += ft_oct_print_flag(size, specs) + LEFT_B;
		}
	}
	return (len + ft_oct_print_left_end(specs));
}
