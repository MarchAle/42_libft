/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:40:47 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/03 13:21:18 by amarchal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static unsigned int	ft_str_len(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_size;
	size_t	dest_size;

	i = 0;
	j = 0;
	src_size = ft_str_len(src);
	dest_size = ft_str_len(dest);
	if (dstsize == 0 || dstsize < dest_size)
		return (src_size + dstsize);
	if (src_size == 0)
		return (dest_size);
	while (dest[i])
	{
		i++;
	}
	while (src[j] && dest_size + j < dstsize - 1)
	{
		dest[dest_size + j] = src[j];
		j++;
	}
	dest[dest_size + j] = '\0';
	return (src_size + dest_size);
}
