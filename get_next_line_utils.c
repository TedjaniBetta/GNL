/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:49:19 by tebetta           #+#    #+#             */
/*   Updated: 2020/03/09 17:49:22 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	char		*str;
	size_t		i;
	size_t		len;

	i = 0;
	if (!s)
	{
		if (!(str = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	len = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		dest[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] && s2)
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	if (!s)
		return (NULL);
	if (!len || (unsigned int)ft_strlen(s) < start)
	{
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
