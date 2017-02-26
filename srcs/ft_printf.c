/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:36:14 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/06 16:07:03 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_get_specs(va_list *arg, char **frmt)
{
	char		*tmp;
	t_specs		specs;
	size_t		len;

	len = 0;
	++(*frmt);
	if (**frmt != '\0')
	{
		tmp = *frmt;
		ft_initialize_struct(&specs);
		ft_get_specifier(frmt, &specs);
		if (!specs.specifier)
			return (0);
		ft_get_flags(tmp, &specs);
		ft_get_width(tmp, &specs);
		ft_get_precision(tmp, &specs);
		if (specs.specifier != 'p')
			ft_get_modifier(tmp, &specs);
		len += ft_handle_spec(arg, &specs);
		++(*frmt);
	}
	return (len);
}

static int		ft_check(va_list *arg, const char *format)
{
	size_t		len;
	char		*frmt;
	char		*start;

	len = 0;
	frmt = (char *)format;
	start = (char *)format;
	while (*frmt)
	{
		if (*frmt == '%')
		{
			ft_putnstr(start, frmt - start);
			len += ft_get_specs(arg, &frmt);
			start = frmt;
		}
		else if (*frmt != '\0')
		{
			len++;
			frmt++;
		}
	}
	ft_putnstr(start, frmt - start);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	size_t		ret;
	va_list		arg;

	ret = 0;
	if (format)
	{
		va_start(arg, format);
		ret = ft_check(&arg, format);
		va_end(arg);
	}
	return (ret);
}
