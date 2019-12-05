#include <FileReader.h>
void FileReader::ReadWords(string relative_name){

    ofBuffer buffer = ofBufferFromFile(relative_name);
    for (auto line : buffer.getLines()){
        file_words.push_back(line);
    }
}

vector<string> FileReader::GetFileWords(){
    return file_words;
}
