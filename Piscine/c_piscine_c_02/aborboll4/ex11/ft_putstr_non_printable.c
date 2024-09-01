/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:31:44 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/12 12:38:41 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	to_hex(char a)
{
	char	*abc;

	abc = "0123456789abcdef";
	if (a > 16)
	{
		to_hex(a / 16);
		to_hex(a % 16);
	}
	else
	{
		ft_putchar(abc[(int)a]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] >= '~')
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			to_hex(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
