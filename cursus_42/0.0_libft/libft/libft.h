/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:26:06 by omontero          #+#    #+#             */
/*   Updated: 2022/04/26 11:27:46 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>

// first_libc.c
int			ft_isalpha(int n);
int			ft_isdigit(int n);
int			ft_isalnum(int n);
int			ft_isascii(int n);
int			ft_isprintf(int n);

// second_libc.c
size_t		ft_strlen(const char *s);
void		*ft_memset(void *p, int n, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t len);
void		*ft_memmove(void *dest, const void *src, size_t len);

// third_libc.c
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlcat(char *dest, char *src, size_t nb);
int			ft_toupper(int c);
int			ft_tolower(int c);

// fourth_libc.c
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);

// fifth_libc.c
static int	ft_check_little(char *p, const char *little, const size_t len);
char		*ft_strnstr(const char *big, const char *little, size_t len);
static int	ft_neg(int num, int x);
int			ft_atoi(const char *nptr);

// sixth_libc.c
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s1);

#endif