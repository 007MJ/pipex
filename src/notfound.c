/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notfound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:41:25 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/09 13:52:07 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	notfound(char *cmd)
{
	ft_putstr("Command not found : ");
	ft_putstr(cmd);
	ft_putstr("\n");
	exit(1);
}
