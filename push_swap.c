/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:57:11 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/13 19:38:15 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	space_check(const char	*str)
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
	if (i == space)
		exit (0);
}

void	nullcheck(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
		{
			write (2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}

void free_stack(t_stack *stack)
{
    t_stack *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		len;
	int		is_sort;

	if (ac < 2)
		return (0);
	nullcheck(ac, av);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = NULL;
	*stack_b = NULL;
	create_stack(stack_a, av);
	is_sort = check_sorted(stack_a);
    if (is_sort)
    {
        free_stack(*stack_a);
        free(stack_a);
        free(stack_b);
        return (0);
    }
    len = lenstack(stack_a);
    selectsort(stack_a, stack_b, len);
    free_stack(*stack_a);
    free_stack(*stack_b);
	free(stack_a);
	free(stack_b);
}
