/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:52:26 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/22 19:23:52 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	size(char *file[], int n)
{
	int	i;

	i = 0;
	while (file[n][i] != '\0')
		i++;
	return (n);
}

char	*fileargv(char *file[], int n)
{
	int		i;
	char	*fil;
	int		len;

	len = size(file, n);
	fil = malloc (len * sizeof(char *) + 1);
	i = 0;
	while (file[n][i])
	{
		fil[i] = file[n][i];
		i++;
	}
	fil[i] = '\0';
	return (fil);
}

int	main(int argc, char *argv[])
{
	char	*fileone;
	char	*cmd1;
	char	*cmd2;
	char	*filetwo;

	fileone = NULL;
	cmd1 = NULL;
	cmd2 = NULL;
	filetwo = NULL;
	if (argc <= 5)
	{
		fileone = fileargv(argv, 1);
		cmd1 = fileargv(argv, 2);
		cmd2 = fileargv(argv, 3);
		filetwo = fileargv(argv, 4);
		
	}
	else
		printf("shit don't work !");

}
