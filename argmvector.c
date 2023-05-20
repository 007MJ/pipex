/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argmvector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:51:35 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/20 17:26:17 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char	*argument(char *str[], int argcnum)
{
	char	*strmalloc;
	int		n;
	int		i;
	int		len;

	n = 0;
	len = 0;
	while (n < argcnum)
	{
		len = strlenght(str, argcnum);
		i = 0;
		strmalloc = malloc (len * sizeof(char *) + 1);
		while (str[n][i] != '\0')
		{
			strmalloc[i] = str[n][i];
			i++;
		}
		n++;
	}
	return (strmalloc);
}
