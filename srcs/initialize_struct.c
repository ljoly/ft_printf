/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:40:00 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/04 20:52:23 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_initialize_struct(t_specs *specs)
{
	SPEC = 0;
	ft_bzero(FLAGS, 7);
	WIDTH = 0;
	IS_PRECISION = 0;
	PRECISION = 0;
	MOD = NO_MOD;
	LEFT_Z = 0;
	LEFT_B = 0;
	RIGHT_B = 0;
	FILL_L = 0;
	FILL_R = 0;
	HEX_UPPER = 0;
}
