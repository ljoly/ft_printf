/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags_hex_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:48:30 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/07 15:18:05 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_hex_flags_right(int size, t_specs *specs)
{
	if (WIDTH > 0 && FILL_L >= 0)
		FILL_R = WIDTH - size - FILL_L;
	else
		FILL_R = 0;
	RIGHT_B = FILL_R;
}

static void		ft_absolute(t_specs *specs)
{
	LEFT_B < 0 ? LEFT_B = 0 : LEFT_B;
	LEFT_Z < 0 ? LEFT_Z = 0 : LEFT_Z;
	FILL_L += LEFT_Z + LEFT_B;
}

void			ft_hex_flags_left(int size, int precision, t_specs *specs)
{
	if (MINUS)
	{
		if (SHARP)
			FILL_L += 2;
	}
	else
	{
		if (SHARP)
		{
			FILL_L += 2;
			if (ZERO && WIDTH > size + 2)
				LEFT_Z = WIDTH - size - 2;
			else if (WIDTH > size + 2)
				LEFT_B = WIDTH - precision - size - 2;
		}
		else
		{
			if (ZERO && WIDTH > size)
				LEFT_Z = WIDTH - size;
			else if (WIDTH > size)
				LEFT_B = WIDTH - precision - size;
		}
	}
	ft_absolute(specs);
}
