#include <iostream>
#include <Rocket/src/include/lexer/tokenizer.h>
#include <Rocket/src/include/parser/ast.h>

void make_ast(){
    for(int i = 0; i<sizeof(list); i++){
        std::string curr_token = list.at(i);
        std::cout << curr_token;
    }
}