#pragma once

#include <string>
#include <vector>

#include "Rocket/src/lexer/lexe.cpp"
#include "Rocket/src/parser/ast_llvm_base.cpp"
#include "Rocket/src/compiler/compiler.cpp"
#include "Rocket/src/parser/parsekey.cpp"


namespace rocket{

  namespace parser{

    static int point;


    //starts the parsing process and depending on token calls different parsers
    void main_parse(std::vector<rocket::lexer::Lexeme> lexe){


      auto length = lexe.length();

      while (point <= length){


        if(rocket::parser::is_paran_expr(cur_token())){

          //if value is a ( call paranthese expression parser
          paran_expr();

        }
        else if(rocket::parser::is_numeric(cur_token())){

          //if value is numeric it calls the Number Expression Parser
          number_expr();

        }
        else if(rocket::parser::is_function_expr(cur_token())){

          //if value is a function expression
          function_parser();

        }
        else if(rocket::parser::is_type(cur_token())){

          //if value is a type keyword
          identifier_tokens();

        }

      }

      //after finished and passed everything to the AST it starts
      //the code generation
      rocket::compiler::start_codegen();

    }


    //returns the current token
    std::string cur_token(){

      std::vector<rocket::lexer::Lexeme> lexe;

      auto cur_t = lexe.at(point);

      return cur_t.value;

    }



    //parses Number Expressions
    static std::unique_ptr<ExprAst> number_expr(){

      auto result = std::make_unique<NumberExprAST>(NumVal);

      //skip the number
      getNextToken();

      //return result
      return std::move(result);

    }


    //parses Expressions
    //code not ready yet
    static std::unique_ptr<ExprAst> parse_expr(){

      std::string expression;
      if(cur_token() == "("){

        return;
      }

      //appends new token while the current token is not a closing paranthese
      while (cur_token() != ")"){

        get_next_token();
        expression.append(cur_token());

      }

      return expression;

    }


    //parses Paranthese Expressions
    static std::unique_ptr<ExprAst> paran_expr(){

      //gets next token
      get_next_token();

      auto parse_ret = parse_expr();


      //checks that the next token is there
      if(!parse_ret){
        return nullptr;
      }

      //checks if next token is )
      if(cur_token != ")"){
        LogError(") expected");
      }

      return parse_ret;



    }


    //gets the type and identifier tokens and returns it
    static std::unique_ptr<ExprAst> identifier_tokens(){

      std::string identifier_name = IdentifierStr;

      //gets next token and skips type token
      get_next_token();

      //gets the current identifier token and
      //puts it into the identifier_token variable
      auto identifier_token = cur_token();


      //if theres no identifier token returns null pointer
      if(!identifier_token){
        return nullptr;
      }


      //returns the expression
      return std::make_unique<CallExprAST>(identifier_name, identifier_token);


    }



    //parses Function call Expression
    static std::unique_ptr<FunctionAst> function_parser(){

      //get function name
      auto func = prototype_parser();

      //if func is empty return null pointer
      if(!func){

        return nullptr;
      }

      //parse expression
      if (auto E = parse_expr()){

        return std::make_unique<FunctionAST>(std::move(Proto), std::move(E));
      }

      return nullptr;


    }


    //parses Function
    static std::unique_ptr<PrototypeAst> prototype_parser(){

      //skips the func / fun declaration token
      get_next_token();

      //get identifier from other function
      auto identifier = identifier_tokens();

      std::string function_name = IdentifierStr;


      if(!identifier){
        LogError("identifier expected");
        return nullptr;
      }

      //get next token and check if these are parantheses
      get_next_token();

      if(cur_token != "("){
        LogError("( expected");
      }

      std::vector<std::string> parameters;

      //get next token to skip the opening parathese
      get_next_token()

      //gets every identifier in the parantheses
      while(cur_token() != ")"){

        //skips the type token
        get_next_token();

        //gets the identifier
        parameters.push_back(cur_token());


      }

      //moves the parameters
      return std::make_unique<PrototypeAST>(function_name, std::move(parameters));


      }



    }



    //The Function gets the next token
    rocket::lexer::Lexeme get_next_token(){


      rocket::lexer::lexeme next_node;

      auto next = next_node.at(point);

      //at a call of the function goes forward by 1
      point++;

      //returns the next node
      return next;

    }



  }

}
