/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:19:10 by akrepkov          #+#    #+#             */
/*   Updated: 2023/10/01 21:16:33 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(t_philo *ph)
{
	write_message(ph, 1);
	if ((ph->countdown + ph->data->to_die)
		< (ph->countdown + ph->data->to_sleep))
	{
		my_sleep(ph->data->to_die);
		return ;
	}
	my_sleep(ph->data->to_sleep);
}

void	thinking(t_philo *ph)
{
	write_message(ph, 2);
	usleep (10);
}

void	eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->fork[ph->first]);
	if (check_dead(ph) == -1)
	{
		pthread_mutex_unlock(&ph->data->fork[ph->first]);
		return ;
	}
	write_message(ph, 3);
	pthread_mutex_lock(&ph->data->fork[ph->second]);
	if (check_dead(ph) == -1)
	{
		pthread_mutex_unlock(&ph->data->fork[ph->first]);
		pthread_mutex_unlock(&ph->data->fork[ph->second]);
		return ;
	}
	write_message(ph, 4);
	write_message(ph, 5);
	pthread_mutex_lock(&ph->data->time_mutex);
	ph->countdown = current_time();
	pthread_mutex_unlock(&ph->data->time_mutex);
	my_sleep(ph->data->to_eat);
	pthread_mutex_unlock(&ph->data->fork[ph->first]);
	pthread_mutex_unlock(&ph->data->fork[ph->second]);
	pthread_mutex_lock(&ph->data->done_mutex);
	ph->done--;
	pthread_mutex_unlock(&ph->data->done_mutex);
}

int	write_message(t_philo *ph, int action)
{
	pthread_mutex_lock(&ph->data->msg_mutex);
	if (action == 1)
		printf("%lld %d is sleeping\n", timestamp_time(ph->data), ph->id);
	else if (action == 2)
		printf("%lld %d is thinking\n", timestamp_time(ph->data), ph->id);
	else if (action == 3)
		printf("%lld %d has taken a fork\n", timestamp_time(ph->data), ph->id);
	else if (action == 4)
		printf("%lld %d has taken a fork\n", timestamp_time(ph->data), ph->id);
	else if (action == 5)
		printf("%lld %d is eating\n", timestamp_time(ph->data), ph->id);
	pthread_mutex_unlock(&ph->data->msg_mutex);
	return (0);
}

void	*died_message(t_philo *ph, int id)
{
	pthread_mutex_lock(&ph->data->msg_mutex);
	ph->data->dead = 0;
	if (ph->done != 0)
		printf("%lld %d died\n", timestamp_time(ph->data), id);
	pthread_mutex_unlock(&ph->data->msg_mutex);
	pthread_mutex_unlock(&ph->data->die_mutex);
	return (NULL);
}
