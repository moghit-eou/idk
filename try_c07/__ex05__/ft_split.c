/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:54:36 by ael-ouaa          #+#    #+#             */
/*   Updated: 2024/07/12 22:15:53 by ael-ouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>


int border(char c , char *sep ) 
{	
	int index;
	
	index = 0 ;  
	while ( sep[index] != '\0' ) 
	{	
		if ( c == sep[index] ) 
			return 1 ;
		index++;
	}
	return 0 ; 
}

int number_of_words(char *str, char * sep)
{		
	int counter   ; 
	int index ; 
	int word  ; 

	counter = 0 ; 
	index = 0 ; 
	word = 0 ;
	while ( str[index] != '\0' ) 
	{
		if ( border(str[index] , sep ) )
		{
			counter += word ; 
			word =0  ; 
			index++ ; 
			continue;
		}
		word = 1 ; 
		index++ ; 
	}
	counter += word ; 
	return counter + 1; 
}

void	end_of_word(char *str, char *sep, int index, int *start, int *end) 
{	
	*start = index ; 
	while ( str[index + 1] != '\0' && !border(str[index + 1] , sep ) )
		index++ ; 

	*end = index ; 
}
void	fill_string(int left, int right, char *arr_element, char *str)
{	
	int index = 0;
	while ( left <= right ) 
	{
		arr_element[index] = str[left];
 		left++ ; 
 		index++;
	}
	arr_element[left] = '\0' ; 
}
char	**ft_split(char *str, char *charset)
{
	char **arr ; 
	int index ; 
	int word;
	int start; 
	int end ; 

	index = 0 ; 
	word =0 ; 
	arr = (char **)malloc(number_of_words(str,charset) * sizeof(char *));
	if ( arr == 0 ) 
		return 0;
	while ( str[index] != '\0' ) 
	{
		if ( border(str[index] , charset) )
		{
			index++ ; 
			continue ; 
		}
 	    end_of_word(str ,charset , index , &start , &end );
		arr[word] = (char *) malloc ((end - start + 2 ) * sizeof(char));
		if ( arr[word] == 0 ) 
			return 0 ;
		fill_string( start , end , arr[word] , str ) ;
		word++ ; 
		index = end + 1 ; 

	}
	arr[word] = 0 ;
	return arr;
}

#include <stdio.h>
#define print_int(x) printf("%s = %d\n" , #x , x) ;
#define print_string(string) printf("%s = %s\n" , #string , string ) ; 
#define print_char(c) printf("%s = %c\n" , #c , c ) ; 
#define new_line printf("\n") ;
int main()
{


    int x = 10 ; 
    char *string = "first|second||third||||d" ; 
    char *charset = ".|x" ; 
    char ** arr = ft_split(string , charset) ; 

    for ( int i =  0 ; arr[i] ; i++ ) 
    {
    	print_string( arr[i] ) ; 
    }
    
    char a[] = "abcdef" ; 
    char * s = a ; 

    print_string( a ) ; 


    new_line
    new_line;

	return 0 ; 
}
