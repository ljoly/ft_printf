/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:03:15 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/03 18:06:31 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wchar_size(wchar_t c)
{
	size_t		len;

	len = 0;
	if (c <= 127)
		len = 1;
	else if (c <= 2047)
		len = 2;
	else if (c <= 65535)
		len = 3;
	else if (c <= 1114111)
		len = 4;
	return (len);
}