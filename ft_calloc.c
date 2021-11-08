/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:16:11 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/08 18:10:39 by amarchal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*buff;
	size_t	i;

	i = count * size;
	buff = malloc(i);
	if (!buff)
		return (NULL);
	while (i > 0)
	{
		*buff++ = 0;
		i--;
	}
	return (buff);
}
