/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:23:40 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/09 17:50:56 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	cleaning(struct s_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo)
	{
		if (pthread_join(data->thread[i], NULL) != 0)
			perror("Join");
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
	exit(0); //not allowed
}

void	thread_issue(struct s_data *data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_join(data->thread[i], NULL) != 0)
			perror("Join");
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
	exit(0); //not allowed
}



void	write_message(t_philo *ph, int action)
{
	if (action == 1)
		printf("%lld PH: %d is sleeping\n", timestamp_time(ph->data), ph->id);
	if (action == 2)
		printf("%lld PH: %d is thinking\n", timestamp_time(ph->data), ph->id);
	if (action == 3)
		printf("%d took a fork\n", ph->id);
	if (action == 4)
		printf("%d took the second fork\n", ph->id);
	if (action == 5)
		printf("%lld PH: %d is eating\n", timestamp_time(ph->data), ph->id);	
}