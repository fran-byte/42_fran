/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:41:59 by frromero          #+#    #+#             */
/*   Updated: 2024/08/07 10:47:29 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_is_negative(int n)
{
	char n;
	char s;

	n = 'N';
	s = 'S';
	if (n < 0)
	{
		write(1, &N, 1);
	}
	else
	{
		write(1, &S, 1);
	}
}