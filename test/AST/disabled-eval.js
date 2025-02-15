// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the LICENSE
// file in the root directory of this source tree.
//
// RUN: (%hermes -hermes-parser -enable-eval=false -non-strict %s 2>&1 || true) | %FileCheck %s --match-full-lines

var eval;
//CHECK: {{.*}}disabled-eval.js:8:5: error: 'eval' is disabled
//CHECK-NEXT: var eval;
//CHECK-NEXT:     ^~~~

eval("print(1)");
//CHECK: {{.*}}disabled-eval.js:13:1: error: 'eval' is disabled
//CHECK-NEXT: eval("print(1)");
//CHECK-NEXT: ^~~~
