/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:38:34 by akrepkov          #+#    #+#             */
/*   Updated: 2023/07/29 16:51:10 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_memset(void *str, int n)//do you need it?
{
	char	*p;
	int		c;

	c = 1;
	p = str;
	while (n != 0)
	{
		*p = c;
		n--;
		c++;
	}
	return (str);
}

int	ft_atoi(char *nptr) //doesn't work
{
	int			i;
	long long	num;

	i = 0;
	num = 0;

	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
			num = num * 10 + nptr[i] - '0';
		if ((nptr[i] > '9' || nptr[i] < '0') && nptr[i] != '+')
			perror("Problem with numbers, check atoi"); //fix
		i++;
	}
	return (num);
}
