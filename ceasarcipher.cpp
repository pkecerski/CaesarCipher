//  Created 2021-03-16
//  by Paweł Kęcerski
//  @pkecerski

#include <iostream>
#include <string>

//  Initialise functions
std::string caesarencrypt(std::string &input);
std::string caeserdecrypt(std::string &input);

//  Main Loop

int main(){
    std::string sMessage, sOperation, sResult;
    int nKey;
    bool bOperationCorrect=0;
    
    //  Prompt for message 
    std::cout << "Enter your message:" << std::endl;
    getline(std::cin, sMessage);
   
    // Prompt for operation
    while(bOperationCorrect!=1){
        std::cout << "Would you like to encrypt or decrypt the message?" << std::endl;
        getline(std::cin, sOperation);
        
        if(sOperation == "encrypt" || sOperation == "Encrypt" || sOperation == "ENCRYPT"){
            sResult = caesarencrypt(sMessage);
            bOperationCorrect = 1;
            break;
        }
        else if(sOperation == "decrypt" || sOperation == "Decrypt" || sOperation == "DECRYPT"){
            sResult = caeserdecrypt(sMessage);
            bOperationCorrect = 1;
            break;
        }
        else{
        bOperationCorrect = 0;
        }
    }
    std::cout << "Your transcoded message is: " << sResult << std::endl;
}
