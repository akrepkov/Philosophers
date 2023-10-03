/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:38:34 by akrepkov          #+#    #+#             */
/*   Updated: 2023/10/03 07:27:19 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_argv(int argc, char **argv, struct s_data *data)
{
	data->philo = ft_atoi(argv[1]);
	data->to_die = ft_atoi(argv[2]);
	data->to_eat = ft_atoi(argv[3]);
	data->to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->done = ft_atoi(argv[5]);
		if (data->done < 1)
			return (printf("Wrong input\n"));
	}
	else
		data->done = -1;
	if (data->philo < 1 || data->philo > 200 || data->to_die < 1
		|| data->to_eat < 1 || data->to_sleep < 1)
		return (printf("Wrong input\n"));
	data->dead = 1;
	return (0);
}

void	*dead_thread(void *val)
{
	struct s_data	*data;
	long long		current;
	int				i;

	data = (struct s_data *) val;
	while (data->done != 0 && data->dead != 0)
	{
		i = 0;
		while (i < data->philo)
		{
			pthread_mutex_lock(&data->time_mutex);
			current = current_time() - data->philosopher[i].countdown;
			pthread_mutex_unlock(&data->time_mutex);
			pthread_mutex_lock(&data->die_mutex);
			if (current > data->to_die)
			{
				died_message(data->philosopher, data->philosopher[i].id);
				return (NULL);
			}
			i++;
			pthread_mutex_unlock(&data->die_mutex);
		}
		usleep (10);
	}
	return (NULL);
}

int	check_dead(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->data->die_mutex);
	if (philosopher->data->dead == 0)
	{
		pthread_mutex_unlock(&philosopher->data->die_mutex);
		return (-1);
	}
	pthread_mutex_unlock(&philosopher->data->die_mutex);
	return (0);
}
