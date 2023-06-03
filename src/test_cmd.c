/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:16:33 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/02 21:51:19 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*test_cmd(char *str, char	*cmd)
{
	int		i;
	char	**s1;

	i = 0;
	s1 = ft_split(str, ':');
	while (s1[i])
	{
		if (access(pathcmd(s1[i], cmd), F_OK) == 0)
		{
			return ((char *)pathcmd(s1[i], cmd));
		}
		i++;
	}
	return (NULL);
}
