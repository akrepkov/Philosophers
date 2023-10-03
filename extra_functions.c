/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:38:34 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/16 15:54:14 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *nptr)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	if (!nptr)
		return (-1);
	if (nptr[0] == '+')
		i++;
	while (nptr[i])
	{
		if (nptr[i] > '9' || nptr[i] < '0')
			return (-1);
		if (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
			num = num * 10 + nptr[i] - '0';
		else
			return (-1);
		i++;
	}
	return (num);
}
