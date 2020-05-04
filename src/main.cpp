#pragma once

#include <iostream>
#include <string>

#include "src/lexer/lexe.cpp"
#include "src/lexer/file_reader.cpp"
#include "src/parser/ast.cpp"
#include "src/parser/parse.cpp"



namespace rocket{

    namespace main{


        //The Main Function starts the whole Programm
        int main(){

            std::vector<rocket::lexer::Lexeme> t_vector;

            //Initialize classes
            rocket::ast::SubChildNode new_subchild_node;
            rocket::ast::ChildNode new_child_node;
            rocket::ast::RootNode root_node;

            std::string filepath;


            std::cin >> filepath;

            std::cout << "Check out the official Rocket-Lang Github Site \n" << "https://github.com/Rocket-Lang/Rocket";

            bool is_type = rocket::file_reader::check_filetype(filepath);

            if(is_type == false){

                std::cout << "Wrong Filetype! Please use the .rckt filetype for Rocket Files";

                exit(0);

            }

            //Gets the code out of the File and hands it over to the Lexer
            std::string code = rocket::file_reader::read_file(filepath);



            //Calls the Functions for the different tasks and sections
            std::vector<rocket::lexer::Lexeme> lexe = rocket::lexer::lexe(code);

            //calls the parser
            rocket::parser::main_parse(lexe);

        }


    }

}
