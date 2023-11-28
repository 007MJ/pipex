/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:01:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/20 13:22:19 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	main_pipe_close(int fd[])
{
	close(fd[0]);
	close(fd[1]);
}

int	phase2(char *arg[], char *split, char *envp[], int fd[])
{
	char	**cmd;
	char	*test;
	int		file_fd;

	file_fd = 0;
	cmd = ft_split(arg[3], ' ');
	test = test_cmd(split, arg[3]);
	if (test == NULL)
	{
		pipe_close(fd);
		free_str(cmd);
		notfound(arg[3]);
		return (-1);
	}
	file_fd = open(arg[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_fd < 0)
		perror(arg[4]);
	dup2(fd[0], 0);
	dup2(file_fd, 1);
	pipe_close(fd);
	close(file_fd);
	if (execve (test, cmd, envp) == -1)
		return (-1);
	return (1);
}

void	endphase(char *argv[], char *envp[], int fd[], int file)
{
	char	*str;
	int		pid;
	int		pid1;

	pid = 0;
	pid1 = 0;
	str = pathname(envp);
	if (file > 0)
	{
		pid = fork();
		if (pid == 0)
			phase1(argv, str, envp, fd);
		waitpid(pid, NULL, 0);
	}
	pid1 = fork();
	if (pid1 == 0)
		phase2(argv, str, envp, fd);
	main_pipe_close(fd);
	waitpid(pid1, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	file_fd;

	file_fd = 0;
	pipe(fd);
	if (argc == 5)
	{
		file_fd = open(argv[1], O_RDONLY, 0777);
		if (file_fd < 0)
		{
			perror(argv[1]);
		}
		dup2(file_fd, 0);
		close(file_fd);
		endphase(argv, envp, fd, file_fd);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		missargv(argc);
	}
	return (0);
}
