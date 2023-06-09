/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missargv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:28:05 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/09 14:15:22 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	missargv(int argc)
{
	if (argc > 5)
		write(1, "Error : Too many argument\n", 27);
	else
		write(1, "Error : not enough argument\n", 29);
	exit(1);
}
