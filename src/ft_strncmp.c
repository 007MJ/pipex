/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:09:35 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/24 20:44:29 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../pipex.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
		i++;
	}
	if (s2[i] == '\0' || i == n)
	{
		return (0);
	}
	else
		return (s1[i] - s2[i]);
}
