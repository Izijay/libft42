/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:51:26 by mdupuis           #+#    #+#             */
/*   Updated: 2020/12/08 13:14:42 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_check_sp(char c, char sep)
{
	if (c == sep)
		return (1);
	else if (c == '\0')
		return (1);
	return (0);
}

static int			ft_wordcount(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_check_sp(str[i + 1], c) == 1 && ft_check_sp(str[i], c) == 0)
			count++;
		i++;
	}
	return (count);
}

static void			ft_strcpy_sp(char *dest, char const *src, char c)
{
	int		i;

	i = 0;
	while (ft_check_sp(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void			ft_mallocword(char **tab, char const *str, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_check_sp(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_check_sp(str[i + j], c) == 0)
				j++;
			if (!(tab[count] = (char *)malloc(sizeof(char) * (j + 1))))
				return ;
			ft_strcpy_sp(tab[count], str + i, c);
			i = i + j;
			count++;
		}
	}
}

char				**ft_split(char const *str, char c)
{
	int		count;
	char	**tab;

	count = ft_wordcount(str, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[count] = 0;
	ft_mallocword(tab, str, c);
	return (tab);
}
