/*
 * There are multiple ways to handle the call back mechanism in c++
 * 1 - function pointer 
 * 2 - functor
 * 3 - std::function and Lambdas
 */
#include<iostream>
#include<functional>
#include<thread>
#include<string>
using namespace std;
// Download service which uses the call back
class Downloader {
	public:
		using DownloadCallback = std::function<void(std::string, int)>; // define callback
		
		// another functional callback with more params
		using StatusCallback = std::function<void(std::string,int,int)>;

		void startDownload(std::string url, DownloadCallback callback) {
			std::cout<<"\n Starting the Download from : "<<url<<std::endl;

			// Simulating the download operation to take task in thread
			std::thread([url,callback]() {
					std::this_thread::sleep_for(std::chrono::seconds(2));
					bool success = true;
					if(success) {
						callback(url,200); // triggering the call back;
					}
					}).detach();
		}

		void getStatus(std::string url,StatusCallback callback) {
			std::cout<<"\n Checking status of previous Download: "<<url<<std::endl;

			std::thread([url,callback]() {
					std::this_thread::sleep_for(std::chrono::seconds(5));
					callback(url,100,10);
					}).detach();
		}
};

int main() {
	Downloader webClient;
	//Using lamda as a callback with capture local state
	int downloadCount = 0;
	webClient.startDownload("https://api.example.com/data.zip",
			[&downloadCount](std::string file, int status){
				downloadCount++;
				std::cout<<"\n[CALLBACK RECEIVED]" <<std::endl;
				std::cout<<"File: "<<file<<" finished with status: "<<status<<std::endl;
				std::cout<<"Total files handled: "<<downloadCount<<std::endl;
				});

	// Keep main thread alive for a demo
	std::this_thread::sleep_for(std::chrono::seconds(3));
	webClient.getStatus("https://api.example.com/data.zip",
			[](std::string url, int status, int percentage) {
				std::cout<<"\n[CALLBACK STATUS RECEIVED]"<<std::endl;
				std::cout<<"\nURL : "<<url;
				if(status == 200) {
					cout<<"\n Successfully Downloaded\n";
				}
				else {
					cout<<"\n Download inprogress -  "<<percentage<<"%"<<std::endl;
				}
				});
	// Keep main thread alive for a demo
	std::this_thread::sleep_for(std::chrono::seconds(9));

	return 0;
}
