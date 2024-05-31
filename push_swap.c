#include "push_swap.h"

void	space_check(const	char	*str)
{
	size_t	space;
	size_t	i;

	space = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	if (i == space) //dizinin icinde sadece bosluk var ise program sonlanir
		exit (0);
}

int	main(int ac, char **av)
{
	t_stack **stack_a;
	t_stack	**stack_b;
	int		len;
	int		is_sort;

	if (ac < 2)
		return (0);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = NULL;
	*stack_b = NULL;
	create_stack(stack_a, av);
	is_sort = check_sorted(stack_a);
	if (is_sort)
		return (0);
	set_que(stack_a);
	len = lenstack(stack_a);
	selectsort(stack_a, stack_b, len);
	return (0);
}