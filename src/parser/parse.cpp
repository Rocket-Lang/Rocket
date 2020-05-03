#pragma once

#include <string>
#include <vector>

#include "src/lexer/lexe.cpp"
#include "src/parser/ast_llvm_base.cpp"
#include "src/compiler/compiler.cpp"
#include "src/parser/parsekey.cpp"


namespace rocket{

  namespace parser{

    static int point;
    static int line = 1;


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
        else if(rocket::parser::is_asm(cur_token())){

          //if value is a inline assembly keyword
          asm_expr();

        }
        else if(cur_token() == "\n"){

          //if value is a new line do nothing and continue


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


    //parses inline assembly expressions
    static std::unique_ptr<ExprAst> asm_expr(){

      //skip the inline assembly keyword
      get_next_token();

      std::vector<std::string> asm_code

      //if token is a opening bracket -> multiline inline assembly
      if(cur_token() == "{"){

        //skip opening bracket
        get_next_token();


        //get all tokens while there is not closing bracket
        while(cur_token() != "}"){

          asm_code.push_back(cur_token());

          get_next_token();

        }


      }

      //check if next token is not a opening bracket
      if(cur_token() != "{"){

        //get all tokens while there is no new line
        while(cur_token() != "\n"){

          //if there is not opening bracket -> oneline inline assembly
          asm_code.push_back(cur_token());

          get_next_token();

      }


      //Add the return statement
      return make_unique<AsmAst> (std::move(asm_code));

    }


    //parses Expressions
    static std::unique_ptr<ExprAst> parse_expr(){

      auto LHS = primary_parse();

      if (!LHS){

        return nullptr;

      }

      return parse_rhs(0, std::move(LHS));
    }


    //parses left side of expression
    static std::unique_ptr<ExprAst> primary_parse(){

      //code coming soon ....


    }


    //merges LHS and RHS
    static std::unique_ptr<ExprAst> parse_rhs(int precendence,
      std::unique_ptr<ExprAst> LHS){

      //code coming soon ....



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

      if(next.value == "\n"){

        //if the next token is a new line add 1 to the line counter
        rocket::parsing::line++;
      }

      //at a call of the function goes forward by 1
      point++;

      //returns the next node
      return next;

    }



  }

}
