/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:35:34 by akrepkov          #+#    #+#             */
/*   Updated: 2023/10/01 18:21:59 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}

long long	time_diff(long long start, long long now)
{
	return (now - start);
}

void	my_sleep(int sleep_time)
{
	long long	timer;

	timer = current_time();
	while (1)
	{
		if (time_diff(timer, current_time()) >= sleep_time)
			break ;
		usleep(100);
	}
}

long long	timestamp_time(struct s_data *data)
{
	struct timeval	c;

	gettimeofday(&c, NULL);
	return (((long long)c.tv_sec * 1000 + ((long long)c.tv_usec / 1000))
		- data->start_time);
}
