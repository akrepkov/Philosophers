/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:31:43 by akrepkov          #+#    #+#             */
/*   Updated: 2023/10/01 19:03:10 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				done;
	int				dead;
	long long		countdown;
	int				first;
	int				second;
	struct s_data	*data;

}	t_philo;

struct s_data
{
	int				philo;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				done;
	int				dead;
	long long		start_time;
	pthread_mutex_t	fork[200];
	pthread_t		thread[201];
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	done_mutex;
	t_philo			philosopher[200];

};

int			check_argv(int argc, char **argv, struct s_data *data);
int			create_mutex(struct s_data *data);
int			ft_atoi(char *nptr);
int			create_threads(struct s_data *data);
void		*start_actions(void *ph);
void		sleeping(t_philo *ph);
void		thinking(t_philo *ph);
void		eating(t_philo *ph);
long long	current_time(void);
long long	timestamp_time(struct s_data *data);
void		init_philosophers(struct s_data *data);
void		*dead_thread(void *val);
int			cleaning(struct s_data *data, int max, int mutex);
int			write_message(t_philo *ph, int action);
int			thread_issue(struct s_data *data, int count);
void		my_sleep(int sleep_time);
int			check_dead(t_philo *philosopher);
void		*died_message(t_philo *ph, int id);
long long	time_diff(long long start, long long now);

#endif
