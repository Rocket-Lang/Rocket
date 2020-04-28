#pragma once

#include <string>
#include <vector>

#include "Rocket/parser/parse.cpp"


namespace rocket{

  namespace parser{


    //handles extern expressions or extern definitions
    void handle_extern(){

      rocket::parser::extern_parse();

      // code coming soon ....

    }


    //handles definitions
    void handle_definition(){

      rocket::parser::def_parse();

      // code coming soon ....

    }


    //handles top level expressions like single variables
    void handle_top_expr(){

      rocket::parser::topexpr_parse();

      // code coming soon ....

    }

  }

}
