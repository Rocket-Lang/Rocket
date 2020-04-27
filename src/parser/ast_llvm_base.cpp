#pragma once

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>


#include <string>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>


#include "Rocket/src/lexer/lexe.cpp"
#include "Rocket/src/lexer/lexeme.cpp"
#include "Rocket/src/parser/lexemecheck.cpp"

using namespace llvm;

namespace rocket{

    namespace ast{

      class ExprAST {
        public:
          virtual ~ExprAST() = default;

          virtual Value *codegen() = 0;
        };

        /// NumberExprAST - Expression class for numeric literals like "1.0".
        class NumberExprAST : public ExprAST {
          double Val;

          public:
            NumberExprAST(double Val) : Val(Val) {}
            virtual Value *codegen();

          Value *codegen() override;
        };

        /// VariableExprAST - Expression class for referencing a variable, like "a".
        class VariableExprAST : public ExprAST {
          std::string Name;

          public:
            VariableExprAST(const std::string &Name) : Name(Name) {}
            virtual Value *codegen

          Value *codegen() override;
        };

        /// BinaryExprAST - Expression class for a binary operator.
        class BinaryExprAST : public ExprAST {
        char Op;
        std::unique_ptr<ExprAST> LHS, RHS;

        public:
          BinaryExprAST(char Op, std::unique_ptr<ExprAST> LHS,
                      std::unique_ptr<ExprAST> RHS)
            : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
          virtual Value *codegen();

        Value *codegen() override;
        };

        /// CallExprAST - Expression class for function calls.
        class CallExprAST : public ExprAST {
        std::string Callee;
        std::vector<std::unique_ptr<ExprAST>> Args;

        public:
          CallExprAST(const std::string &Callee,
                    std::vector<std::unique_ptr<ExprAST>> Args)
            : Callee(Callee), Args(std::move(Args)) {}
          virtual Value *codegen();

        Value *codegen() override;
        };

        /// PrototypeAST - This class represents the "prototype" for a function,
        /// which captures its name, and its argument names (thus implicitly the number
        /// of arguments the function takes).
        class PrototypeAST {
        std::string Name;
        std::vector<std::string> Args;

        public:
          PrototypeAST(const std::string &Name, std::vector<std::string> Args)
            : Name(Name), Args(std::move(Args)) {}
          virtual Value *codegen();

        Function *codegen();
        const std::string &getName() const { return Name; }
        };

        /// FunctionAST - This class represents a function definition itself.
        class FunctionAST {
          std::unique_ptr<PrototypeAST> Proto;
          std::unique_ptr<ExprAST> Body;

        public:
          FunctionAST(std::unique_ptr<PrototypeAST> Proto,
                    std::unique_ptr<ExprAST> Body)
            : Proto(std::move(Proto)), Body(std::move(Body)) {}
          virtual Value *codegen();

        Function *codegen();
        };


    }

}
