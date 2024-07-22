/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:51:51 by ael-ouaa          #+#    #+#             */
/*   Updated: 2024/07/11 20:39:40 by ael-ouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length_of_number_in_base(int x, int base_length)
{
	int		length;
	long	number;

	length = 0;
	number = (long)x;
	if (number < 0)
	{
		length++;
		number = -number;
	}
	while (number > 0)
	{
		length++;
		number /= base_length;
	}
	if (length == 0)
		length = 1;
	return (length);
}

int	length_of_string(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}

void	ft_putnbr_base(int nbr, char *base, char *arr, int *index)
{
	int	base_length;

	base_length = length_of_string(base);
	if (nbr == -2147483648)
	{
		arr[*index] = '-';
		(*index)++;
		ft_putnbr_base(-(nbr / base_length), base, arr, index);
		arr[*index] = base[-(nbr % base_length)];
		(*index)++;
		return ;
	}
	if (nbr < 0)
	{
		arr[*index] = '-';
		(*index)++;
		nbr *= -1;
		ft_putnbr_base(nbr, base, arr, index);
		return ;
	}
	if (nbr >= base_length)
		ft_putnbr_base(nbr / base_length, base, arr, index);
	arr[*index] = base[nbr % base_length];
	(*index)++;
}
