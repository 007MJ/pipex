/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:14:34 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/20 13:22:10 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	phase1(char *ar[], char *split, char *envp[], int fd[])
{
	char	**cmd;
	char	*test;

	cmd = ft_split(ar[2], ' ');
	test = test_cmd(split, ar[2]);
	if (test == NULL)
	{
		free_str(cmd);
		notfound(ar[2]);
		return (-1);
	}
	dup2(fd[1], 1);
	pipe_close(fd);
	execve (test, cmd, envp);
	return (1);
}
