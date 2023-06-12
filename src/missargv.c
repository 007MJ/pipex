/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missargv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:28:05 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/12 15:40:23 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	missargv(int argc)
{
	if (argc > 5)
		write(1, "Error : Too many arguments\n", 28);
	else
		write(1, "Error : not enough arguments\n", 30);
	exit(1);
}
