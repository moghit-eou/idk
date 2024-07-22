

#include <stdio.h>
#include <unistd.h>
#define new_line printf("\n" );

int	check_diagonal(int arr[10][10], int n, int row, int col)
{
	int	r;
	int	c;

	r = row + 1;
	c = col - 1;
	while (r < n && c > -1)
	{
		if (arr[r][c])
			return (0);
		r++;
		c--;
	}
	r = row - 1;
	c = col - 1;
	while (r > -1 && c > -1)
	{
		if (arr[r][c])
			return (0);
		r--;
		c--;
	}
	return (1);
}

int	can_be_placed(int arr[10][10], int n, int row, int col)
{
	int	c;

	c = 0;
	while (c < col)
	{
		if (arr[row][c])
			return (0);
		c++;
	}
	return (check_diagonal(arr, n, row, col));
}

void print_line ( int arr[10][10])
{

}

int solve ( int arr[10][10] , int n , int col )
{

	  if ( col == 10 )
	  {
	   	print_line(arr);
	  	new_line;
	  	return 1;
	  }


	  // count the number of rows where we can placed a queen in this col
	  int answer = 0 ;
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

	int n = 10 ; 
	int arr[n][n] ; 

	for ( int i = 0 ; i < n ; i++ ) 
		for ( int j = 0 ; j < n ; j++ )
			arr[i][j] = 0 ;
	

	
    return solve( arr , n , 0 ) ;
}

int main()
{

  queen();

	return 0 ;
}
