/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:19:03 by leolivei          #+#    #+#             */
/*   Updated: 2021/12/09 12:27:30 by leolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	nstr = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (nstr == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		nstr[i + j] = s2[j];
		j++;
	}
	nstr[i + j] = '\0';
	return (nstr);
}

char	*ft_strchr(const char *s, int c)
{
	char	lt;
	int		i;

	i = 0;
	lt = (char )c;
	while (s[i] != lt && s[i] != '\0')
		s++;
	if (s[i] != lt)
		return (0);
	return ((char *)s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (0);
		*str = '\0';
		return (str);
	}
	if (j < len)
		return (ft_strdup(s + start));
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < j && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
