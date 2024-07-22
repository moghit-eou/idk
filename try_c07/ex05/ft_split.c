/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:54:36 by ael-ouaa          #+#    #+#             */
/*   Updated: 2024/07/13 11:09:02 by ael-ouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	border(char c, char *sep)
{
	int	index;

	index = 0;
	while (sep[index] != '\0')
	{
		if (c == sep[index])
			return (1);
		index++;
	}
	return (0);
}

int	number_of_words(char *str, char *sep)
{
	int	counter;
	int	index;
	int	word;

	counter = 0;
	index = 0;
	word = 0;
	while (str[index] != '\0')
	{
		if (border(str[index], sep))
		{
			counter += word;
			word = 0;
			index++;
			continue ;
		}
		word = 1;
		index++;
	}
	counter += word;
	return (counter + 1);
}

int	check_and_fill(char *str, char *sep, int *index, char **arr_element)
{
	int	start;
	int	end;
	int	word_index;

	start = *index;
	end = *index;
	while (str[end + 1] != '\0' && !border(str[end + 1], sep))
		end++;
	*arr_element = (char *)malloc((end - start + 2) * sizeof(char));
	if (arr_element == 0)
		return (1);
	word_index = 0;
	while (*index <= end)
	{
		(*arr_element)[word_index] = str[*index];
		(*index)++;
		word_index++;
	}
	return (0);
}

char	**ft_split(char *str, char *charset) 
{
	char	**arr;
	int		index;
	int		word;


	index = 0;
	word = 0;
	arr = (char **)malloc(number_of_words(str, charset) * sizeof(char *));
	if (arr == 0)
		return (0);
	while (str[index] != '\0')
	{
		if (border(str[index], charset))
		{
			index++;
			continue ;
		}
		if (check_and_fill(str, charset, &index, &arr[word]))
			return (0);
		word++;
	}
	arr[word] = 0;
	return (arr);
}


#include <stdio.h>
#define print_int(x) printf("%s = %d\n" , #x , x) ;
#define print_string(string) printf("%s = %s\n" , #string , string ) ; 
#define print_char(c) printf("%s = %c\n" , #c , c ) ; 
#define new_line printf("\n") ;
int main()
{


    int x = 10 ; 
    char *string = "     |+Hello My+" ; 
    char *charset = "+" ; 
    char ** arr = ft_split(string , charset) ; 

    for ( int i =  0 ; arr[i] ; i++ ) 
    {
    	print_string( arr[i] ) ; 
    }

    new_line
    new_line;








	return 0 ; 
}
