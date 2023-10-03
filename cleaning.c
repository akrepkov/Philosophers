/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:23:40 by akrepkov          #+#    #+#             */
/*   Updated: 2023/10/01 18:31:22 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	cleaning(struct s_data *data, int max, int mutex)
{
	int	i;

	i = 0;
	while (i < max)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	if (mutex > 1)
	{
		pthread_mutex_destroy(&data->msg_mutex);
		pthread_mutex_destroy(&data->die_mutex);
	}
	if (mutex > 2)
		pthread_mutex_destroy(&data->time_mutex);
	if (mutex > 3)
		pthread_mutex_destroy(&data->done_mutex);
	return (-1);
}

int	thread_issue(struct s_data *data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_join(data->thread[i], NULL) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < data->philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->msg_mutex);
	pthread_mutex_destroy(&data->die_mutex);
	pthread_mutex_destroy(&data->time_mutex);
	pthread_mutex_destroy(&data->done_mutex);
	return (-1);
}
