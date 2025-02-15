/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the LICENSE
 * file in the root directory of this source tree.
 */
#include "hermes/Support/SimpleDiagHandler.h"

#include "llvm/ADT/Twine.h"

using llvm::Twine;

namespace hermes {

void SimpleDiagHandler::installInto(hermes::SourceErrorManager &sm) {
  sm.setDiagHandler(handler, this);
}

void SimpleDiagHandler::handler(const llvm::SMDiagnostic &msg, void *ctx) {
  auto *mgr = static_cast<SimpleDiagHandler *>(ctx);
  if (msg.getKind() == llvm::SourceMgr::DK_Error) {
    if (!mgr->hasFirstMessage()) {
      mgr->firstMessage_ = msg;
    }
  }
}

std::string SimpleDiagHandler::getErrorString() const {
  const auto &msg = getFirstMessage();
  return (Twine(msg.getLineNo()) + ":" + Twine(msg.getColumnNo()) + ":" +
          msg.getMessage())
      .str();
}

SimpleDiagHandlerRAII::SimpleDiagHandlerRAII(
    SourceErrorManager &sourceErrorManager)
    : sourceErrorManager_(sourceErrorManager),
      oldHandler_(sourceErrorManager.getDiagHandler()),
      oldContext_(sourceErrorManager.getDiagContext()),
      oldErrorLimit_(sourceErrorManager.getErrorLimit()) {
  installInto(sourceErrorManager);
  sourceErrorManager.clearErrorLimitReached();
  sourceErrorManager.setErrorLimit(1);
}

SimpleDiagHandlerRAII::~SimpleDiagHandlerRAII() {
  sourceErrorManager_.clearErrorLimitReached();
  sourceErrorManager_.setErrorLimit(oldErrorLimit_);
  sourceErrorManager_.setDiagHandler(oldHandler_, oldContext_);
}

} // namespace hermes
