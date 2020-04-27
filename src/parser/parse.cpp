#pragma once

#include <string>
#include <vector>

#include "Rocket/src/lexer/lexe.cpp"
#include "Rocket/src/parser/ast_llvm_base.cpp"
#include "Rocket/src/compiler/compiler.cpp"


namespace rocket{

  namespace parser{

    static int point;


    //starts the parsing process and depending on token calls different parsers
    void main_parse(std::vector<rocket::lexer::Lexeme> lexe){


      auto length = lexe.length();

      while (point <= length){


        if(cur_token() == "("){

          //if value is a ( call paranthese expression parser
          paran_expr();

        }
        else if(cur_token() == ){

          //if value is numeric it calls the Number Expression Parser
          number_expr();

        }
        else if(cur_token() == ){

          //if value is a function expression
          function_parser();

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

      //code coming soon ....

    }


    //parses Expressions
    static std::unique_ptr<ExprAst> parse_expr(){

      std::string expression;
      if(cur_token() == ")"){

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

      //checks that the next token is not
      if(!parse_ret){
        return nullptr;
      }

      //checks if next token is )
      if(cur_token != ")"){
        LogError(") expected");
      }

      return parse_ret;



    }


    //parses Function Expressions
    static std::unique_ptr<ExprAst> function_parser(){

      //code coming soon ...


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
