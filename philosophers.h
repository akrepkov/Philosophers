/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:31:43 by akrepkov          #+#    #+#             */
/*   Updated: 2023/08/16 14:24:46 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>//Header file for sleep(). man 3 sleep for details.
# include <pthread.h>//check headers

typedef struct s_time
{
	int	philo;
	int	to_die;
	int	to_eat;
	int	to_sleep;
	int	amount;
	pthread_mutex_t	*msg_mutex;

}	t_time;

typedef struct s_philo
{
	pthread_mutex_t	*mutex;
	int				thread_id;
	pthread_mutex_t				*right_fork;
	pthread_mutex_t				*left_fork;
	pthread_t		thread;
	pthread_mutex_t	*mutex_left;
	struct s_time	*timer;


}	t_philo;

void	check_argv(int argc, char **argv, t_time *timer);
void	*write_message(void *ph);
void	create_threads(t_philo *ph, t_time *timer);
void	create_mutex(t_philo *phi, t_time *timer);
int		ft_atoi(char *nptr);
void	make_rules(t_philo *ph, t_time *timer);
void	destroy_mutex(t_philo *ph, t_time *timer);

#endif
