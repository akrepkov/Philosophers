/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:19:10 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/09 18:13:49 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->msg_mutex); 
	// printf("CHECK BEFORE: %lld %d is sleeping\n", timestamp_time(ph->data), ph->id); //replace timestamp
	write_message(ph, 1);
	pthread_mutex_unlock(&ph->data->msg_mutex);
	usleep(ph->data->to_sleep * 1000); //How does usleep work?
	// printf("CHECK AFTER USLEEP %lld %d is sleeping\n", timestamp_time(ph->data), ph->id);
}

void	thinking(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->msg_mutex);
	write_message(ph, 2);
	pthread_mutex_unlock(&ph->data->msg_mutex);
	usleep(50); //*10 - wrong
}

void	eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->fork[ph->id - 1]);
	pthread_mutex_lock(&ph->data->fork[ph->id % ph->data->philo]);//wrong
	pthread_mutex_lock(&ph->data->msg_mutex);
//	ph->countdown = current_time(ph->data); //fix
	write_message(ph, 3);
	write_message(ph, 4);
	write_message(ph, 5);
	usleep(ph->data->to_eat * 1000);
	//printf ("\n\ncountdown after eating: %lld\n\n", ph->countdown);
	pthread_mutex_unlock(&ph->data->msg_mutex);
	pthread_mutex_unlock(&ph->data->fork[ph->id - 1]);
	pthread_mutex_unlock(&ph->data->fork[ph->id % ph->data->philo]);

}
