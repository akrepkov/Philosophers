/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:19:10 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/03 19:33:44 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->msg_mutex); 
	printf("CHECK BEFORE: %lld %d is sleeping\n", timestamp_time(ph->data), ph->id); //replace timestamp
	usleep(ph->data->to_sleep * 100); //How does usleep work?
	printf("CHECK AFTER USLEEP %lld %d is sleeping\n", timestamp_time(ph->data), ph->id);
	pthread_mutex_unlock(&ph->data->msg_mutex);
}

void	thinking(t_philo *ph, int time)
{
	pthread_mutex_lock(&ph->data->msg_mutex);
	printf("%lld %d is thinking\n", timestamp_time(ph->data), ph->id);
	usleep(time);
	pthread_mutex_unlock(&ph->data->msg_mutex);

}

void	eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->msg_mutex);
	printf("%lld %d is eating\n", timestamp_time(ph->data), ph->id);
	usleep(ph->data->to_eat);
	ph->countdown = start_time(); //fix
	pthread_mutex_unlock(&ph->data->msg_mutex);
}