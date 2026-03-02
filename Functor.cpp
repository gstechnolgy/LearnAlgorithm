/*
Functor example from the class Object 
*/
#include <iostream>
using namespace std;

// Event handler functor (function object)
class EventHandler {
    public:
    void operator()(int result) {
        cout << "Event triggered with result: " << result << endl;
    }
};

void processData(int data, EventHandler callback) {
    cout << "Processing data: " << data << endl;
    int result = data * 2; // Simulate some processing
    callback(result); // Trigger the callback with the result
}

int main() {
    int inputData = 5;
    cout << "Starting the data processing..." << endl;
    EventHandler handler; // Create an instance of the functor
    processData(inputData, handler); // Pass the functor as callback
    return 0;
}