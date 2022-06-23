#include <iostream>
#include <cstdio> 
#include <string>
#include <cctype>
using namespace std;

class freqFile{
    public:
        string filename;
        FILE* fp;
        int count[26];
        freqFile(string filename){
            this->filename = filename;
            for(int i = 0 ; i < 26; i++){
                count[i] = 0;
            }
        }
        void readFile(){
            fp = fopen(filename.c_str(), "r");
            char c;
            while(fscanf(fp,"%c",&c)!=EOF){
                c = tolower(c);
                count[c-'a']++;
            }
            fclose(fp);
        }
        void showFreq(){
            for(int i = 0 ; i < 26; i++){
                cout << "["<< char(i+'a') << "] = " << count[i] << endl;  
            }
        }
};

int main()
{
    freqFile myFile("main.cpp");
    myFile.readFile();
    myFile.showFreq();
    return 0;
}
