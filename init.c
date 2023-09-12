/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:46:36 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/09 18:11:11 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_mutex(struct s_data *data)
{
	int	i;

	i = 0;
	if(pthread_mutex_init(&data->msg_mutex, NULL) != 0) // destroy mutexes if there are problrms
		return ;
	if(pthread_mutex_init(&data->die_mutex, NULL) != 0)// destroy mutexes if there are problrms
		pthread_mutex_destroy(&data->msg_mutex);
	while (i < data->philo)
	{
		if(pthread_mutex_init(&data->fork[i], NULL) != 0)// destroy mutexes if there are problrms
			{
				pthread_mutex_destroy(&data->msg_mutex);
				pthread_mutex_destroy(&data->die_mutex);
				while (i >= 0)
					pthread_mutex_destroy(&data->fork[i--]);
				break ;
			}
		i++;
	}
}

int	create_threads(struct s_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo) //change
	{

		if (pthread_create(&data->thread[i], NULL, &start_actions, &data->philosopher[i]) != 0) //protect *** do I need void here?
		{
			thread_issue(data, i); // add i, to do the join thing
		// thinking(data->philosopher[i]);
			//return (printf ("Error with threads"));
			return (1);
		}
		usleep (10);
		i++;
	}
	i = 0;
	while (i < data->philo)
	{
		if (pthread_join(data->thread[i], NULL) != 0)
			perror("Join");
		i++;
	}
	if (pthread_create(&data->thread[i], NULL, &check_dead, &data) != 0)
	{
		cleaning(data);
		return (1);
	}
	return (0);
}

void	init_philosophers(struct s_data *data)
{
	int i;


	i = 0;
	data->start_time = current_time(data);
	while (i < data->philo)
	{
		data->philosopher[i].id = i + 1;
		data->philosopher[i].data = data;
		data->philosopher[i].countdown = data->start_time;
		//data->philosopher[i].done = data->done;
		data->philosopher[i].done = 5; //change
		i++;
	}
}