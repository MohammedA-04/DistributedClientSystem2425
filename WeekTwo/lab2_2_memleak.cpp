#include <iostream>

void memoryLeakExample() {
    int* array = new int[100];  

    for (int i = 0; i < 100; i++) {
        array[i] = i;  // Filling the array
    }
    std::cout << "Memory allocated but not freed." << std::endl;
    
}

int main() {
    // On each iteration
    // our program keeps intilasing a new array of 100 integers
    // via the invoke(); keeps asking for memory without releasing it
    // AS MEMORY IS LIMITED!
    for (int i = 0; i < 5; i++) {
        memoryLeakExample();  
    }
    return 0;
}
