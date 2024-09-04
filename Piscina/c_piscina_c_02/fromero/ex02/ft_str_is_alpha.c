/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:09:54 by frromero          #+#    #+#             */
/*   Updated: 2024/08/11 17:54:11 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (str[0] != '\0')
	{
		if ((str[0] < 97 || str[0] > 122) && (str[0] < 65 || str[0] > 90))
			return (0);
		str++;
	}
	return (1);
}