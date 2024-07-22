/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:51:40 by ael-ouaa          #+#    #+#             */
/*   Updated: 2024/07/11 19:51:41 by ael-ouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		length_of_number_in_base(int number, int base_length);
int		length_of_string(char *string );
void	ft_putnbr_base(int nbr, char *base, char *arr, int *index);

int	is_not_valid(char *string)
{
	int	index;
	int	right_index;

	if (string[0] == '\0' || string[1] == '\0')
		return (1);
	index = 0;
	while (string[index] != '\0')
	{
		right_index = index + 1;
		while (string[right_index] != '\0')
		{
			if (string[index] == string[right_index])
				return (1);
			right_index++;
		}
		if (string[index] == '-' || string[index] == '+')
			return (1);
		if (string[index] == 32 || (9 <= string[index] && string[index] <= 13))
			return (1);
		index++;
	}
	return (0);
}

int	value_of_character_in_base(char c, char *base)
{
	int	index ;

	index = 0 ;
	while (base[index] != '\0')
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int	starting_index(char *str, int *is_negative)
{
	int	index;

	index = 0;
	*is_negative = 1;
	while (str[index] == 32 || (9 <= str[index] && str[index] <= 13))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			*is_negative *= -1;
		index++;
	}
	return (index);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_length;
	int	index;
	int	is_negative;
	int	number;
	int	exist;

	base_length = length_of_string(base);
	index = starting_index(str, &is_negative);
	number = 0;
	while (str[index] != '\0')
	{
		exist = value_of_character_in_base(str[index], base);
		if (exist == -1)
			break ;
		number = number * base_length + exist;
		index++;
	}
	return (number * is_negative);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len;
	int		number ;
	char	*string ;
	int		index ;

	if (is_not_valid(base_from) || is_not_valid(base_to))
		return (0);
	number = ft_atoi_base(nbr, base_from);
	len = length_of_number_in_base(number, length_of_string(base_to)) + 1;
	index = 0;
	string = (char *)malloc(len * sizeof(char));
	ft_putnbr_base(number, base_to, string, &index);
	string[index] = '\0';
	return (string);
}
