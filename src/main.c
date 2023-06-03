/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:01:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/03 14:11:05 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*str;
	int		id;
	int		file_fd;

	id = 0;
	file_fd = 0;
	if (argc == 3)
	{
		str = pathname(envp);
		id = fork();
		if (id == 0)
		{
			file_fd = open(argv[1], O_RDONLY);
			if (file_fd < 0)
				perror(argv[1]);
			dup2(file_fd, 0);
			execve ((const char *)test_cmd(str, argv[2]), argv + 2, envp);
		}
	}
	else
		printf("Programme Done!");
}
