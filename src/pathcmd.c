/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:22:41 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/09 14:42:04 by mnshimiy         ###   ########.fr       */
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
	while ((s2[n] != ' ') && s2[n])
	{
		str[i] = s2[n];
		i++;
		n++;
	}
	str[i] = '\0';
}

char	*pathcmd(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = 0;
	len = ft_strlen(s1);
	str = malloc (sizeof(char *) * (len + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	copystr(str, s1, s2);
	return (str);
}
