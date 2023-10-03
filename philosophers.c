/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:25:57 by akrepkov          #+#    #+#             */
/*   Updated: 2023/10/01 21:02:48 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_actions(void *ph)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)ph;
	if (philosopher->id % 2 == 1)
		usleep (philosopher->data->to_eat * 50);
	while (1)
	{
		eating(philosopher);
		if (check_dead(philosopher) != 0)
			return (NULL);
		if (philosopher->done == 0)
			return (NULL);
		sleeping(philosopher);
		if (check_dead(philosopher) != 0)
			return (NULL);
		thinking(philosopher);
		if (check_dead(philosopher) != 0)
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	struct s_data	data;

	if (argc < 5 || argc > 6)
		return (0);
	if (check_argv(argc, argv, &data) != 0)
		return (0);
	init_philosophers(&data);
	if (data.philo == 1)
	{
		printf("%lld %d has taken a fork\n", timestamp_time(&data), 1);
		my_sleep(data.to_die);
		printf("%lld %d died\n", timestamp_time(&data), 1);
		return (0);
	}
	if (create_mutex(&data) != 0)
		return (0);
	if (create_threads(&data) != 0)
		return (0);
	cleaning(&data, data.philo, 4);
	return (0);
}
