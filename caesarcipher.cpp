//  Created 2021-03-16
//  by Paweł Kęcerski
//  @pkecerski

#include <iostream>
#include <string>

//  Initialise functions and variables
std::string caesarencrypt(std::string &input, int key);
std::string caesardecrypt(std::string &input, int key);

std:: string sResult;

//  Main Loop

int main(){
    std::string sMessage;
    int nKey, nOperation;
    bool nOperationCorrect=0;

    //  Prompt for message 
    std::cout << "Enter your message:" << std::endl;
    getline(std::cin, sMessage);
   
    //  Prompt for key and truncate if value is too high
    std::cout << "Enter your key (value between 0 and 25):" << std::endl;
    std::cin >> nKey;
    nKey = nKey%26;

    // Prompt for operation
    while(nOperationCorrect!=1){
        std::cout << "Would you like to:\n1. encrypt or\n2. decrypt\nthe message?" << std::endl;
        std::cin >> nOperation;
        
        if(nOperation == 1){
            std::cout << "Your encoded message is: " << caesarencrypt(sMessage, nKey) << std::endl;
            nOperationCorrect = 1;
            break;
        }
        else if(nOperation == 2){
            std::cout << "Your decoded message is: " << caesardecrypt(sMessage, nKey) << std::endl;
            nOperationCorrect = 1;
            break;
        }
        else{
        nOperationCorrect = 0;
        }
    }    
}

std::string caesarencrypt(std::string &input, int key){
    std::string sResult;

    for(int i=0; i<input.length(); i++){
        wchar_t cTemp = input[i];
        // Lowercase
        if(cTemp>='a' && cTemp<='z'){
            cTemp += key;
            if(cTemp > 'z'){
                cTemp = cTemp - 'z' + 'a' - 1;
            }
        }
        // Uppercase
        if(cTemp>='A' && cTemp<='Z'){
            cTemp += key;
            if(cTemp > 'Z'){
                cTemp = cTemp - 'Z' + 'A' - 1;
            }
        }
        sResult += cTemp;
    }
    return sResult;
}

std::string caesardecrypt(std::string &input, int key){
    std::string sResult;

    for(int i=0; i<input.length(); i++){
        wchar_t cTemp = input[i];
        // Lowercase
        if(cTemp>='a' && cTemp<='z'){
            cTemp -= key;
            if(cTemp <'a'){
                cTemp = cTemp + 'z' - 'a' + 1;
            }
        }
        // Uppercase
        if(cTemp>='A' && cTemp<='Z'){
            cTemp -= key;
            if(cTemp <'A'){
                cTemp = cTemp + 'Z' - 'A' + 1;
            }
        }
        sResult += cTemp;
    }
    return sResult;
}