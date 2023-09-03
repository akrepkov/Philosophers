/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:25:57 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/03 18:53:24 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*write_message(void *ph)
{
	t_philo	*philosopher;
	int i = 10;

	philosopher = (t_philo *)ph;
	if (philosopher->id % 2 == 0)
		thinking (philosopher, philosopher->data->to_eat);
	while (philosopher->data->dead != 2 && philosopher->data->done != 0 && i > 0)
	{
		eating(philosopher);
		sleeping(philosopher);
		thinking(philosopher, 0);
		check_dead(philosopher->data);
		printf("CHECK: %d\n", philosopher->data->dead);
		philosopher->data->done--;
		i--;
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
