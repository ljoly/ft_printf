/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:29:33 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/02 11:41:48 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		ft_uint_print_right(t_specs *specs)
{
	size_t	len;

	len = 0;
	if (RIGHT_B > 0)
	{
		ft_print_blanks(RIGHT_B);
		len += RIGHT_B;
	}
	return (len);
}

size_t		ft_uint_print_left(t_specs *specs)
{
	size_t	len;

	len = 0;
	if (LEFT_B > 0)
	{
		ft_print_blanks(LEFT_B);
		len += LEFT_B;
	}
	if (LEFT_Z > 0)
	{
		len += LEFT_Z;
		ft_print_zeros(LEFT_Z);
	}
	return (len);
}

void		ft_uint_flags_right(int size, t_specs *specs)
{
	if (WIDTH > 0 && FILL_L >= 0)
		FILL_R = WIDTH - size - FILL_L;
	else
		FILL_R = 0;
	RIGHT_B = FILL_R;
}

void		ft_uint_flags_left(int size, int precision, t_specs *specs)
{
	if (!MINUS)
	{
		if (ZERO && WIDTH && !IS_PRECISION)
			LEFT_Z = WIDTH - size;
		else if (WIDTH)
			LEFT_B = WIDTH - precision - size;
	}
	FILL_L += LEFT_Z + LEFT_B;
}
