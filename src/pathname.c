/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:04:20 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/12 15:05:22 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*pathname(char *envp[])
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (envp[n])
	{
		if ((ft_strncmp("PATH=", envp[n], ft_strlen("PATH="))) == 0)
		{
			return (ft_stilsame("PATH=", envp[n]));
		}
		n++;
	}
	return (NULL);
}



