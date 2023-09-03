/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:31:43 by akrepkov          #+#    #+#             */
/*   Updated: 2023/09/03 19:23:05 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> //Header file for sleep(). man 3 sleep for details.
# include <pthread.h> //check headers
# include <sys/time.h> // for gettimeofday



typedef struct s_philo
{
	int id;
	long long	countdown;
	struct s_data *data;

}	t_philo;



struct s_data
{
	int	philo;
	int	to_die;
	int	to_eat;
	int	to_sleep;
	int done;
	int dead;
	long long	start_time;
	long long	current_time;
	pthread_mutex_t	fork[201];
	pthread_t		thread[201];
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t die_mutex;
	t_philo	philosopher[201];
	//start; //read about EPOCH and The elapsed time since EPOCH in millisecond.
};




void	check_argv(int argc, char **argv, struct s_data *data);
void	create_mutex(struct s_data *data);
// void	make_rules(t_main *ph,  struct s_data *data);
// void	create_mutex(t_time **timer);
int		ft_atoi(char *nptr);
void	create_threads(struct s_data *data);
void	*write_message(void *ph);
void	destroy_mutex(struct s_data *data);
void	sleeping(t_philo *ph);
void	thinking(t_philo *ph, int time);
void	eating(t_philo *ph);
long long	start_time(void);
long long	timestamp_time(struct s_data *data);
void	init_philosophers(struct s_data *data);
void	check_dead(struct s_data *data);

#endif


// 	/*check:  mutexes 
// 	typedef enum e_mutexes
// 	{
// 		PRINT,
// 		MEALS,
// 		DONE,
// 		DIED,
// 		M_NUM
// 	}	t_mutexes;*/