#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int				value;
	int				queue_num;
	struct s_data	*next;
}	t_stack;

void	swap(t_stack **stack);
void	sa(t_stack **a_stack);
void	sb(t_stack **b_stack);
void	ss(t_stack **a_stack, t_stack **b_stack);
void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **dst_a, t_stack **src_b);
void	pb(t_stack **dst_b, t_stack **src_a);
void	rotate(t_stack **stack);
void	ra(t_stack **a_stack);
void	rb(t_stack **b_stack);
void	rr(t_stack **a_stack, t_stack **b_stack);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a_stack);
void	rrb(t_stack **b_stack);
void	rrr(t_stack **a_stack, t_stack **b_stack);
void	catch_error(t_stack **stack);
#endif