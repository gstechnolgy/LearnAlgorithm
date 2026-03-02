/*
Example of using std::bind to create a function object that binds a member function to an instance of a class.
This allows us to use member functions as callbacks while still maintaining access to the object's state.
*/
#include <iostream>
#include <functional>
using namespace std;

void processData(int data, function<void(int)> callback) {
    cout << "Processing data: " << data << endl;
    int result = data * 2; // Simulate some processing
    callback(result); // Trigger the callback with the result
}

class DataProcessor {
public:
    void memberCallback(int result) { 
        cout << "Member callback with result: " << result << endl; 
    }
};


int main() {
    int inputData = 5;
    cout << "Starting the data processing..." << endl;
    processData(inputData, [](int result) {
        cout << "Lambda callback with result: " << result << endl;
    });

    /* calling via bind operation*/

    DataProcessor processor;
    auto boundCallback = std::bind(&DataProcessor::memberCallback, &processor, std::placeholders::_1);
    processData(inputData, boundCallback);
}



