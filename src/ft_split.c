/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:25:54 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/26 20:11:09 by mnshimiy         ###   ########.fr       */
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
			return (i + 1);
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
		if (str[i] == c)
			nbc++;
		i++;
	}
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
	int		i;
	char	**tab;

	n = nbstr(str, c);
	i = 0;
	tab = malloc ((n * sizeof(char *)) + 1);
	if (!tab)
		return (NULL);
	tab[n + 1] = NULL;
	n = 0;
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
