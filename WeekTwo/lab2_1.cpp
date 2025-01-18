// Task One: sum two numbers
#include <iostream>
using namespace std;

int sum(int, int);
int factorial(int);
bool primeCheck(int);
int arraySum(int[], int);
void swapNumbers(int&, int&);
int calculatePow(int, int);
bool isPanlidrome(string);
int fibonacci(int);
int getPosition(int[], int, int);


int main(){

    // ----------------------- Task One -----------------------
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    int ans = sum(n1, n2);
    cout << "The sum of " << n1 << " and " << n2 << " is " << ans << endl;

    // ----------------------- Task Two -----------------------
    int fac = factorial(10);
    cout << "The factorial of 10 is " << fac << endl;

    // ----------------------- Task Three -----------------------
    int prime = primeCheck(7);
    cout << "Is 7 a prime number? " << prime << endl;

    // ----------------------- Task Four -----------------------
    int arr[] = {1, 4, 3, 3, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int total = arraySum(arr, size);
    cout << "The sum of the array is " << total << endl;

    // ----------------------- Task Five -----------------------
    int n3 = 10, n4 = 20;
    cout << "Before swapping: " << n3 << " and " << n4 << endl;
    swapNumbers(n3, n4);
    cout << "After swapping: " << n3 << " and " << n4 << endl;

    // ----------------------- Task Six -----------------------
    int base = 2, exp = 3;
    int pow = calculatePow(base, exp);
    cout << base << " to the power of " << exp << " is " << pow << endl;

    // ----------------------- Task Seven -----------------------
    string s = "racecar";
    bool pal = isPanlidrome(s);
    cout << "Is " << s << " a palindrome? " << (pal ? "True":"False") << endl;

    // ----------------------- Task Eight -----------------------
    int fib = fibonacci(5);
    cout << "The 5th fibonacci number is " << fib << endl;

    // ----------------------- Task Nine -----------------------
    int arr2[] = {1, 4, 3, 5, 6};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int pos = getPosition(arr2, size2, 5);
    cout << "The position of 5 in the array is " << pos << endl;

    return 0;
}



// Function typed here 
int sum(int n1, int n2){
    return n1 + n2;
}

int factorial(int n){
    if(n==0){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

bool primeCheck(int n){
    if(n==1){
        return 0;
    }
    else{
        for(int i=2; i<n; i++){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
    }
}

int arraySum(int array[], int size){
    int total = 0;
    // loop thru array and total them
    for(int i=0; i<size; i++){
        total += array[i];
    }

    return total;
}

void swapNumbers(int &n1, int &n2){
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int calculatePow(int base, int exp){
    int res = 1;

    for(int i=0; i<exp; i++){
        res = res * base;
    }
    return res;
}

bool isPanlidrome(string s){
    int middle = s.length()/2;
    int end = s.length()-1;

    for(int i=0; i<middle; i++){
        if(s[i] != s[end-i]){
            return false;
        }
    }
    return true;
}

int fibonacci(int n){
    if(n != 0 && n != 1){
        return fibonacci(n-1) + fibonacci(n-2);
    }else{
        return n;
    }
}

int getPosition(int array[], int size, int n){
    int pos = -1;

    for(int i=0; i<size; i++){
        if(array[i] == n){
            pos = i;
            break;
        }
    }
    return pos;
}