/*
    @AUTHOR: S.ABILASH
    COMMENT: idont know this code is valid 
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class playFair
{
private:
    std::string key = "MONEY";
public:
    std::string getKey()
    {
        return this->key;
    }
   void checkSizeAndDuplicate(std::string& message)
   {
    if(message.length()%2!=0){
        message=message+'z';
    }
    for(int i=0;i<message.length();i++)
    {
        if(message[i]==message[i+1]){
            message[i+1]='z';
        }
    }
   }
   void convertCase(std::string& message)
   {
     transform(message.begin(),message.end(),message.begin(),::toupper);
   }
   bool checkExist(char a)
   {
    int pos = this->key.find(a);
    if(pos!=-1)
        return true;
    return false;
   }
  
   std::vector<std::vector<char> > generateKeyMatrix()
   {
    char start='A';
    std::vector<std::vector<char> > keyMatrix;
    std::vector<char> sub;
    for(int i=0;i<5;i++){
        sub.push_back(this->key[i]);
    }
    keyMatrix.push_back(sub);
    sub.clear();
    for(int i=1;i<5;i++)
    {
        sub.clear();
        for(int j=0;j<5;j++)
        {
            while(checkExist(start) || start=='J'){
                    start++;
                }

            sub.push_back(start);
            start++;            
        }
        keyMatrix.push_back(sub);
    }
    return keyMatrix;
   }  
   void printGenMatrix(std::vector< std::vector<char> > genMat)
   {
    std::cout<<"Generated: "<<std::endl;
    for(int i=0;i<genMat.size();i++)
    {
        for(int j=0;j<genMat[i].size();j++)
        {
            std::cout<<genMat[i][j]<<" ";
        }
        std::cout<<endl;
    }
   }
   void encrypt(std::string& message)
   {
        std::string output;
        std::vector<std::vector<char> >genMat=generateKeyMatrix();
        printGenMatrix(genMat);
        int pointer=0;
        while(pointer<message.length())
        {
            char left=message[pointer];
            char right=message[pointer+1];
            int leftPosRow,leftPosCol,rightPosRow,rightPosCol;
            for(int i=0;i<genMat.size();i++)
            {
                for(int j=0;j<genMat[i].size();j++)
                {
                    if(left==genMat[i][j]){
                        leftPosRow=i;
                        leftPosCol=j;
                    }
                    if(right==genMat[i][j]){
                        rightPosRow=i;
                        rightPosCol=j;
                    }
                }
            }
            if( (leftPosRow!=rightPosRow) && (leftPosCol!=rightPosCol) ){
                output+=genMat[leftPosRow][rightPosCol%5];
                output+=genMat[rightPosRow][leftPosCol%5];
            }else if(leftPosCol==rightPosCol && leftPosRow!=rightPosRow){
                output+=genMat[(leftPosRow+1)%5][leftPosCol];
                output+=genMat[(rightPosRow+1)%5][rightPosCol];
            }else if(leftPosRow==rightPosRow && leftPosCol!=rightPosCol){
                output+=genMat[leftPosRow][(leftPosCol+1)%5];
                output+=genMat[rightPosRow][(rightPosCol+1)%5];
            }
            pointer+=2;   
        }
        message=output;
        
   }
} play;

int main()
{
   
    std::string input_message="hello";
    
    std::cout<<"Message:"<<input_message<<endl<<"Key: "<<play.getKey()<<std::endl;
    play.checkSizeAndDuplicate(input_message);
    std::cout<<input_message<<endl;
    play.convertCase(input_message);
    std::cout<<input_message<<endl;
    play.encrypt(input_message);
    std::cout<<"Encrypt: "<<input_message<<std::endl;

       
    return 0;
}
