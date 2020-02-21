/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducas <aducas@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:36:07 by aducas       #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2020/01/21 15:52:44 by aducas      ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2020/01/21 15:08:07 by aducas      ###    #+. /#+    ###.fr     */
>>>>>>> 1a947a225d24a88017be82611b2c9fc9b1149696
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] == c)
			return (i + 1);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	sizes1;
	size_t	sizes2;
	size_t	i;

	if (s1 == 0 && s2 != 0)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (s2 == 0 && s1 != 0)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	if ((s1 == 0 && s2 == 0) ||
			!(ptr = malloc((sizes1 + sizes2 + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < sizes1)
		ptr[i] = s1[i];
	i = -1;
	while (++i < sizes2)
		ptr[i + sizes1] = s2[i];
	ptr[sizes2 + sizes1] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	maxsize;

	i = -1;
	if (s == 0)
		return (NULL);
	maxsize = (start >= ft_strlen(s)) ? 0 : len;
	if (!(substr = malloc((maxsize + 1) * sizeof(char))))
		return (NULL);
	while (++i < maxsize && s[start + i])
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int		cpy_line(char *str, char **line, int i_rc)
{
	if (i_rc > 0)
		(*line) = ft_substr(str, 0, i_rc - 1);
	else
		(*line) = ft_substr(str, 0, ft_strlen(str));
	if (!(*line))
		return (-1);
	return (0);
}
