// Heap demo

#include <iostream>

int* intOnHeap();

int main()
{
	int* pHeap = new int;
	*pHeap = 10; // initialise value
	std::cout << "*pHeap: " << *pHeap << "\n\n";
	
	int* pHeap2 = intOnHeap();
	std::cout << "*pHeap2: " << *pHeap2 << "\n\n";
	
	std::cout << "Freeing mem at pHeap.\n\n";
	delete pHeap;
	
	std::cout << "Freeing mem at pHeap2.\n\n";
	delete pHeap2;
	
	// remove dangles
	pHeap = 0;
	pHeap2 = 0;
	
	return 0;
}

int* intOnHeap() // data allocated here is still available in main
{
	return new int(20); // initialise while allocating
}