#include <string>
#include <Rocket/src/include/lexer/lexer_classes.h>
#include <Rocket/src/include/tokens/rocket_tokens.h>
#include <vector>

static std::vector<std::string> list;


void other_keyw(String_Buffer sbuffer){
    
    while(sbuffer.buffer != "\0"){
        if(sbuffer.buffer == "("){
            create_token("(", OPEN_PARANTHESES), add_token("(");
        }
        else if(sbuffer.buffer == ":"){
            create_token(":", COLON), add_token(":");
        }
        else if(sbuffer.buffer == "!"){
            create_token("!", EXCLAMATION), add_token("!");
        }
        else if(sbuffer.buffer ==")"){
            create_token(")", CLOSE_PARANTHESES), add_token(")");
        }
        else if(sbuffer.buffer =="["){
            create_token("[", OPEN_BRACKETS), add_token("[");
        }
        else if(sbuffer.buffer == "]"){
            create_token("]", CLOSE_BRACKETS), add_token("]");
        }
        else if(sbuffer.buffer == "{"){
            create_token("{", OPEN_BRACES), add_token("{");
        }
        else if(sbuffer.buffer == "}"){
            create_token("}", CLOSE_BRACES), add_token("}");
        }
        else if(sbuffer.buffer == ","){
            create_token(",", COMMA), add_token(",");
        }
        else if(sbuffer.buffer == ";"){
            create_token(";", SEMICOLON), add_token(";");
        }
        else if(sbuffer.buffer == "="){
            create_token("=", EQUAL), add_token("=");
        }
        else if(sbuffer.buffer =="*"){
            create_token("*", TIMES), add_token("*");
        }
        else if(sbuffer.buffer == "+"){
            create_token("+", PLUS), add_token("+");
        }
        else if(sbuffer.buffer == "-"){
            create_token("-", MINUS), add_token("-");
        }
        else if(sbuffer.buffer == "/"){
            create_token("/", DEVIDE), add_token("/");
        }
        else if(sbuffer.buffer == "."){
            create_token(".", DOT), add_token(".");
        }
        else if(sbuffer.buffer == "'\'"){
            create_token("'\'", BACKSLASH), add_token("'\'");
        }
        else if(sbuffer.buffer == "%"){
            create_token("%", MODULO), add_token("%");
        }
        else if(sbuffer.buffer ==  "=="){
            create_token("==", DOUBLE_EQUAL), add_token("==");
        }
        else if(sbuffer.buffer == "AND"){
            create_token("AND", AND), add_token("AND");
        }
        else if(sbuffer.buffer == "OR"){
            create_token("OR", OR), add_token("OR");
        }
        else if(sbuffer.buffer == "return"){
            create_token("return", RETURN), add_token("return");
        }
        else if(sbuffer.buffer == ">"){
            create_token(">", GREATER), add_token(">");
        }
        else if(sbuffer.buffer == ">="){
            create_token(">=", GREATER_EQUAL), add_token(">=");
        }
        else if(sbuffer.buffer == "<"){
            create_token("<", LESS), add_token("<");
        }
        else if(sbuffer.buffer =="<="){
            create_token("<=", LESS_EQUAL), add_token("<=");
        }
        else if(sbuffer.buffer == "**"){
            create_token("**", TIMES_TIMES), add_token("**");
        }
        else if(sbuffer.buffer == "+="){
            create_token("+=", PLUS_EQUAL), add_token("+=");
        }
        else if(sbuffer.buffer == "-="){
            create_token("-=", MINUS_EQUAL), add_token("-=");
        }
        else if(sbuffer.buffer == "*="){
            create_token("*=", TIMES_EQUAL), add_token("*=");
        }
        else if(sbuffer.buffer == "++"){
            create_token("++", PLUS_PLUS), add_token("++");
        }
        else if(sbuffer.buffer == "--"){
            create_token("--", MINUS_MINUS), add_token("--");
        }
        else if(sbuffer.buffer == "/="){
            create_token("/=", DEVIDE_EQUAL), add_token("/=");
        }
    }
}

void get_types(std::string token){

    if(token.compare("int")){
        create_token("int", INT), add_token("int");
    }
    else if(token.compare("string")){
        create_token("string", STRING), add_token("string");
    }
    else if(token.compare("char")){
        create_token("char", CHAR), add_token("char");
    }
    else if(token.compare("double")){
        create_token("double", DOUBLE), add_token("double");
    }
    else if(token.compare("FLOAT")){
        create_token("float", FLOAT), add_token("float");
    }
    else if(token.compare("bool")){
        create_token("bool", BOOL), add_token("bool");
    }
    else if(token.compare("while")){
        create_token("while", WHILE), add_token("while");
    }
    else if(token.compare("for")){
        create_token("for", FOR), add_token("for");
    }
    else if(token.compare("do")){
        create_token("do", DO), add_token("do");
    }
    else if(token.compare("import")){
        create_token("import", INCLUDE), add_token("import");
    }
    else if(token.compare("//")){
        create_token("//", COMMENT), add_token("//");
    }
    else if(token.compare("if")){
        create_token("if", IF), add_token("if");
    }
    else if(token.compare("else")){
        create_token("else", ELSE), add_token("else");
    }
    else if(token.compare("switch")){
        create_token("switch", SWITCH), add_token("switch");
    }
    else if(token.compare("case")){
        create_token("case", CASE), add_token("case");
    }
    else if(token.compare("fun")){
        create_token("fun", FUN), add_token("fun");
    }
}


void add_token(std::string token){
    
    if(token != ""){
        list.push_back(token);
    }

}