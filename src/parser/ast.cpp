#pragma once

#include <string>
#include <vector>

#include "Rocket/src/lexer/lexe.cpp"
#include "Rocket/src/lexer/lexeme.cpp"
#include "Rocket/src/parser/lexemecheck.cpp"


namespace rocket{

    namespace ast{

        //Node Class
        class RootNode{

            public:
            
                std::string type;
                std::string value;
                std::vector<ChildNode> child_node;
                

        };

        //Child Node Class
        class ChildNode{
            
            public:
                
                std::string type;
                std::string value;
                std::vector<SubChildNode> sub_childs;
                RootNode *parent_node;


        };

        //Sub Child Node Class
        class SubChildNode{
            
            public:
                
                std::string type;
                std::string value;
                ChildNode *parent_node;


        };


        //Function for start building the AST
        void start_build(std::vector<rocket::lexer::Lexeme> t_vector, SubChildNode new_subchild_node, ChildNode new_child_node, RootNode root_node){
            
            int position = 0;

            int vec_size = sizeof(t_vector);


            //Check if Root Node is set
            bool is_root = rocket::ast::is_root_set(root_node.value, root_node.type);

            //Sets Root Node values
            if(is_root == false){

                root_node.type = "ROOT";
                root_node.value = "";

            }


            //Get next Node (Class) from Vector while position less than or equal
            while(position <= vec_size){
                
                rocket::lexer::Lexeme next_node = get_next_node(t_vector ,position);

                bool is_child = rocket::ast::if_new_child(next_node);

                if(is_child){
                    
                    //Creates a new Child Node
                    create_new_child(next_node, new_child_node, root_node);

                }

                //If Node is not a new Child Node -> creates new SubChild 

                create_new_subchild(next_node, new_subchild_node, new_child_node);
                
            }

        }


        //Function that gets next Lexeme
        rocket::lexer::Lexeme get_next_node(std::vector<rocket::lexer::Lexeme> next_node, int position){
            
            rocket::lexer::Lexeme lexeme;

            //next Node
            lexeme = next_node.at(position);


            return lexeme;
            
        }


        //Function to create a new Child Node
        void create_new_child(rocket::lexer::Lexeme next_node, ChildNode new_child_node, RootNode root_node){
            
            //Add values
            new_child_node.type = next_node.key;
            new_child_node.value  = next_node.value;
            new_child_node.parent_node = &root_node;


            //push it to Child Vector
            root_node.child_node.push_back(new_child_node);


        }


        //Function to create a new SubChild Node
        void create_new_subchild(rocket::lexer::Lexeme next_node, SubChildNode new_subchild_node, ChildNode child_node){
            
            //Add values 
            new_subchild_node.type = next_node.key;
            new_subchild_node.value = next_node.value;
            new_subchild_node.parent_node = &child_node; 


            //push it to SubChild vector
            child_node.sub_childs.push_back(new_subchild_node);
            

        }



    }

}
