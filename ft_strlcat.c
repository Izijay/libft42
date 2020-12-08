/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:56:42 by mdupuis           #+#    #+#             */
/*   Updated: 2020/12/08 03:12:19 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, char *src, size_t size)
{
	char		*sr;
	char		*de;
	size_t		len;

	de = dest;
	sr = src;
	while (size != 0 && *de)
	{
		--size;
		++de;
	}
	len = de - dest;
	if (size == 0)
		return (len + ft_strlen(sr));
	while (*sr)
	{
		if (size != 1)
		{
			++de = sr;
			--size;
		}
		sr++;
	}
	*de = '\0';
	return (len + (sr - src));
}
