#pragma once

#include <fstream>
#include <string>
#include <iostream>


namespace rocket{

    namespace file_reader{


        //checks filetype
        bool check_filetype(std::string filepath){
            
            //return true if filetype equals .rckt
            if(filepath.substr(filepath.length() - 5) == ".rckt"){
                
                return 1;
                
            }

            //else returns false and exits program
            return false;


        }


        std::string read_file(std::string filepath){

            //Reads the file content and puts in a string
            std::ifstream ifs(filepath);

            std::string content( (std::istreambuf_iterator<char>(ifs) ),
                (std::istreambuf_iterator<char>()    ) );

            if(content == ""){
                
                //if file content is empty exit program
                std::cout << "The file is empty";
                
                exit(0);
                
            }


            //return file content
            return content;

        }

    }

}