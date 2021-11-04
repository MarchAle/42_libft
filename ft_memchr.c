/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:31:56 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/04 11:20:05 by amarchal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*buffer;

	i = 0;
	buffer = s;
	while (buffer[i] && i < n)
	{
		if (buffer[i] == c)
			return ((void *)&buffer[i]);
		i++;
	}
	return (NULL);
}
