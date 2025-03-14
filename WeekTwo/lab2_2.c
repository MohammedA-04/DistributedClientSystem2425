#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main(){

    // ------------------ Task one: Input Safety ------------------
    // Take String -> ensure no buffer overflow -> print it
    char buf[10];
    cout << "Enter a string: " << endl;
    cin.getline(buf, 10);
    cout << "You entered: " << buf << endl;

    // ------------------ Task two: Error Handling Basics ------------------ 
    // Take a number -> ensure it is a number -> print it
    bool valid = false;
    do{
        int n; 
        cout << "Enter a number: " << endl;
        cin >> n;

        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            valid = false;
        } else {
            valid = true;
            cout << "You entered: " << n << endl;
        }
    } while(valid == false);

    // ------------------ Task three: File Permission ------------------
    // make .cpp to read/write to text -> allow permission for user only 
    
    // NOT COMPLETED?
    string filename = "test.txt";
    ofstream outfile(filename);

    if(!outfile){
        cout << "Error opening file" << endl;
        return 1;
    }
    
    outfile << "Hello World Mo Here!" << endl;
    outfile.close();

    if(!SetFileAttributesA(filename.c_str(), FILE_ATTRIBUTE_NORMAL)){
        cout << "Error changing file permission" << endl;
        return 1;
    }

    // ------------------ Task four: Memory Leak found in lab2_2_memleak.cpp ------------------

    // ------------------ Task five: Input Validation ------------------
    // take input -> check common issues like over long intput/unexpected chars

    // ------------------ Task six: Basic Encryptor ------------------
    char alp[] = "abcdefghijklmnopqrstuvwxyz";
    int alp_size = sizeof(alp) / sizeof(alp[0]);
    string input;
    int key;

    cout << "Enter a string to encrypt: " << endl;
    cin >> input;

    cout << "Enter how many characters to shift: " << endl;
    cin >> key;

    // Loop string -> move char by key -> print
    for(int i = 0; i < input.length(); i++){
        for(int j=0; j< alp_size; j++){
           if(input[i] == alp[j]){
                cout << endl; // modula to wrap alp[]
                cout << alp[(j+key) % alp_size];
                // mod works if j+key[26] % size[26] = i[0]
           }
        }
    }

    // TODO: not done yet
    // ------------------ Task seven: Signal Handling basics ------------------

    // ------------------ Task eight: Concurrency ------------------

    // ------------------ Task nine: Netowrk Security Awareness ------------------
    
    // ------------------ Task ten: Graceful Program Shutdown ------------------



    return 0;
}