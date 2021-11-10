/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:37:03 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/10 18:17:16 by amarchal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_wordnbr(char *s, char c)
{
	int	i;
	int	nbr;
	int	count;

	i = 0;
	nbr = 1;
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
		tab[k] = s[i - wordsize + k];
		k++;
	}
	tab[k] = '\0';
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
		else if (wordsize > 0 || !s[i + 1])
		{
			tab[j] = ft_calloc(sizeof(char), wordsize + 1);
			if (!tab[j])
				return (NULL);
			ft_fillword(s, tab[j], i, wordsize);
			j++;
		//	i += (wordsize - 1);
			wordsize = 0;
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

	if (s == NULL)
		return (NULL);
	i = 0;
	tab = ft_calloc(sizeof(char *), ft_wordnbr((char *)s, c) + 1);
	if (!tab)
		return (NULL);
	tab = ft_filltab((char *)s, c, tab);
	return (tab);
}

int	main(int ac, char **av)
{
	(void)ac;
	int	i;
	char **test;
	i = 0;
	test = ft_split(av[1], av[2][0]);
	while (test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
}
