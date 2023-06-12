/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:22:41 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/12 15:31:44 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	copystr(char *str, char *s1, char *slash, char *s2)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	n = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (slash[j])
	{
		str[i] = slash[j];
		i++;
		j++;
	}
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
	char	*slash;
	int		len;

	len = 0;
	str = NULL;
	slash = "/";
	len = ft_strlen(s1);
	str = malloc (sizeof(char *) * (len + ft_strlen(s2) + 5));
	if (!str)
		return (NULL);
	copystr(str, s1, slash, s2);
	return (str);
}
