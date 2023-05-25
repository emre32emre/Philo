/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:44:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/05/25 09:21:09 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_valid(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (ft_err("Error: Number of arguments is not valid\n"));
	if (unsigned_atoi(av[1]) <= 0)
		return (ft_err("Error: Number of philosophers is not valid\n"));
	while (av[i])
	{
		if (!is_digit(av[i]))
			return (ft_err("Error: Arguments are must be digit\n"));
		i++;
	}
	return (1);
}

t_table	*parse(int ac, char **av)
{
	t_table	*table;

	if (!check_valid(ac, av))
		return (0);
	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	table->number_of_philo = unsigned_atoi(av[1]);
	table->time_to_die = unsigned_atoi(av[2]);
	table->time_to_eat = unsigned_atoi(av[3]);
	table->time_to_sleep = unsigned_atoi(av[4]);
	table->number_of_must_eat = -1;
	if (ac == 6)
		table->number_of_must_eat = unsigned_atoi(av[5]);
	table->philos = malloc(sizeof(t_philo) * table->number_of_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->number_of_philo);
	table->time = current_time();
	table->stop = 0;
	return (table);
}
