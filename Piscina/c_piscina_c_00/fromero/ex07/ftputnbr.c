/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftputnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:59:54 by frromero          #+#    #+#             */
/*   Updated: 2024/08/07 10:49:21 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char a)
{
	write(1, &a, 1);
}

void ft_putnbr(int n)
{
	int number;

	if (n < 0 && n * -1)
	{
		ft_putchar('-');
	}
	number = n;
	if (number < 10)
		ft_putchar(number + 48);
	else
	{
		ft_putnbr(number / 10);
		ft_putchar((number % 10) + 48);
	}
}