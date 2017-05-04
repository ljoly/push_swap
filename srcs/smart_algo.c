/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:51:47 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/04 21:28:20 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*static void		move(t_stack *env, int start, int end, int op)
{
	I = start - 1;
	while (++I <= end)
	{
		do_op(env, op);
		send_op(env, op);
	}
}*/

static int		next_target(int *st, int len, int target)
{
	int			i;
	int			j;

	i = -1;
	j = len;
	while (++i < len && --j > i)
	{
		if (st[i] < target)
			return (i);
		else if (st[j] < target)
			return (j);
	}
	return (-1);
}

static void		use_b(t_stack *env)
{
	int			op;

	op = 0;
	if (!(I = next_target(A, LEN_A, MED)) && (op = PB)) // SI IS_SORT(A) ON ARRETE PB
		do_op(env, PB);
	else if (LEN_B > 1 && A[0] > A[1] && B[0] < B[1] && (op = SS))
		do_op(env, SS);
	else if (I > -1 && I <= MED_RANK && LEN_B > 1 && B[0] < B[LEN_B - 1])
		do_op(env, RR);
	else if (I > MED_RANK && LEN_B > 1 && B[0] < B[LEN_B - 1])
		do_op(env, RRR);
	else if ((LEN_B > 1 && B[0] < B[1] && B[0] < A[LEN_B - 1] &&
			   	B[0] - B[1] > B[LEN_B - 1]) && (op = SB))
		do_op(env, SB);
	else if ((I == 1 || (A[0] > A[1] && A[0] > A[LEN_A - 1] &&
					A[0] - A[1] < A[0] - A[LEN_A - 1])) && (op = SA))
		do_op(env, SA);
	else if (I > -1 && I <= MED_RANK && (op = RA))
		do_op(env, RA);
		//move(env, 0, I, RA);
	else if (((I > -1 && I > MED_RANK) || A[0] > A[LEN_A - 1]) && (op = RRA))
		do_op(env, RRA);
		//move(env, I, LEN_A, RRA);
	else if (LEN_B > 1 && B[0] > B[1] && B[0] > B[LEN_B - 1] &&
			B[0] - B[1] < B[0] - B[LEN_B - 1] && (op = RB))
		do_op(env, RB);
	else if (((LEN_B > 1 && B[0] > B[1] && B[0] > B[LEN_B - 1] &&
					B[0] - B[1] > B[0] - B[LEN_B - 1]) ||
				(LEN_B > 1 && B[0] > B[1] && B[0] < B[LEN_B - 1])) && (op = RRB))
		do_op(env, RRB);
	//	op ? store_op(env, op, 0) : (op = 1) ;
	if (op)
		send_op(env, op);
}

void		smart_push_swap(t_stack *env)
{
//	int		min;

	if (LEN_A > 3)
	{
		while (LEN_B < MED_RANK - 1 || !is_sort(B, LEN_B, 0, 0))
		{
			(LEN_B < MED_RANK - 1) ? ft_putendl("LEN_B < MED_RANK") : ft_putendl("!is_sort");
			use_b(env);
		}
	}
	idiot_push_swap(env);
	while (LEN_B > 0)
	{
		do_op(env, PA);
//		store_op(env, PA, 0);
		send_op(env, PA);
	}
}