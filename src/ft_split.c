/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:25:54 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/12 13:16:09 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	**ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static int	nbrworld(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
			i++;
		if (str[i -1] != c)
			word++;
	}
	return (word);
}

static char	**mysplit(char **section, char const *s, char c)
{
	int	i;
	int	star;
	int	len;

	i = 0;
	star = 0;
	len = 0;
	while (s[i] && len < nbrworld(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		star = i;
		while (s[i] != c && s[i])
			i++;
		section[len] = ft_substr(s, star, i - star);
		if (!section[len])
			return (ft_free(section));
		len++;
	}
	section[len] = 0;
	return (section);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	split = malloc (sizeof(char *) * (nbrworld(s, c) + 1));
	if (!split)
		return (NULL);
	return (mysplit(split, s, c));
}
