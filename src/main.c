/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:01:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/26 20:16:32 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*pathname(char *envp[])
{
	int	n;

	n = 0;
	while (envp[n] != NULL)
	{
		if ((ft_strncmp("PATH=", envp[n], ft_strlen("PATH="))) == 0)
		{
			return (envp[n]);
		}
		n++;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	(void) 	argc;
	(void) 	argv;
	printf("%s", ft_stilsame("PATH=", pathname(envp)));
	
}
