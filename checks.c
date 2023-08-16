/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:38:34 by akrepkov          #+#    #+#             */
/*   Updated: 2023/08/16 14:30:23 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_argv(int argc, char **argv, t_time *timer)
{
	timer->philo = ft_atoi(argv[1]);
	if (!timer->philo || timer->philo < 1)
		return ;
	timer->to_die = ft_atoi(argv[2]); //change
	timer->to_eat = ft_atoi(argv[3]); 
	timer->to_sleep = ft_atoi(argv[4]); 
	if (!timer->to_die || !timer->to_eat || !timer->to_sleep)
		return; //add free + what if they are 0?
	if (argc == 5)
	{
		timer->amount = ft_atoi(argv[4]); 
		if(!timer->to_die)
			return ; //add free
	}
	else
		timer->amount = -1;
	printf("CHECK \n"); //delete
	printf("philo %d\n", timer->philo);
	printf("to_die %d\n", timer->to_die);
	printf("to_eat %d\n", timer->to_eat);
	printf("to_sleep %d\n", timer->to_sleep);
}

void	make_rules(t_philo *ph, t_time *timer)
{
	int	i;

	i = 0;
	while (i < timer->philo)
	{
		ph[i].thread_id = i + 1;
		ph[i].right_fork = ph[i].mutex;
		if (i == timer->philo - 1)
			ph[i].left_fork = ph[0].mutex;
		else
			ph[i].left_fork = ph[i + 1].mutex;
		i++;
	}

}

void	create_threads(t_philo *ph, t_time *timer) //something is wrong with mutex and passing arg
{
	int	i;

	i = 0;
	// t_time	*check;
	// check = ph->timer;
	// printf("Time to eat: %d\n", 1);

	// printf("Time to eat: %d\n", &(check->to_eat));
	while (i < timer->philo) //change
	{
		if (pthread_create(&ph[i].thread, NULL, &write_message, &(ph[i])) != 0) //protect
			perror("Problem with creating thread"); //not allowed to use?
		i++;
	}
	i = 0;
	while (i < timer->philo)
	{
		if (pthread_join(ph[i].thread, NULL) != 0)//protect
			perror("Problem with finishing thread");
		i++;
	}
}

void	create_mutex(t_philo *ph, t_time *timer)
{	
	int	i;

	i = 0;
	while (i < timer->philo)
	{
		ph[i].mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!ph[i].mutex)
		{
			while (i != 0) //might be leak here
			{
				free(ph[i].mutex);
				i--;
			}
			perror("Mutex"); //fix
		}
		if(pthread_mutex_init(ph[i].mutex, NULL) != 0)
			perror("Mutex"); //protect
		i++;
	}
	timer->msg_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)); //protect
}

void	destroy_mutex(t_philo *ph, t_time *timer)
{	
	int	i;

	i = 0;
	while (i < timer->philo)
	{
		pthread_mutex_destroy(ph[i].mutex);
		free(ph[i].mutex);
		i++;
	}
}