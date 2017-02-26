/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags_oct_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:11:18 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/12 14:27:15 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_oct_flags_right(int size, t_specs *specs)
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

void			ft_oct_flags_left(int size, int precision, t_specs *specs)
{
	if (MINUS)
	{
		if (SHARP)
			FILL_L += 1;
	}
	else
	{
		if (SHARP)
		{
			FILL_L += 1;
			if (ZERO && WIDTH > size + 1)
				LEFT_Z = WIDTH - size - 1;
			else if (WIDTH > size + 1)
				LEFT_B = WIDTH - precision - size - 1;
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
