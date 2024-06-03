/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:33:21 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/25 17:34:25 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return ((size_t) NULL);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}