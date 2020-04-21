#include <string>

class Tokenizer{
    public:
        std::string path;
        int buffer;
};

class String_Buffer{
    public:
        std::string buffer;
        char buffer_start,
            buffer_end;
};

class Token{
    public:
        int type;
        std::string value_token;
        int line;
};

Token create_token(std::string value, int name){
    int type = name;
    std::string value_token = value;
    int line = line;
};