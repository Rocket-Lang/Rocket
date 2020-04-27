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

    bool is_paran_expr(std::string cur_token){

      if(cur_token == "("){

        //if token is a opening paranthese -> returns true
        return true;
      }

      //if token is not a opening paranthese -> returns false
      return false;

    }

    bool is_numeric(){

      if(cur_token)

    }

  }

}
