/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:51:31 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/23 18:04:16 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	section(char *fileone, char *cmd1)
{
	int	fileonefd;
	cmd1 = NULL;
	fileonefd = 0;
	if (access(fileone, F_OK) == -1)
		perror(fileone);
	else
	{
		fileonefd = open(fileone, O_RDONLY);
	}
	return (1);
}
