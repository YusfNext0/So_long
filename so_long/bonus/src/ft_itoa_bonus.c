/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:19:17 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/25 17:34:11 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	c_num( int n)
{
	int	count;

	count = 1;
	while (n / 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*p;
	int				count;
	unsigned int	nb;

	count = c_num(n);
	if (n < 0)
	{
		nb = -n;
		count++;
	}
	else
		nb = n;
	p = malloc(count + 1);
	if (!p)
		return (NULL);
	p[count] = '\0';
	count--;
	while (count >= 0)
	{
		p[count--] = (nb % 10) + 48;
		nb = (nb / 10);
	}
	if (n < 0)
		p[0] = '-';
	return (p);
}
