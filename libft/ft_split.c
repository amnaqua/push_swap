/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:49:33 by naqua             #+#    #+#             */
/*   Updated: 2022/01/22 12:50:13 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

int	ft_wordmalloc(char const *s, char **mass)
{
	int	lenword;
	int	i;

	i = 0;
	while (*s)
	{
		lenword = 0;
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
			{
				s++;
				lenword++;
			}
			mass[i++] = (char *)malloc(sizeof(char) * (lenword + 1));
			if (!mass)
				return (i);
		}
		else
			s++;
	}
	return (0);
}

void	ft_rewriting(char const *s, char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				arr[i][j++] = *s++;
			arr[i++][j] = '\0';
		}
		j = 0;
		if (*s != '\0')
			s++;
	}
}

char	**ft_split(char const *s, int word)
{
	char	**arr;
	int		res;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	if (!arr)
		exit(1);
	arr[word] = NULL;
	res = ft_wordmalloc(s, arr);
	if (res == 0)
		ft_rewriting(s, arr);
	else
	{
		while (res != 0)
		{
			free(arr[res]);
			arr[res--] = NULL;
		}
		free(arr);
	}
	return (arr);
}
