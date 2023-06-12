/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:38:35 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/06/12 15:30:12 by mnshimiy         ###   ########.fr       */
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

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_stilsame(char *s1, char *s2);
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, int start, int len);
void	copystr(char *str, char *s1, char *slash, char *s2);

char	*pathcmd(char *s1, char *s2);
char	*pathname(char *envp[]);
char	*test_cmd(char *str, char	*cmd);
void	missargv(int argc);
void	notfound(char *cmd);

#endif
