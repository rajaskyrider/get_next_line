/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:00:22 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/12 17:21:35 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		ft_strchr_num(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin_r(char *s1, char *s2);
void	delnode(t_list **lst, t_list *line);

#endif
