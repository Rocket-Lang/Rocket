#include <iostream>
#include <fstream>
#include <regex>
#include <Rocket/src/include/lexer/lexer_classes.h>
#include <Rocket/src/include/lexer/lexer.h>
#include <Rocket/src/include/lexer/tokenizer.h>



static void lexing(Tokenizer tokenizer, String_Buffer sbuffer){
    std::string filepath;
    int position = 1;

    tokenizer.buffer = read_file(filepath);

    while((int)tokenizer.buffer <= position){
        std::string get_string = next_string(sbuffer);
        get_types(get_string);
        get_digit(sbuffer);
        other_keyw(sbuffer);


        sbuffer.buffer = "";
        position += 1;
    }

    return;

}

int read_file(std::string filepath){
    
    std::ifstream inFile;
	inFile.open(filepath);
	
	inFile.seekg(0, std::ios::end);
	int fileSize = inFile.tellg();
	inFile.seekg(0);
	
	std::string data(fileSize, ' ');
	inFile.read(const_cast<char*>(data.data()), fileSize);

    return fileSize;
 
}

std::string get_digit(String_Buffer sbuffer){

    std::regex r("-?[0-9]+([.][0-9]+)?");

    while(sbuffer.buffer != "\0"){
        if(regex_match(sbuffer.buffer, r)){
            
            sbuffer.buffer += sbuffer.buffer;  
            
        }
    }

    return sbuffer.buffer;
}

std::string next_string(String_Buffer sbuffer){
    
    std::regex r("[^A-Za-z_\s]");
    
    while(sbuffer.buffer != "\0"){
        
        if(regex_match(sbuffer.buffer, r)){
            sbuffer.buffer += sbuffer.buffer;
        }
    }

    return sbuffer.buffer;
}


