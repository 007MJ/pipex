/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:01:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/29 16:54:59 by mnshimiy         ###   ########.fr       */
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
			return (ft_stilsame("PATH=", envp[n]));
		}
		n++;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	(void) 	argc;
	(void) 	argv;
	// char *str = pathname(envp);
	// printf("%s\n", str);
	char **str = ft_split (pathname(envp),':');
	int n;

	n = 0;
	while (str[n])
	{
		if (access("../main.c", F_OK) == 0)
		{
			printf("work!");
		}
		else
			printf("shit don't work !\n");
		//printf("%s\n", str[n]);
		n++;
	}
}
