/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:25:57 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/09 18:14:11 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_actions(void *ph)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)ph;
	if (philosopher->id % 2 == 0)
		usleep (50);
	while (philosopher->done != 0)
	{
		eating(philosopher);
		pthread_mutex_lock(&philosopher->data->die_mutex);
		check_dead(philosopher->data);
		if (philosopher->data->dead == 0)
			perror ("DEAD");
		pthread_mutex_unlock(&philosopher->data->die_mutex);
		sleeping(philosopher);
		// check_dead(philosopher->data);
		thinking(philosopher);
		// check_dead(philosopher->data);
		usleep (50);
		philosopher->done--;
	}


	return (NULL); //don't need it
}


int	main(int argc, char **argv) 
{
	struct s_data	data;

	if (argc < 5 || argc > 6)
		return (0); //what do we return?
	check_argv(argc, argv, &data);
	init_philosophers(&data);
	create_mutex(&data);
	create_threads(&data);
	cleaning(&data);
    // destroy_mutex(&ph);
    return 0;
}
/*
PLAN
- 1 philosopher
- status (dead/alive)
- timestamp
- write own sleep
- test on uneven numbers
- change perror
- add dead check and done check
- destroy and clean after death







*/
