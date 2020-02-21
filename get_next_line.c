/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducas <aducas@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 13:14:09 by aducas       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 15:07:40 by aducas      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*lst_new(int fd, char *file)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (!file)
	{
		if (!(new->buffer = ft_substr("", 0, 1)))
		{
			free(new);
			return (NULL);
		}
	}
	else
		new->buffer = file;
	new->fd = fd;
	new->next = NULL;
	return (new);
}

t_list	*fd_check(t_list **str, int fd)
{
	t_list	*c_lst;

	if (!(c_lst = (*str)))
		return (((*str) = lst_new(fd, NULL)));
	while (c_lst)
	{
		if (c_lst->fd == fd)
			break ;
		else if (!(c_lst->next))
		{
			c_lst->next = lst_new(fd, NULL);
			return (c_lst->next);
		}
		(c_lst) = (c_lst)->next;
	}
	return (c_lst);
}

int		read_file(int fd, char **file)
{
	char	*str;
	int		res;
	int		ret;

	ret = 1;
	if (!(str = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if ((res = read(fd, str, BUFFER_SIZE)) == -1)
	{
		free(str);
		return (-1);
	}
	str[res] = '\0';
	if (!ft_strlen(str))
		ret = 0;
	if (!(*file = ft_strjoin(*file, str)))
	{
		free(str);
		return (-1);
	}
	free(str);
	return (ret);
}

int		del_clst(t_list **file, t_list *clst)
{
	t_list *temp;
	t_list *temp_prec;

	temp_prec = NULL;
	if ((temp = (*file)) == clst)
		(clst->next) ? (*file) = clst->next : 0;
	while (temp)
	{
		if (temp == clst)
		{
			if (temp_prec != NULL)
				temp_prec->next = temp->next;
			if (clst == (*file))
				(*file) = NULL;
			free(clst);
			clst = NULL;
			break ;
		}
		temp_prec = temp;
		temp = temp->next;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*files;
	t_list			*str;
	char			*check;
	int				i_rc;
	int				endfile;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(str = fd_check(&files, fd)))
		return (-1);
	check = NULL;
	while (!(i_rc = ft_strchr(str->buffer, '\n')))
		if ((endfile = read_file(fd, &str->buffer)) == -1)
			return (-1);
		else if (endfile == 0)
			break ;
	if ((i_rc > 0) &&
		!(check = ft_substr(str->buffer, i_rc, ft_strlen(str->buffer))))
		return (-1);
	if (cpy_line(str->buffer, line, i_rc) == -1)
		return (-1);
	free(str->buffer);
	str->buffer = check;
	return ((i_rc == 0) ? del_clst(&files, str) : 1);
}
