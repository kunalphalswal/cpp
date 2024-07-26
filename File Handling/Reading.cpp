#include<bits/stdc++.h>
using namespace std;
string readFile(string fileName){
    ifstream file(fileName); //i in ifstream stands for input
    stringstream buffer;
    buffer<<file.rdbuf();
    string content=buffer.str();
    for(int i=0;i<=content.size()-7;i++){
        if(content.substr(i,7)=="......."){
            return content.substr(0,i);
        }
    }
    file.close();
    return content;
}
string readLines(string fileName){
    ifstream file(fileName);
    //check if it's successful or not
    if(!file){
        cout<<"unable to open file.";
        return "404";
    }
    string content="";
    string line;
    //read the file line by line
    while(getline(file,line)){//can also define a custom delimiter character(char only not string) as third argument
        if(line.substr(0,7)!="......."){
            content+=line;
            content+=" ";
        }else break;
    }
    file.close();
    return content;
}
string readWords(string fileName){
    ifstream file(fileName);
    string word;
    string content;
    while(file >> word){
        if(word.size()>=7 && word.substr(0,7)=="......."){
            break;
        }
        content+=word;
        content+=' ';
    }
    file.close();
    return content;
}
string readCharacters(string fileName){
    ifstream file(fileName);
    string content="";
    char ch;
    while(file.get(ch)){//can also define a custom delimiter here.
        content+=ch;
    }
    for(int i=0;i<content.size()-7;i++){
        if(content.substr(i,7)=="......."){
            return content.substr(0,i);
        }
    }
    file.close();
    return content;
}
int main(){
    string fileName = "text.txt"; //need to mention full path here
    //to access a file's content from a given location.
    cout<<"Reading the whole file together:\n";
    cout<<readFile(fileName);//also incorporates the new line character.
    cout<<"\nReading the file line by line.\n";
    cout<<readLines(fileName);
    cout<<"\nReading the file word by word\n";
    cout<<readWords(fileName);
    cout<<"\nReading the file character by character.\n";
    cout<<readCharacters(fileName);//incorporates the new line character as well, because it reads every character.
    return 0;
}