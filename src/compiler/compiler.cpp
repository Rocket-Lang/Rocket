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

#include "parser/ast.cpp"

using namespace llvm;


namespace rocket{

    namespace compiler{

      static LLVMContext TheContext;
      static IRBUIDER<> Builder(TheContext);
      static std::unique_ptr<Module> TheModule;
      static std::map<std::string, Value *> NamedValues;

      Value *LogErrorV(const char *Str){

          LogError(Str);
          return nullptr;

      }


      //starts the code generation
      void start_codegen(){

        //code coming soon ....

      }



    }

}
