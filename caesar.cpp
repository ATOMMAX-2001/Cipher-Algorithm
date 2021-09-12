/*
@Author:S.ABILASH
Comment:Got Bored
*/

#include <iostream>
#include <string>

class Caeser
{
private:
    int key=3;
public:
    char encrypt(char message)
    {
        return (char)((int)message+this->key);
    }
    char decrypt(char message)
    {
        return (char)((int)message-this->key);
    }
} caeser;

int main()
{
   
    std::string input_message="Hello";
    std::string output="";
    std::cout<<"Before Encryption :"<<input_message<<std::endl;
    for(int i=0;i<input_message.length();i++)
    {
        output+=caeser.encrypt(input_message[i]);
    }
    std::cout<<"After Encryption :"<<output<<std::endl;


    input_message=output;
    output="";
    std::cout<<"\nBefore Decryption :"<<input_message<<std::endl;
    for(int i=0;i<input_message.length();i++)
    {
    	output+=caeser.decrypt(input_message[i]);
    }
    std::cout<<"After Decryption :"<<output<<std::endl;
    return 0;
}
