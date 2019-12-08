#pragma once
#include "ofMain.h"

class FileReader{
private:
    vector<string> file_words;
public:
    void ReadWords(string relative_name);
    vector<string> GetFileWords();
    void ClearWords();
};
