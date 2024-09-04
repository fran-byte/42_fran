/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:50:46 by frromero          #+#    #+#             */
/*   Updated: 2024/08/10 13:20:06 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp[size];
	int start;
	int end;
	int current;

	start = 0;
	end = size;
	while (start <= size)
	{
		temp[start] = tab[end];
		end--;
		start++;
	}
	tab = temp;
}
