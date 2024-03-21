/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:15:43 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/12 15:55:02 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

char	*get_next_line(int fd);
int		ft_strchr_num(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin_r(char *s1, char *s2);
void	*ft_setzero(char *s, int n);

#endif
