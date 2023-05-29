/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acces.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:22:41 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/29 16:49:25 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	copystr(char *str, char *s1, char *s2)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] += '/';
	i++;
	while (s2[n] != ' ')
	{
		str[i] = s2[n];
		i++;
		n++;
	}
}

const char	*ft_access(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = 0;
	len = ft_strlen(s1);
	str = malloc (len + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	copystr(str, s1, s2);
	return (str);
}


