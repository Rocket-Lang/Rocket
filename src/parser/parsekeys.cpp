#pragma once

#include <string>


namespace rocket{

  namespace parser{


    //checks if current token is a function expression token
    bool is_func_expr(std::string cur_token){

      if(cur_token == "fun" || cur_token == "func"){

        //if token is a function keyword -> returns true
        return true;
      }

      //if token is not a function keyword -> returns false
      return false;

    }


    //checks if the cur_token is paranthese expression
    bool is_paran_expr(std::string cur_token){

      if(cur_token == "("){

        //if token is a opening paranthese -> returns true
        return true;
      }

      //if token is not a opening paranthese -> returns false
      return false;

    }


    //checks if the cur_token is numeric
    bool is_numeric(std::string cur_token){

      //gets the length of the token
      int token_length = cur_token.length();

      for(int i = 0; i <= token_length; i++){

        //gets every single char of the string to check if its a
        //numeric one
        auto check = cur_token[i];

        if(check < 47 &&  check > 58){

          //if its not numeric -> returns false
          return false;

        }

        //if its numeric -> returns true
        return true;


      }


    //checks if the current token is a type keyword
    bool is_type(std::string cur_token){

      //check if type
      if(cur_token == "int" || cur_token == "float" || cur_token == "double" ||
         cur_token == "uint"|| cur_token == "char"  || cur_token == "string" ||
         cur_token == "bool"|| cur_token == "byte"  ){


           //if current token is a type keyword -> returns true
           return true;

      }

      //if current token is not a type keyword -> returns false
      return false;

    }


    //checks if the current token is a inline assembly keyword
    bool is_asm(std::string cur_token){

      //check if asm token
      if(cur_token == "asm"){

        //if the current token is a inline assembly keyword -> returns true
        return true;

      }

      //if current token is not a inline assembly keyword -> returns false
      return false;

    }



  }

}
