/**
 * A bubble sort implementation in C++
 * Input: array
 * Output: sorted array
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sys/time.h>   /* time in ms */
#include <assert.h>     /*assert */

template <class Var>
int bubbleSorter(Var* var, size_t size);
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

	/*genetate random numbers between array_size and 1*/
	for(int i = 0; i < array_size; ++i){
		array[i] = rand() % array_size + 1;
	}
	gettimeofday(&tp, NULL);
	long int timeBegin = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	
	bubbleSorter(array, array_size);
	
	gettimeofday(&tp, NULL);
	long int timeEnd = tp.tv_sec * 1000 + tp.tv_usec / 1000;	

	for(int i = 0; i < array_size-1; ++i){
		assert(array[i] <= array[i+1]);
		//std::cout<<array[i]<<std::endl;
	}

	std::cout<<"Bubble sorting finished in (ms): "<<timeEnd - timeBegin<<std::endl;
	free(array);
	return 0;
}

template <class Var>
int bubbleSorter(Var* var, size_t size){
	Var tmp_var;
	for(int i = 0; i < size; ++i){
		for(int j = i + 1; j < size; ++j){
			if(var[i] > var[j]){
				tmp_var = var[i];
				var[i] = var[j];
				var[j] = tmp_var;
			}
		}
	}
	return 0;
}
