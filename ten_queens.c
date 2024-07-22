

#include<stdio.h>

#define new_line printf("\n" );



int can_be_placed( int arr[10][10] , int n , int row , int col ) 
{
	int	r;
	int	c;

	c = 0 ;
	// check the current row and previous cols 
	while ( c < col )
	{
		if ( arr[row][c] )
			return 0 ;
		c++;
	}
 

	// check ( left , up ) cells
	  r = row - 1 ;
	  c = col - 1 ; 

	while ( r > -1 && c > -1 )
	{
		if ( arr[r][c] ) 
			return 0 ; 

		r--; 
		c-- ; 
	}

    // check ( left , down ) cells 

    r = row + 1 ;
    c = col - 1 ; 

    while ( r < n && c > -1 ) 
    {
    	if ( arr[r][c] ) 
    		return 0 ; 

    	r++ ; 
    	c-- ; 
    }

    return 1 ;
}


int solve ( int arr[10][10] , int n , int col )
{	

	int	r;
	int c;
	int answer;

	  if ( col == 10 )
	  {
	  	// base_case ;

	  	for ( int i  = 0 ; i < n ; i++ ) 
	  	{
	  		for ( int j = 0 ; j < n ; j++ ) 
	  		{
	  			if ( arr[i][j] ) printf("Q");
	  			else printf(".");

	  			printf(" ");
	  		}
	  		new_line;
	  	}
	  	printf("====================");
	  	new_line;
	  	c = 0 ;
 	  	while ( c < n ) 
 	  	{
 	  		r = 0 ;
 	  		while ( r < n ) 
 	  		{
 	  			if ( arr[r][c] == 1 ){
 	  				printf("%d" , r ) ; 
 	  				break;
 	  			}
 	  			r++;
 	  		}
 	  		c++;
 	  	}
	  	new_line;
	  	return 1 ;// 1 that means that there's a solution
	  }


	  // count the number of rows where we can placed a queen in this col
	  answer = 0 ;
	  for ( int row = 0 ; row < n ; row++ )
	  {

	  	 	// check if we can placed queen in the current row 
	  	   if ( can_be_placed(arr , n , row , col ))
	  	   {

 	  	   		// mark this as placed
	  	   		arr[row][col] = 1 ; 
	  	   		// move the next column
	  	   		answer += solve( arr , n , col + 1 ) ;

	  	   		// backtracking
	  	   		arr[row][col] = 0 ; // making the current row is empty after using it 

	  	   }
 

	  }

	  return answer ;
}





int queen (void) 
{
	int arr[10][10] ;
	int row;
	int col;
	int n;

	row = 0; 
	n   = 10 ;
	while ( row < n ) 
	{	
		col = 0 ;
		while ( col < n ) 
		{
			arr[row][col] = 0 ; 
			col++;
		}
		row++;
	}	

    return solve( arr , n , 0 ) ;
}

int main()
{

  queen();

	return 0 ;
}