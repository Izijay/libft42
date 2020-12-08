/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:18:46 by mdupuis           #+#    #+#             */
/*   Updated: 2020/12/08 18:26:15 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_atoi(const char *str, int *i)
{
	int	sig;
	int	neg;

	sig = 0;
	neg = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		*i = *i + 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sig++;
			neg++;
		}
		else if (str[*i] == '+')
			sig++;
		*i = *i + 1;
	}
	if (sig > 1)
		return (-1);
	if (neg == 1)
		return (1);
	else
		return (666);
}

int		ft_atoi(const char *str)
{
	long	res;
	int		chk;
	int		i;

	i = 0;
	res = 0;
	chk = ft_check_atoi(str, &i);
	str += i;
	if (chk == -1)
		return (0);
	while (*str && (*str >= '0' && *str <= '9'))
		res = res * 10 + *str++ - 48;
	if (chk == 1)
		res = -res;
	return (res);
}

