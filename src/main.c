/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:01:21 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/12 14:06:33 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipe_close(int fd[], int file)
{
	close(fd[0]);
	close(fd[1]);
	close(file);
}

void	phase1(char *ar[], char *split, char *envp[], int fd[])
{
	char	**cmd;
	char	*test;
	int		file_fd;

	file_fd = 0;
	cmd = ft_split(ar[2], ' ');
	test = test_cmd(split, ar[2]);
	file_fd = open(ar[1], O_RDONLY, 0777);
	if (file_fd < 0)
	{
		perror(ar[1]);
		pipe_close(fd, file_fd);
		exit(1);
	}
	if (test == NULL)
	{
		notfound(ar[2]);
		free(test);
	}
	dup2(file_fd, 0);
	dup2(fd[1], 1);
	pipe_close(fd, file_fd);
	if (execve (test, cmd, envp) == -1)
		exit(1);
}

void	phase2(char *arg[], char *split, char *envp[], int fd[])
{
	char	**cmd;
	char	*test;
	int		file_fd;

	file_fd = 0;
	cmd = ft_split(arg[3], ' ');
	test = test_cmd(split, arg[3]);
	if (test == NULL)
	{
		notfound(arg[3]);
		exit(1);
	}
	file_fd = open(arg[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_fd < 0)
		perror(arg[4]);
	dup2(fd[0], 0);
	dup2(file_fd, 1);
	pipe_close(fd, file_fd);
	if (execve (test, cmd, envp) == -1)
		exit(1);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*str;
	int		pid;
	int		pid1;
	int		fd[2];

	pid = 0;
	pid1 = 0;
	pipe(fd);
	if (argc == 5)
	{
		str = pathname(envp);
		pid = fork();
		if (pid == 0)
			phase1(argv, str, envp, fd);
		waitpid(pid, NULL, 0);
		pid1 = fork ();
		if (pid1 == 0)
			phase2(argv, str, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
	}
	else
		missargv(argc);
}
