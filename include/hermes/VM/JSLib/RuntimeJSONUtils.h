/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the LICENSE
 * file in the root directory of this source tree.
 */
#ifndef HERMES_VM_JSLIB_RUNTIMEJSONPARSER_H
#define HERMES_VM_JSLIB_RUNTIMEJSONPARSER_H

#include "hermes/VM/Runtime.h"

namespace hermes {
namespace vm {

/// Parse JSON string \p jsonString according to ES5.1 15.12.1 and 15.12.2.
CallResult<HermesValue> runtimeJSONParse(
    Runtime *runtime,
    Handle<StringPrimitive> jsonString,
    Handle<Callable> reviver);

/// Returns a String in JSON format representing an ECMAScript value,
/// according to 15.12.3.
CallResult<HermesValue> runtimeJSONStringify(
    Runtime *runtime,
    Handle<> value,
    Handle<> replacer,
    Handle<> space);

} // namespace vm
} // namespace hermes

#endif
