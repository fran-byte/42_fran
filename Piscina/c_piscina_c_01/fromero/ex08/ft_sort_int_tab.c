/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:41:38 by frromero          #+#    #+#             */
/*   Updated: 2024/08/10 12:54:20 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int current;
	int i;
	int temp;

	current = 0;
	while (current <= size)
	{
		i = 0;
		while (i <= size)
		{
			if (tab[i] > tab[current])
			{
				temp = tab[current];
				tab[current] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		current++;
	}
}