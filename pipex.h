/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:38:35 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/05/24 16:58:24 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int		execve(const char *filename, char *const argv[], char *const envp[]);
int		access(const char *pathname, int mode);
void	perror(const char *s);
void	section(char *fileone, char *cmd1[], char *enpv[]);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *str);
char	*ft_concante(char *dst, char *src, int *stop);
char	*get_next_line(int fd);
char	*ft_srch_backn(char *src);
char	*ft_memmove(char *dst, char *src, size_t len);
char	*ft_memcpy(char *dst, const char *src, size_t n);
char	*strmalloc(int size);

#endif
