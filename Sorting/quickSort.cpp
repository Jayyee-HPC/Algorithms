/**
 * A quick sort implementation in C++
 * Input: array
 * Output: sorted array
 * Always pick the first element as pivot
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sys/time.h>   /* time in ms */
#include <assert.h>     /*assert */

template <class Var>
int quickSorter(Var* var, size_t begin, size_t end);

template <class Var>
int partition(Var* var, size_t start, size_t end);

int testcases(void);

int main(int argc, char** argv){
	testcases();
	return 0;
}

int testcases(void){
	struct timeval tp;
	/* initialize random seed: */
 	srand (time(NULL));

	size_t array_size  = 10000;
	
	int* array;
	array = (int*)malloc(sizeof(int) * array_size);
	if(array == NULL){
		std::cout<<"Malloc failed!"<<std::endl;
		return 0;
	}

	/*genetate random numbers between array_size and 1*/
	for(int i = 0; i < array_size; ++i){
		array[i] = rand() % array_size + 1;
	}
	gettimeofday(&tp, NULL);
	long int timeBegin = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	
	quickSorter(array, 0, array_size-1);
	
	gettimeofday(&tp, NULL);
	long int timeEnd = tp.tv_sec * 1000 + tp.tv_usec / 1000;	

	for(int i = 0; i < array_size-1; ++i){
		assert(array[i] <= array[i+1]);
		//std::cout<<array[i]<<std::endl;
	}

	std::cout<<"Quick sorting finished in (ms): "<<timeEnd - timeBegin<<std::endl;
	free(array);
	return 0;
}

template <class Var>
int quickSorter(Var* var, size_t start, size_t end){
	if(start < end){
		size_t mid = partition(var, start, end);
		quickSorter(var, start, mid);
		quickSorter(var, mid+1, end);
	}
	return 0;
}

template <class Var>
int partition(Var* var, size_t start, size_t end){
	Var pivot = var[start];
	Var tmpVar;
	size_t mid = start;

	for(size_t i = start + 1; i <= end; ++i){
		if(var[i] < pivot){
			++mid;
			tmpVar = var[mid];
			var[mid] = var[i];
			var[i] = tmpVar;
		}
	}

	tmpVar = pivot;
	var[start] = var[mid];
	var[mid] = tmpVar;
	return mid;
}
