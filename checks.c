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

void	check_argv(int argc, char **argv, t_time *timer) // try to use pointer to a struct - in main it's &timer, here **timer. In this case (*timer)->start....
{
****	timer->start = ft_abs_time(); //use struct timeval, next gettinmeofday, after that learn about: s = time.tv_sec*1000; u = time.tv_usec/1000, return (s+u);
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
****
	(*timer)->done = FALSE; //add boolian
	(*timer)->died = FALSE;

	
	printf("CHECK \n"); //delete
	printf("philo %d\n", timer->philo);
	printf("to_die %d\n", timer->to_die);
	printf("to_eat %d\n", timer->to_eat);
	printf("to_sleep %d\n", timer->to_sleep);
}

void	make_rules(t_philo *ph, t_time *timer) //**ph a pointer to s_philo struct set to NULL, *timer a pointer to an initialized s_timer struct.
{
	**** pthread_mutex_t	*fork; //?????????????????? allocate memory fork = malloc(sizeof(pthread_mutex_t) * ((size_t)data->philo_nb)); and protect
	int	i;

	i = 0;
****	while (i < timer->philo)
		pthread_mutex_init (&fork[i++], NULL); //WTF?

	i = 0;
	while (i < timer->philo)
	{
		(*ph)[i].thread_id = i + 1; // if  I use a pointer to the struct (**ph), 
		(*ph)[i].last_meal = timer->start;
		(*ph)[i].meals_counter = 0;
		(*ph)[i].left_fork = i;
		if (i - 1 < 0)
			(*philo)[i].right_fork = timer->philo - 1;
		else
			(*philo)[i].right_fork = i - 1;
		(*philo)[i].fork = fork;
		(*philo)[i].timer = timer;
		i++;
	}

}

void	create_threads(t_philo *ph, t_time *timer) //to change everything in main we need to use **
{
	int	i;

	i = 0;
**** pthread_t	*thread;
thread = malloc (sizeof (pthread_t) * (size_t)data->philo_nb); //protect
	while (i < timer->philo) //change
	{
		if (pthread_create(&thread[i], NULL, &write_message, (void *)&(ph[i])) != 0) //protect *** do I need void here?
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
****

int	ft_init_data_mutexes(t_data **data)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = malloc (sizeof (pthread_mutex_t) * ((size_t)M_NUM)); //what is M_NUM
	/*check: /* Simulator's mutexes 
	typedef enum e_mutexes
	{
		PRINT,
		MEALS,
		DONE,
		DIED,
		M_NUM
	}	t_mutexes;*/
	
	if (mutex == NULL)
		return (FAILURE);
	i = 0;
	while (i < M_NUM)
		pthread_mutex_init (&mutex[i++], NULL);
	(*timer)->mutex = mutex;
	return (SUCCESS);
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

IF WE NEED TO CHANGE - WE ADD & in calling, or * in declaration (we need pointer to do it). IF we just use info - no pointers needed (we send a copy of variable)
