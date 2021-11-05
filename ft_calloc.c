/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:16:11 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/05 17:24:26 by amarchal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
		printf("%d - i = %zu\n", *buff, i);
	}
	return (buff);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	int	i;
	int *mycalloc = ft_calloc(atoi(av[1]), atoi(av[2]));
	int *thecalloc = calloc(atoi(av[1]), atoi(av[2]));

	i = 0;
	printf("ft_calloc \n");
	while (i < (atoi(av[1]) * atoi(av[2])))
	{
		printf("%d\n", mycalloc[i]);
		i++;
	}
	i = 0;
	printf("calloc \n");
	while (i < (atoi(av[1]) * atoi(av[2])))
	{
		printf("%d\n", thecalloc[i]);
		i++;
	}
}
