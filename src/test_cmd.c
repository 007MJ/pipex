/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:16:33 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/12 15:40:47 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*test_cmd(char *str, char	*cmd)
{
	int		i;
	char	**s1;
	char	*s2;

	i = 0;
	s1 = ft_split(str, ':');
	while (s1[i])
	{
		s2 = pathcmd(s1[i], cmd);
		if (access(s2, F_OK) == 0)
		{
			return (s2);
		}
		free (s2);
		i++;
	}
	return (NULL);
}
