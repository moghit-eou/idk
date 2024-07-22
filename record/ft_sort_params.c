#include <string.h>
#include <unistd.h>


int ft_strcmp ( char *first , char * second ) {

	 int index = 0 ; 

	 while ( first[index] != '0' && second[index] != '\0')
	 {
	 	  if ( first[index] != second[index] ) 
	 	  	return ( first[index] - second[index] ) ; 

	 	  index++;
	 }

	 return ( first[index] - second[index] ) ;
}


void swap ( char ** first, char ** second ) 
{
	 char *temp = *first ; 
	 *first = *second ; 
	 *second = temp ; 

}

void print_string( char *string )
{
	int index = 0 ; 

	while ( string[index] != '\0' ){
		 write ( 1 , &string[index] , 1 ) ; 
		 index++;
	}
}
#include<stdio.h>
int main( int argc , char *argv[])
{



 int is_not_sorted = 1 ; 

	while ( is_not_sorted )
	{
		is_not_sorted = 0 ;

		int index = 2 ;  // skip index 0 
		while ( index < argc ) 
		{
			if ( strcmp ( argv[index - 1] , argv[index] ) > 0 )
			{
 				swap ( &argv[index - 1] , &argv[index] ) ;
 				is_not_sorted = 1 ;
			}
			index++;
		}
	}  

    int index = 1 ; 
    while ( index < argc ) 
    {
    	printf("%s\n" , argv[index] ) ; 
    	index++;
    }
    


	return 0;
}



