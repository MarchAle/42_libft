/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:37:03 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/07 16:41:48 by amarchal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_wordnbr(char *s, char c)
{
	int	i;
	int	nbr;

	i = 1;
	nbr = 1;
	if (s[0] == c)
		nbr--;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			nbr++;
		i++;
	}
	return (nbr);
}

void	ft_fillword(char *s, char *tab, int i, int wordsize)
{
	int	k;

	k = 0;
	while (k < wordsize)
	{
		tab[k] = s[i + k];
		k++;
	}
	tab[k] = '\0';
}

char	**ft_filltab(char *s, char c, char **tab)
{
	int	i;
	int	j;
	int	wordsize;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			wordsize = 0;
			while (s[i + wordsize] != c)
				wordsize++;
			tab[j] = malloc(sizeof(char) * (wordsize + 1));
			if (!tab[j])
				return (NULL);
			ft_fillword(s, tab[j], i, wordsize);
			j++;
			i += wordsize;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_wordnbr((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	tab = ft_filltab((char *)s, c, tab);
	return (tab);
}
