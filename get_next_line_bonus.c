/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:57:56 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/12 17:22:55 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*get_fd(t_list **lst, int fd)
{
	t_list		*temp;
	t_list		*node;

	temp = *lst;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		else if (!temp->next)
			break ;
		temp = temp->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->content = NULL;
	node->next = NULL;
	temp->next = node;
	return (node);
}

char	*read_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr_num(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free (buffer);
			if (line)
				return (line);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		line = ft_strjoin_r((char *)line, (char *)buffer);
	}
	free(buffer);
	return (line);
}

char	*save_newline(char *line)
{
	int		i;
	char	*ans;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	ans = (char *)malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		ans[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		ans[i++] = '\n';
	ans[i] = 0;
	return (ans);
}

char	*save_oldline(char *line)
{
	int		i;
	int		j;
	int		len;
	char	*oldline;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	if (!line[i])
	{
		free (line);
		return (NULL);
	}
	oldline = (char *)malloc(sizeof(char) * (len - i) + 1);
	if (!oldline)
		return (NULL);
	while (line[i])
		oldline[j++] = line[i++];
	oldline[j] = 0;
	free (line);
	return (oldline);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*ans;
	t_list			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!lst)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		if (!lst)
			return (NULL);
		lst->fd = fd;
		lst->content = NULL;
		lst->next = NULL;
	}
	line = get_fd(&lst, fd);
	line->content = read_line(fd, line->content);
	if (!line->content)
	{
		delnode(&lst, line);
		return (NULL);
	}
	ans = save_newline(line->content);
	line->content = save_oldline(line->content);
	return (ans);
}
