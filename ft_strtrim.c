/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:34:18 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/09 17:09:59 by amarchal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	*trim;

	i = 0;
	j = 0;
	start = 0;
	while (ft_isinset(s1[i], (char *)set))
		i++;
	start = i;
	if (i == ft_strlen(s1))
		return (ft_calloc(1, 1));
	while (s1[i])
		i++;
	i--;
	while (ft_isinset(s1[i], (char *)set))
		i--;
	trim = malloc(sizeof(char) * (i - start + 2));
	if (!trim)
		return (NULL);
	while (start <= i)
		trim[j++] = s1[start++];
	trim[j] = '\0';
	return (trim);
}
