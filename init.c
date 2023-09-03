/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:46:36 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/03 18:53:18 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	create_mutex(struct s_data *data)
{
	int	i;

	i = 0;
	if(pthread_mutex_init(&data->msg_mutex, NULL) != 0) // destroy mutexes if there are problrms
		perror("Mutex");
	if(pthread_mutex_init(&data->die_mutex, NULL) != 0)// destroy mutexes if there are problrms
		perror("Mutex");
	while (i < data->philo)
	{
		if(pthread_mutex_init(&data->fork[i], NULL) != 0)// destroy mutexes if there are problrms
			perror("Mutex"); //protect
		i++;
	}
}

void	create_threads(struct s_data *data)
{
	int	i;

	i = 0;
	data->start_time = start_time();
	while (i < data->philo && data->dead != 0) //change
	{

		if (pthread_create(&data->thread[i], NULL, &write_message, &data->philosopher[i]) != 0) //protect *** do I need void here?
			perror("Problem with creating thread"); //not allowed to use?
		i++;
	}
		i = 0;
	while (i < data->philo)
	{
		if (pthread_join(data->thread[i], NULL) != 0)//protect
			perror("Problem with finishing thread");
		i++;
	}
}

void	init_philosophers(struct s_data *data)
{
	int i;


	i = 0;

	while (i < data->philo)
	{
		data->philosopher[i].id = i + 1;
		data->philosopher[i].data = data;
		data->philosopher->countdown = 0;
		i++;
	}
}