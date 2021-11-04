/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:05:43 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/04 17:50:22 by amarchal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	buffer[len];

	i = 0;
	while (i < len)
	{
		buffer[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (buffer[i])
	{
		((char *)dst)[i] = buffer[i];
		i++;
	}
	return (dst);
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", ft_memmove(av[1], &av[1][atoi(av[2])], atoi(av[3]) * sizeof(char)));
	printf("%s\n", memmove(av[4], &av[4][atoi(av[5])], atoi(av[6]) * sizeof(char)));
}
