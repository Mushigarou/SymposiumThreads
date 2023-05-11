#include "philosophers.h"

void	clear_list(t_philo *head, int list_size)
{
	t_philo	*tmp;

	if (!head || list_size == 0)
		return ;
	while (list_size)
	{
		tmp = head;
		head = head->next;
		free(tmp);
		list_size--;
	}
	return ;
}
