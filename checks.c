/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:38:34 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/03 19:33:18 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_argv(int argc, char **argv, struct s_data *data)
{


//****	timer->start = ft_abs_time(); //use struct timeval, 
//next gettinmeofday, after that learn about: s = time.tv_sec*1000; u = time.tv_usec/1000, return (s+u);
	data->philo = ft_atoi(argv[1]);
	if (!data->philo || data->philo < 1)
		return ;
	data->to_die = ft_atoi(argv[2]); //change
	data->to_eat = ft_atoi(argv[3]); 
	data->to_sleep = ft_atoi(argv[4]); 
	if (!data->to_die || !data->to_eat || !data->to_sleep)
		return; //add free + what if they are 0?
	if (argc == 5)
	{
		data->done = ft_atoi(argv[4]); 
		if(!data->to_die)
			return ; //add free
	}
	else
		data->done = -1;
	data->dead = 1;
}

void	check_dead(struct s_data *data) //doesn't work
{
	long long	current;
	int i;

	i = 0;
	while(i < data->philo)
	{
		current = start_time() - data->philosopher[i].countdown;
		// printf ("start_time(): %lld\n", start_time());
		// printf ("countdown: %lld\n", data->philosopher[i].countdown);
		// printf ("Current: %lld\n", current);
		// printf ("To die: %d\n", data->to_die);
		if ((int)current < data->to_die)
		{
			data->dead = 0;
			//clean everything 
			return ;
		}
		i++;
	}

	
}





	// 	ph[i].thread_id = i + 1;
	// //	(*ph)[i].last_meal = timer->start;
	// //	(*ph)[i].meals_counter = 0;
	// 	ph[i].left_fork = i;
	// 	if ((i - 1) < 0)
	// 		ph[i].right_fork = data->philo - 1;
	// 	else
	// 		ph[i].right_fork = i - 1;