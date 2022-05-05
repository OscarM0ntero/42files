/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:26:06 by omontero          #+#    #+#             */
/*   Updated: 2022/05/04 10:14:54 by oscar            ###   ########.fr       */
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
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);

// sixth_libc.c
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s1);

// first_add.c
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(const char *s1, char const *set);

// second_add.c
char		**ft_split(char const *s, char c);

// third_add.c
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// fourth_add.c
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif
