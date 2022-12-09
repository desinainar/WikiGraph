
#pragma once
using namespace std;

#include <vector>
#include <string>
#include <iostream>

#include "Node.h"

struct Edge{
    
    string source_;
    string destination_;
    int weight_;

    //Constructor:
    Edge(string source, string destination) : source_(source), destination_(destination) { }

    bool operator!=(const Edge e1){
        if(source_ != e1.source_){return true;}
        else if(destination_ != e1.destination_){return true;}
        return false;
    }

    std::string utf8_decode(const std::string& encodedString)
    {
        std::string decodedString;
        for(size_t i = 0; i < encodedString.length(); i++)
        {
            if(encodedString[i] == '%' && i + 2 < encodedString.length())
            {
                // Read the two characters after the % sign
                std::string hexCode = encodedString.substr(i + 1, 2);

                // Convert the hexadecimal code to an integer value
                int asciiValue = stoi(hexCode, nullptr, 16);

                // Append the corresponding ASCII character to the decoded string
                decodedString += static_cast<char>(asciiValue);

                // Skip the two characters we just read
                i += 2;
            }
            else
            {
                // If the character is not part of a %xx sequence, just append it to
                // the decoded string
                decodedString += encodedString[i];
            }
        }
        return decodedString;
    }


    void print(){
        std::string new_src = source_;
        std::string new_dst = destination_;
        if (source_.find("%") != string::npos) {
            new_src = utf8_decode(source_);
        }
        if (destination_.find("%") != string::npos) {
            new_dst = utf8_decode(destination_);
        }
        cout << new_src << " -> " << new_dst << endl;
    }

};
