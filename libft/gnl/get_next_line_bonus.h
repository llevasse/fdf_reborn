/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:59:20 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/21 13:35:50 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1064
# endif

char		*get_next_line(int fd);
void		fill_char(char *dst, char *src, int till_nl);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
int			is_nl(const char *str);
void		get_left_over(char *line, char *stach);
void		clear_buff(char buff[BUFFER_SIZE]);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_setzero(char *stach);
void		empty_buff(char buff[BUFFER_SIZE]);
char		*check_stach_nl(char *stach, char buff[BUFFER_SIZE + 1], int fd);
char		*stach_empty(char *stach, int fd, char buff[BUFFER_SIZE]);
char		*return_line(char *stach[OPEN_MAX], int fd);

#endif
