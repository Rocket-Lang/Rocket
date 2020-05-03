#pragma once

#include <string>
#include <vector>

#include "src/parser/ast.cpp"


namespace rocket{

    namespace ast{


        //Checks if Node is a new Child Node or Subchild
        bool if_new_child(rocket::lexer::Lexeme next_node ){


            //checks if node value is a keyword for a new child
            if(next_node.value == "fun" || next_node.value == "func" || next_node.value == "type"){

                return true;

            }

            return false;

        }


        //Checks if Root Node is already set
        bool is_root_set(std::string root_node_value, std::string root_node_type){


            //checks if root node type and value not equals an empty string
            if(root_node_type != "" && root_node_value != ""){

                return true;

            }

            return false;

        }




}
