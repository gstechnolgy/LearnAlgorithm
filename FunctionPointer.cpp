#include<iostream>
using namespace std;
void onComplete(int result) {
    cout <<"\n Result of the operation: "<<result<<endl;   
}

void processData(int data, void (*callback)(int)) {
    cout <<"\n Processing data: "<<data<<endl;
    int result = data * 2; // Simulate some processing
    callback(result); // Trigger the callback with the result
}

int main() {
    int inputData = 5;
    cout <<"\n Starting the data processing..."<<endl;
    processData(inputData, onComplete); // Pass the function pointer as callback
    return 0;
}   