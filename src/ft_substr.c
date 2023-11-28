/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:16:53 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/20 12:21:57 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*ptr;

	i = 0;
	if (start < ft_strlen((char *)s))
		while (i < len && s[start + i])
				i++;
	ptr = malloc((i + 1) * sizeof(*s));
	if (!ptr)
		return (ptr);
	i = 0;
	if (start <= ft_strlen((char *)s))
	{
		while (s[start] != '\0' && i < len)
		{
			ptr[i] = s[start];
			start++;
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
