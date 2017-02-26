/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:11:33 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 16:58:43 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t		ft_str_to_print(char *s, t_specs *specs)
{
	size_t			len;
	int				size;

	len = 0;
	size = (int)ft_strlen(s);
	if (IS_PRECISION)
		PRECISION < size ? (size = PRECISION) : size;
	ft_char_flags_left(size, specs);
	ft_char_flags_right(size, specs);
	len += ft_char_print_left(specs);
	len += size;
	ft_putnstr(s, size);
	len += ft_char_print_right(specs);
	return (len);
}

size_t				ft_print_str(va_list *arg, t_specs *specs)
{
	char			*s;
	size_t			len;

	len = 0;
	s = va_arg(*arg, char*);
	if (!s && !IS_PRECISION)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (!s)
		return (0);
	len = ft_str_to_print(s, specs);
	return (len);
}
