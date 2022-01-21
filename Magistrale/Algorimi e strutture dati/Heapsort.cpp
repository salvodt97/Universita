#include <iostream>
#include <fstream>
#include <sys/time.h>
using namespace std;


void exchange(int & i, int & j){
	int temp=i;
	i=j;
	j=temp;
}

void max_heapify(int array[], int len, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && array[left] > array[largest])
        largest = left;

    if (right < len && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        exchange(array[i], array[largest]);
        max_heapify(array, len, largest);
    }
}

void build_max_heap(int array[], int len){
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(array, len, i);
}

void heapsort(int array[], int len){
	build_max_heap(array, len);
    for (int i = len - 1; i >= 0; i--){
        exchange(array[0], array[i]);
        max_heapify(array, i, 0);
    }
}


int main(){	
	double tempi_heapsort[25];
	ofstream output1;
	
	for(int i=0; i<25; i++){
		
		timeval start, stop;
		double elapsedTime;	
		int DIM=150000+i*15000;
		int array[DIM];
		
		for(int i=0; i<DIM; i++)
    		array[i] = rand() % 1000;
    		
    	int len = sizeof(array) / sizeof(array[0]);
    	
    	gettimeofday(&start, NULL);
    	
    	heapsort(array, len);
    	
    	gettimeofday(&stop, NULL);
    	
    	elapsedTime = (stop.tv_sec - start.tv_sec);           
		elapsedTime += (stop.tv_usec - start.tv_usec)/ 1000000.0;   
		tempi_heapsort[i]=elapsedTime;
    }
    output1.open("tempi_heapsort.txt");
    for(int i=0; i<25; i++)
    	output1 << tempi_heapsort[i] <<" " << 150000+i*15000 << "\n";
    output1.close();
    
    
	cout << "Ho scritto sul file di testo di heapsort\n";
	
	
	double tempi_buildmaxheap[25];
	ofstream output2;
	
	for(int i=0; i<25; i++){
		
		timeval start, stop;
		double elapsedTime;	
		int DIM=150000+i*15000;
		int array[DIM];
		
		for(int i=0; i<DIM; i++)
    		array[i] = rand() % 1000;
    		
    	int len = sizeof(array) / sizeof(array[0]);
    	
    	gettimeofday(&start, NULL);
    	
    	build_max_heap(array, len);
    	
    	gettimeofday(&stop, NULL);
    	
    	elapsedTime = (stop.tv_sec - start.tv_sec);           
		elapsedTime += (stop.tv_usec - start.tv_usec)/ 1000000.0;   
		tempi_buildmaxheap[i]=elapsedTime;
    }
    output2.open("tempi_buildmaxheap.txt");
    for(int i=0; i<25; i++)
    	output2 << tempi_buildmaxheap[i] <<" " << 150000+i*15000 << "\n";
    output2.close();
    
    
	cout << "Ho scritto sul file di testo di buildmaxheap\n";
	
	return 0;
}
