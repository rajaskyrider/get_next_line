/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:35:58 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/12 16:36:33 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	delnode(t_list **lst, t_list *line)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == line)
	{
		*lst = line->next;
	}
	else
	{
		while (temp->next != line)
			temp = temp->next;
		temp->next = line->next;
	}
	free(line->content);
	free(line);
	line = NULL;
}

int	ft_strchr_num(char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !(*s))
		return (1);
	while (s[i] != 0)
	{
		if (s[i] == (char) c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_copystr(char *ans, char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != 0)
		{
			ans[i] = s1[i];
			i++;
		}
		free (s1);
	}
	while (s2[j] != 0)
		ans[i++] = s2[j++];
	ans[i] = 0;
	return (ans);
}

char	*ft_strjoin_r(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	char	*ans;

	s1len = 0;
	if (s1)
		s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	ans = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ans)
		return (NULL);
	ans = ft_copystr(ans, s1, s2);
	return (ans);
}
