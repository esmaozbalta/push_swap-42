/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:15:04 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/12 19:28:31 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int				value;
	int				index;
	struct s_data	*next;
}	t_stack;

void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **dst_a, t_stack **src_b);
void	pb(t_stack **dst_b, t_stack **src_a);

void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	nullcheck(int ac, char **av);
void	catch_error(t_stack **stack);

void	space_check(const char	*str);

void	split_node(t_stack **stack_a, char *av);
void	create_stack(t_stack **stack_a, char **av);
int		check_sorted(t_stack **stack_a);
void	set_neg(t_stack **stack_a);
int		lenstack(t_stack **stack_a);

t_stack	*find_min2(t_stack	**stack_a);
void	index_setter(t_stack	**stack_a);
void	radixbin(t_stack	**stack_a, t_stack	**stack_b);

void	selectsort(t_stack **stack_a, t_stack **stack_b, int len);
int		find_min(t_stack	**stack_a);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack	**stack_a, t_stack **stack_b);
void	sort_5(t_stack	**stack_a, t_stack	**stack_b);

int		ft_atoi(const char *str);
int		ft_isdigit(int n);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int n);
int		ft_lstsize(t_stack *lst);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t max);
size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
#endif