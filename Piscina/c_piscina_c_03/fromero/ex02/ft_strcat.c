/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:10:32 by frromero          #+#    #+#             */
/*   Updated: 2024/08/13 12:18:10 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *src, char *dest)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	while (dest[j] != '\0')
	{
		src[i + j] = dest[j];
		j++;
	}
	src[i + j] = '\0';
	return (src);
}