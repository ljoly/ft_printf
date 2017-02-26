/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:03:57 by ljoly             #+#    #+#             */
/*   Updated: 2016/11/15 13:38:43 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_w(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
			i++;
		else if (s[i] == c)
		{
			n++;
			while (s[i] == c)
				i++;
		}
	}
	if (s[i] == '\0' && s[i - 1] != c)
		n++;
	return (n);
}

static int	ft_count_chr(char const *s, char c, int pos)
{
	int		len;

	len = 0;
	while (s[pos] != c)
	{
		pos++;
		len++;
	}
	return (len);
}

static int	copy_and_return_pos(char *ret, char const *s, int size_w, int pos)
{
	int		i;

	i = 0;
	while (i < size_w)
	{
		ret[i] = s[pos];
		i++;
		pos++;
	}
	ret[i] = '\0';
	return (pos);
}

static int	check_pos(char const *s, int pos, char c)
{
	while (s[pos] == c)
		pos++;
	return (pos);
}

char		**ft_strsplit(char const *s, char c)
{
	int		pos;
	int		w;
	int		size_ret;
	int		size_w;
	char	**ret;

	if (!s)
		return (NULL);
	size_ret = ft_count_w(s, c);
	ret = (char**)malloc(sizeof(char*) * (size_ret + 1));
	if (!ret)
		return (NULL);
	pos = 0;
	pos = check_pos(s, pos, c);
	w = 0;
	while (w < size_ret)
	{
		size_w = ft_count_chr(s, c, pos);
		ret[w] = (char*)malloc(sizeof(char) * (size_w + 1));
		pos = copy_and_return_pos(ret[w], s, size_w, pos);
		pos = check_pos(s, pos, c);
		w++;
	}
	ret[w] = 0;
	return (ret);
}
