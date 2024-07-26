#include<bits/stdc++.h>
using namespace std;
void writeByContent(string fileName, string content){
    fstream file(fileName,ios::app);//o stands for output ops, and we are opening it in append mode, to write at the back of existing content
    if(!file){
        cout<<"Couldn't open the file.";
        return ;
    }
    file<<"Writing the whole content at once\n";
    file<<content;
    file.close();
}
void writeByLines(string fileName, string content){
    fstream file(fileName,ios::app);//using f, we can do both input and output ops.
    if(!file){
        cout<<"Couldn't open file.";
        return ;
    }
    file<<"\nWriting line by line\n";
    //first, need to traverse the content line by line, writing is similar
    istringstream stream(content);//this allows to treat the string as an input stream
    string line;
    while(getline(stream,line)){
        file<<line;
        file<<"\n";
    }
    file.close();
}
void writeByWords(string fileName,string content){
    ofstream file(fileName,ios::app); //we can also mention a mode as second argument, like read, write, trunc, delete, etc.
    if(!file){
        cout<<"Couldn't open file.";
        return ;
    }
    file<<"Writing word by word\n";
    istringstream stream(content);
    string word;
    while(stream >> word){
        word+=' ';
        file << word;
    }
    file.close();
}
void writeByCharacters(string fileName, string content){
    ofstream file(fileName,ios::app);
    if(!file){
        cout<<"Couldn't open file.";
        return ;
    }
    file<<"\nWriting character by character\n";
    char ch;
    istringstream stream(content);
    while(stream.get(ch) && !stream.eof()){//eof checks for end of file.
        file.put(ch);
    }
    file.close();
}
void replicate(string fileName){
    fstream file(fileName,ios::app | ios::in);//can't read in append only, so use in to make a combo of modes
    if(!file){
        cout<<"Couldn't open file.";
        return ;
    }
    stringstream buffer;
    buffer<<file.rdbuf();
    string content = buffer.str();
    file << "\nReplicating file Content\n";
    file<<content;
    
    file.close();
}
int main(){
    string fileName="output.txt";
    string content="God Bless us!\nGod Bless Us!\nGod Bless Us!";
    writeByContent(fileName,content);
    writeByLines(fileName,content);
    writeByWords(fileName,content);
    writeByCharacters(fileName,content);
    //deleting of characters can't be done in file directly, instead read the content, modify it in runtime storage and put it.
    //wherever we are writing, we will automatically clear content after that pointer and write over it.
    replicate(fileName);
    return 0;
}