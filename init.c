/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:46:36 by akrepkov          #+#    #+#             */
/*   Updated: 2023/10/01 20:23:12 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_mutex(struct s_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->msg_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->die_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->msg_mutex);
		return (-1);
	}
	if (pthread_mutex_init(&data->done_mutex, NULL) != 0)
		return (cleaning (data, i, 2));
	if (pthread_mutex_init(&data->time_mutex, NULL) != 0)
		return (cleaning (data, i, 3));
	while (i < data->philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (cleaning (data, i, 4));
		i++;
	}
	return (0);
}

int	create_threads(struct s_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo)
	{
		if (pthread_create(&data->thread[i], NULL, &start_actions,
				&data->philosopher[i]) != 0)
			return (thread_issue(data, i));
		i++;
	}
	if (pthread_create(&data->thread[i], NULL, &dead_thread, data) != 0)
		return (thread_issue(data, i));
	i = 0;
	while (i < data->philo)
	{
		if (pthread_join(data->thread[i], NULL) != 0)
			return (-1);
		i++;
	}
	if (pthread_join(data->thread[i], NULL) != 0)
		return (-1);
	return (0);
}

void	init_philosophers(struct s_data *data)
{
	int	i;

	i = 0;
	data->start_time = current_time();
	while (i < data->philo)
	{
		data->philosopher[i].id = i + 1;
		data->philosopher[i].data = data;
		data->philosopher[i].countdown = current_time();
		data->philosopher[i].done = data->done;
		data->philosopher[i].dead = data->dead;
		if (i < (data->philosopher[i].id % data->philo))
		{
			data->philosopher[i].first = i;
			data->philosopher[i].second = (i + 1) % data->philo;
		}
		else
		{
			data->philosopher[i].first = (i + 1) % data->philo;
			data->philosopher[i].second = i;
		}
		i++;
	}
}
