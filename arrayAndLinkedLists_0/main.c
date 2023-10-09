#include <stdio.h>
#include <stdlib.h>
void removeInTheMiddle(int **numbers, const int size);
void addInTheMiddle(int **numbers, int numberInput, const int size);
void addFromTheEnd(int **numbers, int numberInput, const int size);
void removeFromTheEnd(int **numbers, const int size);
void removeFromTheBegin(int **numbers, const int size);
void addTheBegin(int *numbers, int inputNumber, const int rows);
void resizeNumbers(int **numbers, const int size);
void insertNumbers(int *numbers, const int rows);
void showNumbers( const int *numbers, const int rows);
int main(void){
	int N = 5;
	// how to make an order aray 
	int *numbers = (int*) malloc(sizeof(int) * N);
	
	printf("## Before modifying numbers ##\n");
	// insert all the numbers
	insertNumbers(numbers, N);
	showNumbers(numbers, N);
		
	// resize the array
	N += 1;
	resizeNumbers(&numbers, N); 
	// add from the beginning
	addTheBegin(numbers, 100, N);
	// show the numbers
	
	printf("## After addding number in the begining ##\n");
	showNumbers(numbers, N);	
	
	// add from the middle
	N += 1;
	addInTheMiddle(&numbers, 6000, N);
	printf("## After addding number in the middle ##\n");
	showNumbers(numbers, N);

	// add from the end
	N += 1;
	addFromTheEnd(&numbers, 200, N);
	printf("## After addding number in the end ##\n");
	showNumbers(numbers, N);
	

	// remove from the beginning
	N -= 1;
	removeFromTheBegin(&numbers, N); 
	printf("## Remove number in the begining ##\n");
	showNumbers(numbers, N);
	
	// remove from the middle
	N -= 1;
	removeInTheMiddle(&numbers, N);
	printf("## Remove number in the middle ##\n");
	showNumbers(numbers, N);

	// remove from the end	
	N -= 1;
	removeFromTheEnd(&numbers, N); 
	printf("## Remove number from the end ##\n");
	showNumbers(numbers, N);
	
	free(numbers);
	numbers = NULL;	
	return(0);
}

// Time complexity O(N)
void removeInTheMiddle(int **numbers, const int size){
	// move all the number from left to the middle
	int oldSize = size + 1;
	int mid = (oldSize/2);
	for(int index = mid; index < oldSize; index++){
		(*numbers)[index] = (*numbers)[index + 1]; 
	}	
	// reallocate after moving from right to left
	*numbers = realloc(*numbers, sizeof(int) * size);
}

// Time complexity O(N)
void addInTheMiddle(int **numbers, int numberInput, const int size){
	// reallocate
	*numbers = realloc(*numbers, sizeof(int) * size);
	int mid = size/2;
	// move bottom half
	for(int index = size - 1; index > mid; index--){

		(*numbers)[index] = (*numbers)[index - 1];
	}	
	// move a number in the middle
	(*numbers)[mid] = numberInput;
}

// Time complexity O(1)
void addFromTheEnd(int **numbers, int numberInput, const int size){
	
	// reallocate memory 
	*numbers = realloc(*numbers, sizeof(int) * size);
	(*numbers)[size - 1] = numberInput;
}

// Time Complexity O(1)
void removeFromTheEnd(int **numbers, const int size){
	if (size <= 0){
		return;
	}
	// reallocation simply remove the element from the end
	*numbers = realloc(*numbers, sizeof(int) * (size));	
}

// Time Complexity O(N)
void removeFromTheBegin(int **numbers, const int size){
	int *newNumbers = (int *) malloc(sizeof(int) * size);
	// move all the number from right to left 
	// simply delete the last element
	for(int index = 1; index < size + 1; index++){
		newNumbers[index - 1] = (*numbers)[index];
	}
	free(*numbers);
	*numbers = newNumbers;
	
	// allocate a new memory and copy to the the new one
	// and reassign that address to another one	
}

// Time Complexity O(N)
void addTheBegin(int *numbers, int inputNumber, const int rows){
	int temp = numbers[0];
	for(int index = rows - 1; index >= 0; index--){
		numbers[index] = numbers[index - 1];
	}
	numbers[0] = inputNumber;
}
void resizeNumbers(int **numbers, const int size){
	*numbers = realloc(*numbers, sizeof(int) * size);
}
void showNumbers(const int *numbers, const int rows){
	for(int index = 0; index < rows; index++){
		printf("%d\n", numbers[index]);
	}
}
void insertNumbers(int *numbers, const int rows){
	for(int index = 0; index < rows; index++){
		numbers[index] = index;
	}

}
