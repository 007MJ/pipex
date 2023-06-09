/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:25:54 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/09 15:57:08 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	tab[i] = NULL;
	free(tab);
	return (NULL);
}

int	ft_mylen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			printf("le nommbre de caractere : %d\n", i);
			return (i + 1);
		}
		i++;
	}

	return (i);
}

int	nbstr(char *str, char c)
{
	int	i;
	int	nbc;

	i = 0;
	nbc = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
			i++;
		if (str[i - 1] != c)
			nbc++;
		i++;
	}
	printf("le nombre d'espace : %d\n", nbc);
	return (nbc);
}

void	mycpy(char *dst, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	**ft_split(char *str, char c)
{
	int		n;
	int		j;
	int		i;
	char	**tab;

	n = 0;
	j = 0;
	j = nbstr(str, c) + 1;
	i = 0;
	tab = (char **)malloc ((j * sizeof(char *)));
	if (!tab)
		return (NULL);
	tab[j] = NULL;
	printf("la taille du split: %d\n", j);
	while (str[i])
	{
		tab[n] = malloc(ft_mylen(str + i, c) * sizeof(char));
		if (!tab[n])
			return (ft_free(&tab[n]));
		mycpy(tab[n], str + i, c);
		i += ft_mylen(str + i, c);
		n++;
	}
	return (tab);
}
