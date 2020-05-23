/**
 * A merge sort implementation in C++
 * Input: array
 * Output: sorted array
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sys/time.h>   /* time in ms */
#include <assert.h>     /*assert */

template <class Var>
int mergeSorter(Var* var, size_t begin, size_t end);

template <class Var>
int merge(Var* var, size_t start, size_t middle, size_t end);

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
	
	mergeSorter(array, 0, array_size-1);
	
	gettimeofday(&tp, NULL);
	long int timeEnd = tp.tv_sec * 1000 + tp.tv_usec / 1000;	

	for(int i = 0; i < array_size-1; ++i){
		assert(array[i] <= array[i+1]);
		//std::cout<<array[i]<<std::endl;
	}

	std::cout<<"Merge sorting finished in (ms): "<<timeEnd - timeBegin<<std::endl;
	free(array);
	return 0;
}

template <class Var>
int mergeSorter(Var* var, size_t start, size_t end){
	if(end > start){
		size_t middle = start + (end - start)/2;
		mergeSorter(var, start, middle);
		mergeSorter(var, middle + 1, end);
		merge(var, start, middle, end);
	}
	return 0;
}

template <class Var>
int merge(Var* var, size_t start, size_t middle, size_t end){
	size_t i = start;
	size_t j = middle + 1;
	size_t k = 0;
	Var* tmpVar;
	tmpVar = (Var*)malloc(sizeof(Var) * (end - start + 1));

	while(i <= middle && j <= end){
		if(var[i] < var[j]){
			tmpVar[k] = var[i];
			++i;
		}else{
			tmpVar[k] = var[j];
			++j;
		}
		++k;
	}

	while(i <= middle){
		tmpVar[k] = var[i];
		++i;
		++k;
	}

	while(j <= end){
		tmpVar[k] = var[j];
		++j;
		++k;
	}

	for(i = start; i <= end; ++i){
		var[i] = tmpVar[i-start];
	}

	free(tmpVar);
	return 0;
}
