/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:10:28 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/13 18:46:39 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *src);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strjoin(char *s1, char *s2);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_str_nb_base(unsigned int nb, const char *base);
void		ft_str_revert(char *str);

void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);

int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);

void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);

char		**ft_split(char const *s, char *to_skip);
char		**free_tab(char **tab);
int			skip_char(const char *s, char *to_skip, int i);

int			ft_isspace(char c);
int			ft_atoi(const char *str);
long long	ft_atoi_long_long(const char *str);

void		ft_bzero(void *s, size_t n);

void		*ft_calloc(size_t nmemb, size_t size);

char		*ft_itoa(int n);

char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_tolower(int c);
int			ft_toupper(int c);

int			ft_is_in_str(const char *str, char c);

int			get_nb_word(const char *str, char *to_skip);

#endif
