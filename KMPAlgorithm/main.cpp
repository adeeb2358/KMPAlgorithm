//
//  main.cpp
//  KMPAlgorithm
//
//  Created by adeeb mohammed on 03/11/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>

// program for finding KMP algorithm 0(m+n) time and space complexity is o(m)
// this function creates a vector of size
std::vector<int> buildPattern(std::string substr){
    std::vector<int> patternArray(substr.size(),-1);
    int j = 0;
    int i = 1;
    while(i < substr.size()){
        if(substr[i] == substr[j]){
            patternArray[i] = j;
            i++;
            j++;
        }else if(j > 0){
            j = patternArray[j-1] + 1;
        }else{
            i++;
        }
    }
    return patternArray;
}

bool knuthMorrisPrattAlgorithm(
            std::string str,
            std::string substr) {
    auto patternArray =  buildPattern(substr);
    int i = 0;
    int j = 0;
    while(i < str.size() && j < substr.size()){
        if (str[i] == substr[j]) {
            if(j == substr.size() - 1){
                return true;
            }
            i++;
            j++;
        }else if(j > 0){
            j = patternArray[j-1] + 1;
        }else{
            i++;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::cout << knuthMorrisPrattAlgorithm(
                        "aefoaefcdaefcdaed",
                        "aefcdaed"
                );
    return 0;
}
