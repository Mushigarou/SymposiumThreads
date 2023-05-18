#include "philosophers.h"


void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mtx);
	printf("%lu	%lu is eating\n", get_time_in_ms(philo->start), philo->philo_id);
	pthread_mutex_unlock(&philo->data->print_mtx);

	unsigned long start_time = get_time_in_ms(philo->start);
	pthread_mutex_lock(&philo->death_mtx);
	while (((get_time_in_ms(philo->start) - start_time) < philo->data->time_to_eat)
		&& (philo->dead_or_alive == 1))
	{
		pthread_mutex_unlock(&philo->death_mtx);
		usleep(100);
		pthread_mutex_lock(&philo->death_mtx);
	}
	philo->last_meal = get_time_in_ms(philo->start);
	pthread_mutex_unlock(&philo->death_mtx);

	philo->nbr_of_meals_taken += 1;
	return ;
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mtx);
	printf("%lu	%lu is sleeping\n", get_time_in_ms(philo->start), philo->philo_id);
	pthread_mutex_unlock(&philo->data->print_mtx);
	
	unsigned long	start_time = get_time_in_ms(philo->start);
	
	pthread_mutex_lock(&philo->death_mtx);
	while (((get_time_in_ms(philo->start) - start_time) < philo->data->time_to_sleep)
	&& (philo->dead_or_alive == 1))
	{
		pthread_mutex_unlock(&philo->death_mtx);
		usleep(100);
		pthread_mutex_lock(&philo->death_mtx);
	}
	pthread_mutex_unlock(&philo->death_mtx);
	return ;
}

int	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mtx);
	printf("%lu	%lu is thinking\n", get_time_in_ms(philo->start), philo->philo_id);
	pthread_mutex_unlock(&philo->data->print_mtx);

	if (philo->philo_id % 2 != 0)
		usleep(1000);
	pthread_mutex_lock(&philo->data->data_mtx);
	if (philo->prev->fork)
	{
		pthread_mutex_lock(&philo->prev->mtx);
		printf("%lu	%lu has taken a fork\n", get_time_in_ms(philo->start), philo->philo_id);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->data_mtx);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->data_mtx);

	pthread_mutex_lock(&philo->mtx);
	printf("%lu	%lu has taken a fork\n", get_time_in_ms(philo->start), philo->philo_id);

	return (0);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mtx);
	pthread_mutex_unlock(&philo->prev->mtx);
	return ;
}
