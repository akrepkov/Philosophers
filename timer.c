/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:35:34 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/09 17:08:30 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	current_time(struct s_data *data)
{
	struct timeval	tv;
	//struct timeval *tv contains: tv_sec (seconds since the epoch) 
	// and tv_usec (microseconds).
	if (gettimeofday(&tv, NULL) == -1)
	{
		cleaning(data);
	}
	//printf ("\nCurrent: %lld\n\n", (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}
// long long	my_sleep(struct s_data *data)
// {
// 	struct timeval	tv;
// }

long long	timestamp_time(struct s_data *data)
{
	struct timeval	current;
	if (gettimeofday(&current, NULL) == -1)
	{
		cleaning(data);
	}
	//printf("TIMESTAMP %lld\n\n", (long long)current.tv_sec * 1000 + ((long long)current.tv_usec / 1000) );
	return (((long long)current.tv_sec * 1000 + ((long long)current.tv_usec / 1000)) - data->start_time);
}