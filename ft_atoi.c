/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:18:46 by mdupuis           #+#    #+#             */
/*   Updated: 2020/12/08 12:45:05 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int			neg;
	int			sig;
	long		res;

	res = 0;
	neg = 1;
	sig = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = neg * -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str++ - 48;
		if (res < 0 && neg == 1)
			sig = -1;
		else if (res < 0 && neg == -1)
			sig = 0;
	}
	return (sig = 1 ? res * neg : sig);
}
