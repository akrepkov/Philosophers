/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:35:34 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/03 18:57:59 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	start_time(void)
{
	struct timeval	tv;
	//struct timeval *tv contains: tv_sec (seconds since the epoch) 
	// and tv_usec (microseconds).
	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("Problem with time"); //fix it
		return (1);
	}
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);

}

long long	timestamp_time(struct s_data *data)
{
	struct timeval	current;
	if (gettimeofday(&current, NULL) == -1)
	{
		perror("Problem with time"); //fix it
		return (1);
	}
	return (((long long)current.tv_sec * 1000 + (long long)current.tv_usec / 1000) - data->start_time);
}