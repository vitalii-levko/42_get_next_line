/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 20:51:51 by vlevko            #+#    #+#             */
/*   Updated: 2018/03/25 14:42:56 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_free(char **s1, char **s2, char **s3, int ret)
{
	if (s1)
		ft_strdel(s1);
	if (s2)
		ft_strdel(s2);
	if (s3)
		ft_strdel(s3);
	return (ret);
}

int	gnl_init(int fd, int *ret, t_gnl **curr, t_gnl **gnl)
{
	while (*curr != NULL && (*curr)->fd != fd)
		*curr = (*curr)->next;
	if (*curr == NULL)
	{
		*curr = (t_gnl *)malloc(sizeof(t_gnl));
		(*curr)->fd = fd;
		(*curr)->buff = NULL;
		(*curr)->next = NULL;
		(*curr)->res = NULL;
		(*curr)->str = NULL;
		if (*gnl)
			(*curr)->next = *gnl;
		*gnl = *curr;
	}
	if ((*curr)->buff == NULL)
	{
		if (!((*curr)->buff = ft_strnew(BUFF_SIZE)))
			return (-1);
		if ((*ret = read((*curr)->fd, (*curr)->buff, BUFF_SIZE)) == -1)
			return (gnl_free(&((*curr)->buff), NULL, NULL, -1));
	}
	else
		*ret = ft_strlen((*curr)->buff);
	return (0);
}

int	gnl_br(int i, int ret, t_gnl *curr, char *temp)
{
	if (curr->res == NULL)
	{
		if (!(curr->res = ft_strsub(curr->buff, 0, i - 1)))
			return (gnl_free(&(curr->buff), NULL, NULL, -1));
	}
	else
	{
		if (!(curr->str = ft_strsub(curr->buff, 0, i - 1)))
			return (gnl_free(&(curr->buff), NULL, NULL, -1));
		temp = curr->res;
		if (!(curr->res = ft_strjoin(temp, curr->str)))
			return (gnl_free(&temp, &(curr->str), &(curr->buff), -1));
		gnl_free(&(curr->str), &temp, NULL, 0);
	}
	if (i < ret)
	{
		temp = curr->buff;
		if (!(curr->buff = ft_strsub(temp, i, ret - i)))
			return (gnl_free(&(curr->buff), &temp, NULL, -1));
		ft_strdel(&temp);
	}
	else
		ft_strdel(&(curr->buff));
	return (0);
}

int	gnl_nobr(int *i, int *ret, t_gnl *curr, char *temp)
{
	if (*i == *ret)
	{
		if (curr->res == NULL)
		{
			if (!(curr->res = ft_strdup(curr->buff)))
				return (gnl_free(&(curr->buff), NULL, NULL, -1));
		}
		else
		{
			temp = curr->res;
			if (!(curr->res = ft_strjoin(temp, curr->buff)))
				return (gnl_free(&temp, &(curr->buff), NULL, -1));
		}
		gnl_free(&(curr->buff), &temp, NULL, 0);
		if (!(curr->buff = ft_strnew(BUFF_SIZE)))
			return (gnl_free(&(curr->res), NULL, NULL, -1));
		if ((*ret = read(curr->fd, curr->buff, BUFF_SIZE)) == -1)
			return (gnl_free(&(curr->buff), &(curr->res), NULL, -1));
		*i = 0;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	int				i;
	int				ret;
	t_gnl			*curr;
	static t_gnl	*gnl = NULL;

	curr = gnl;
	if (BUFF_SIZE <= 0 || fd < 0 || fd >= 1000000 || line == NULL || \
		(i = gnl_init(fd, &ret, &curr, &gnl)) == -1)
		return (-1);
	if (ret == 0)
		return (gnl_free(&(curr->buff), NULL, NULL, 0));
	while (i < ret && curr->buff[i] != '\0')
		if (curr->buff[i++] == '\n')
		{
			if (gnl_br(i, ret, curr, NULL) || !(*line = ft_strdup(curr->res)))
				return (gnl_free(&(curr->buff), &(curr->res), NULL, -1));
			return (gnl_free(&(curr->res), NULL, NULL, 1));
		}
		else if (gnl_nobr(&i, &ret, curr, NULL) == -1)
			return (-1);
	if (curr->res == NULL)
		return (gnl_free(&(curr->buff), NULL, NULL, 0));
	if (!(*line = ft_strdup(curr->res)))
		return (gnl_free(&(curr->buff), &(curr->res), NULL, -1));
	return (gnl_free(&(curr->res), NULL, NULL, 1));
}
