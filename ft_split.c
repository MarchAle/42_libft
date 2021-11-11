/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:37:03 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/11 14:15:14 by amarchal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_wordnbr(char *s, char c)
{
	int	i;
	int	nbr;
	int	count;

	i = 0;
	nbr = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		else if (count > 0)
		{
			nbr++;
			count = 0;
		}
		if (!s[i + 1] && count > 0)
			nbr++;
		i++;
	}
	return (nbr);
}

char	*ft_fillword(char *s, char *tab, int i, int wordsize)
{
	int	k;

	k = 0;
	tab = ft_calloc(sizeof(char), wordsize + 1);
	if (!tab)
		return (NULL);
	while (k < wordsize)
	{
		tab[k] = s[i - wordsize + k];
		k++;
	}
	return (tab);
}

static char	**ft_filltab(char *s, char c, char **tab)
{
	int	i;
	int	j;
	int	wordsize;

	i = 0;
	j = 0;
	wordsize = 0;
	while (s[i])
	{
		if ((s[i] != c))
			wordsize++;
		else if (wordsize > 0)
		{
			tab[j] = ft_fillword(s, tab[j], i, wordsize);
			j++;
			wordsize = 0;
		}
		if (!s[i + 1] && wordsize > 0)
			tab[j] = ft_fillword(s, tab[j], i + 1, wordsize);
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = ft_calloc(sizeof(char *), ft_wordnbr((char *)s, c) + 1);
	if (!tab)
		return (NULL);
	tab = ft_filltab((char *)s, c, tab);
	return (tab);
}
