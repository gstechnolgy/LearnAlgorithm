/*
 Code to match the strings and substring
*/
#include<iostream>
#include<string>
using namespace std;


bool isSubStringPresent(string text, string subStr) {
   int textLen = text.length();
   int subStrLen = subStr.length();
   for(int i=0; i<=(textLen-subStrLen); i++) { // repreating the the textStr patter untill it holds the substring length
     int j=0;
     while(j<subStrLen && text[i+j]==subStr[j]) {
        cout<<subStr[j]<<"---"<<text[i+j];
	j++;
     }
     cout<<"\n";
     if(j==subStrLen)
      return true;
   }
   return false;
}

int main() {
   string text = "aababba";
   string subStr = "abba";
   
   if(isSubStringPresent(text,subStr)) {
      cout<<"\n Substring is present in main text";
   } else {
     cout<<"\n Substring is not present in the main text";
   }
   return 0;
}

