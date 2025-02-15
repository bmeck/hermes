# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE
# file in the root directory of this source tree.

set(LLVM_LINK_COMPONENTS support)

add_llvm_library(hermesOptimizer
  STATIC
  Optimizer/PassManager/Pipeline.cpp
  Optimizer/Scalar/SimplifyCFG.cpp
  Optimizer/Scalar/CSE.cpp
  Optimizer/Scalar/CodeMotion.cpp
  Optimizer/Scalar/DCE.cpp
  Optimizer/Scalar/Mem2Reg.cpp
  Optimizer/Scalar/TypeInference.cpp
  Optimizer/Scalar/StackPromotion.cpp
  Optimizer/Scalar/InstSimplify.cpp
  Optimizer/Scalar/Auditor.cpp
  Optimizer/Scalar/SimpleCallGraphProvider.cpp
  Optimizer/Scalar/ResolveStaticRequire.cpp
  Optimizer/Scalar/SimpleCallGraphProvider.cpp
  Optimizer/Scalar/FuncSigOpts.cpp
  Optimizer/Scalar/BundlerUtils.cpp
  Optimizer/Scalar/Utils.cpp
  Optimizer/Scalar/Inlining.cpp
  Optimizer/Scalar/HoistStartGenerator.cpp
  Optimizer/Scalar/InstructionEscapeAnalysis.cpp
  Optimizer/Scalar/TDZDedup.cpp
  IR/Analysis.cpp
  IR/IREval.cpp
)

add_llvm_library(hermesFrontend
  STATIC
  IRGen/IRGen.cpp
  IRGen/ESTreeIRGen.cpp IRGen/ESTreeIRGen.h
  IRGen/ESTreeIRGen-expr.cpp
  IRGen/ESTreeIRGen-stmt.cpp
  IRGen/ESTreeIRGen-func.cpp
  IRGen/ESTreeIRGen-except.cpp
  IR/IR.cpp
  IR/CFG.cpp
  IR/IRBuilder.cpp
  IR/IRVerifier.cpp
  IR/Instrs.cpp
  Utils/Dumper.cpp
  LINK_LIBS hermesSupport hermesInst hermesAST
)

add_subdirectory(VM)
add_subdirectory(Inst)
add_subdirectory(CompilerDriver)
add_subdirectory(AST)
add_subdirectory(FlowParser)
add_subdirectory(Parser)
add_subdirectory(SourceMap)
add_subdirectory(Support)
add_subdirectory(BCGen)
add_subdirectory(ConsoleHost)
add_subdirectory(Regex)
add_subdirectory(Platform)
