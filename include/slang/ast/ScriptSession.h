//------------------------------------------------------------------------------
//! @file ScriptSession.h
//! @brief High-level interface to the compiler tools to evaluate snippets of code
//
// SPDX-FileCopyrightText: Michael Popoloski
// SPDX-License-Identifier: MIT
//------------------------------------------------------------------------------
#pragma once

#include "slang/ast/Compilation.h"
#include "slang/ast/EvalContext.h"
#include "slang/syntax/SyntaxFwd.h"
#include "slang/syntax/SyntaxTree.h"

namespace slang::ast {

/// A helper class that allows evaluating arbitrary snippets of SystemVerilog
/// source code and maintaining state across multiple eval calls.
class ScriptSession {
public:
    Compilation compilation;
    CompilationUnitSymbol& scope;

    ScriptSession();

    ConstantValue eval(string_view text);
    ConstantValue evalExpression(const ExpressionSyntax& expr);
    void evalStatement(const StatementSyntax& expr);

    Diagnostics getDiagnostics();

private:
    std::vector<std::shared_ptr<SyntaxTree>> syntaxTrees;
    EvalContext evalContext;
};

} // namespace slang::ast