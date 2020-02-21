/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducas <aducas@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 13:21:24 by aducas       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 15:52:51 by aducas      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int				fd;
	char			*buffer;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char const *s2);
int				ft_strchr(const char *s, int c);
int				cpy_line(char *buffer, char **line, int index);
int				get_next_line(int fd, char **line);
#endif
