/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 02:41:14 by tebetta           #+#    #+#             */
/*   Updated: 2020/02/24 02:45:25 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_get_nb_line(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char			*ft_get_line(char *line, char **stock)
{
	char		*tmp;

	if (ft_strchr(*stock, '\n'))
	{
		if (!(line = ft_substr(*stock, 0, ft_get_nb_line(*stock))))
			return (NULL);
		tmp = *stock;
		if (!(*stock = ft_substr(tmp, ft_get_nb_line(tmp) + 1, ft_strlen(tmp))))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(line = ft_strdup(*stock)))
			return (NULL);
		free(*stock);
		*stock = NULL;
	}
	return (line);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	static char	*stock = NULL;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	ret = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!(ft_strchr(stock, '\n')) && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = stock;
		stock = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (ret == -1)
		return (-1);
	if (!(*line = ft_get_line(*line, &stock)))
		return (-1);
	return ((!stock && !ret) ? 0 : 1);
}
