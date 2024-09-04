/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:19:42 by frromero          #+#    #+#             */
/*   Updated: 2024/08/17 12:32:33 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	int	number;

	if (nb < 0 && nb * -1)
	{
		ft_putchar('-');
	}
	number = nb;
	if (number < 10)
		ft_putchar(number + 48);
	else
	{
		ft_putnbr(number / 10);
		ft_putchar((number % 10) + 48);
	}
}
