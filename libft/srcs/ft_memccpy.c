/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:52:47 by ljoly             #+#    #+#             */
/*   Updated: 2016/11/08 17:52:51 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] != (unsigned char)c)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		else
		{
			((unsigned char *)dst)[i] = (unsigned char)c;
			i++;
			return (&((unsigned char *)dst)[i]);
		}
		i++;
	}
	return (NULL);
}
