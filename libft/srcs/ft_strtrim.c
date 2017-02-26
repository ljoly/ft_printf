/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:16:45 by ljoly             #+#    #+#             */
/*   Updated: 2016/11/15 11:59:16 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	int		k;
	char	*ret;

	if (!s)
		return (NULL);
	start = 0;
	k = 0;
	end = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	{
		start++;
		if (s[start] == '\0')
			k = 1;
	}
	while (k == 0 && (s[end - 1] == ' ' || s[end - 1] == '\n' ||
				s[end - 1] == '\t'))
		end--;
	ret = ft_strnew(end - start);
	if (!ret)
		return (NULL);
	return (ft_strncpy(ret, &(s)[start], end - start));
}
