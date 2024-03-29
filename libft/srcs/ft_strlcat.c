/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:22:09 by ljoly             #+#    #+#             */
/*   Updated: 2016/11/19 11:26:30 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*cpy_dst;
	const char		*cpy_src;
	size_t			i;
	size_t			len;

	i = size;
	cpy_dst = dst;
	cpy_src = src;
	while (i-- && *cpy_dst)
		cpy_dst++;
	len = cpy_dst - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen((char *)cpy_src));
	while (*cpy_src)
	{
		if (i != 1)
		{
			*cpy_dst++ = *cpy_src;
			--i;
		}
		cpy_src++;
	}
	*cpy_dst = '\0';
	return (len + (cpy_src - src));
}
