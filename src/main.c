/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:01:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/24 20:07:04 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pathname(char *envp)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (*envp != NULL)
	{
		
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	(void) 	argc;

	(void) 	argv;

	i = 0;
	while (*envp != NULL)
	{
		i++;
		printf("\nenv var %d => %s", i, *(envp ++));
	}
}
