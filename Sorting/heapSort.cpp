/**
 * A heap sort implementation in C++
 * Input: array
 * Output: sorted array
 * 1. Build a max heap from the input data.
 * 2. At this point, the largest item is stored at the root of the heap. 
 * 		Replace it with the last item of the heap followed by reducing the size of heap by 1. 
 * 		Finally, heapify the root of tree.
 * 3. Repeat above steps while size of heap is greater than 1.
 *
 * Heapify procedure can be applied to a node only if its children nodes are heapified. 
 * 		So the heapification must be performed in the bottom up order.
 *
 * Using template for heapfier() causes unknown bug. 
 * Using int instead.
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sys/time.h>   /* time in ms */
#include <assert.h>     /*assert */

//template <class Var>
void heapify(int* var, size_t size, size_t root);

//template <class Var>
void heapSorter(int* var, size_t size);

template <class Var>
void swap(Var &var1, Var &var2);

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
	
	heapSorter(array, array_size);
	
	gettimeofday(&tp, NULL);
	long int timeEnd = tp.tv_sec * 1000 + tp.tv_usec / 1000;	

	for(int i = 0; i < array_size-1; ++i){
		assert(array[i] <= array[i+1]);
		//std::cout<<array[i]<<std::endl;
	}

	std::cout<<"Heap sorting finished in (ms): "<<timeEnd - timeBegin<<std::endl;
	free(array);
	return 0;
}

template <class Var>
void swap(Var &var1, Var &var2){
	Var tmp = var1;
	var1 = var2;
	var2 = tmp;
}

void heapify(int* var, size_t n, size_t root) 
{ 
    int largest = root; // Initialize largest as root 
    int l = 2 * root + 1; // left = 2*i + 1 
    int r = 2 * root + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && var[l] > var[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && var[r] > var[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != root) { 
        swap(var[root], var[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(var, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSorter(int* var, size_t n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(var, n, i); 
  
    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(var[0], var[i]); 
  
        // call max heapify on the reduced heap 
        heapify(var, i, 0); 
    } 
} 