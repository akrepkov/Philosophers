/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:25:57 by akrepkov          #+#    #+#             */
/*   Updated: 2023/08/16 14:30:43 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*write_message(void *ph)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)ph;
	// t_time	*timer;
	// timer = philosopher->timer;
	// printf("WRITE CHECK\n");
	//if (forks are available) - > ph is eating;
    pthread_mutex_lock(philosopher->right_fork); //here should be fork mutex
    printf("Philosopher %d has taken a fork\n", philosopher->thread_id); //how to send exact id?
    // printf("Philosopher %d has taken a fork!\n", philosophers->left_fork); 
	pthread_mutex_lock(philosopher->left_fork); //here should be fork mutex
    printf("Philosopher %d has taken a fork\n", philosopher->thread_id); //how to send exact id?

	// usleep(philosophers->timer.to_eat);
	pthread_mutex_lock(&(timer->msg_mutex));
	printf("Philosopher %d is eating\n", timer->to_eat);
	pthread_mutex_unlock(&(timer->msg_mutex));

	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
    // Exit the thread ?
    // pthread_exit(NULL);

**** if (philosopher->thread_id % 2 == 0)
	{
	printf("Philosopher %d is thinking\n", timer->thread_id);
	usleep **********;
}
	while (1)
	{
		if (ft_check_died(philosopher)) ->lock mutex[died], check philosopher->timer->died, unlock mutex[died] and return boolian
			break ;
		if (ft_eating (philosopher) != SUCCESS) -> Here we have functions:
		//1. start eating - > mutex_lock &philosopher->fork[ft_min R, L]; after that ft_max
			//print - taken a fork;
		//2. lock mutex[meals];
		//philosopher->last_meal = ft_abs_time;
		//meals_counter++;
		//3. ft_check_done - the same as died;
		//4. finish_eating - unlock forks
			// print - is sleeping
			// sleep 
			break ;
		printf("Philosopher %d is thinking\n", timer->thread_id);
		usleep **********;
	}
	return (NULL); //don't need it
}


int	main(int argc, char **argv) 
{
	t_philo	*ph; //why *?
	t_time	*timer;
	// pthread_mutex_t *mutex;

****	timer = NULL;
****	ph = NULL:
	if (argc < 5 || argc > 6)
		return (0); //what do we return?
	timer = (t_time *)malloc(sizeof(t_time)); //free
	if (!timer)
		perror("Problem in timer");
	check_argv(argc, argv, timer);
	ph = (t_philo *)malloc(sizeof(t_philo) * timer->philo);
	//ph->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!ph)
		perror("Problem in ph"); //add free if needed
	create_mutex(ph, timer);
	make_rules(ph, timer);

	// Initialize the mutex
	// pthread_mutex_init(ph->mutex, NULL);
	create_threads(ph, timer);// using & lets you give the function the ability to modify the original variables and not just copies of them.
****	//thats's why we need to pass &ph and &timer

    // // Destroy the mutex
    destroy_mutex(ph, timer);
	// free(threads);
	// free(ph->mutex);
	// free(ph);
    return 0;
}
/*
PLAN
- 1 philosopher
- status (dead/alive)
- timestamp
- write own sleep
- test on uneven numbers






*/
