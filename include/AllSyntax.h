#pragma once

#include "SyntaxNode.h"
#include "Token.h"

// This file contains all parse tree syntax nodes.
// It is auto-generated by the syntax_gen.py script under the tools/ directory.

namespace slang {

// ----- EXPRESSIONS -----

struct ExpressionSyntax : public SyntaxNode {

    ExpressionSyntax(SyntaxKind kind) :
        SyntaxNode(kind)
    {
    }
};

struct PrefixUnaryExpressionSyntax : public ExpressionSyntax {
    Token* operatorToken;
    ExpressionSyntax* operand;

    PrefixUnaryExpressionSyntax(SyntaxKind kind, Token* operatorToken, ExpressionSyntax* operand) :
        ExpressionSyntax(kind), operatorToken(operatorToken), operand(operand)
    {
        childCount += 2;
    }

protected:
    TokenOrSyntax getChild(uint32_t index) const override final {
        switch(index) {
            case 0: return operatorToken;
            case 1: return operand;
            default: return nullptr;
        }
    }
};

struct BinaryExpressionSyntax : public ExpressionSyntax {
    ExpressionSyntax* left;
    Token* operatorToken;
    ExpressionSyntax* right;

    BinaryExpressionSyntax(SyntaxKind kind, ExpressionSyntax* left, Token* operatorToken, ExpressionSyntax* right) :
        ExpressionSyntax(kind), left(left), operatorToken(operatorToken), right(right)
    {
        childCount += 3;
    }

protected:
    TokenOrSyntax getChild(uint32_t index) const override final {
        switch(index) {
            case 0: return left;
            case 1: return operatorToken;
            case 2: return right;
            default: return nullptr;
        }
    }
};

struct PrimaryExpressionSyntax : public ExpressionSyntax {

    PrimaryExpressionSyntax(SyntaxKind kind) :
        ExpressionSyntax(kind)
    {
    }
};

struct LiteralExpressionSyntax : public PrimaryExpressionSyntax {
    Token* literal;

    LiteralExpressionSyntax(SyntaxKind kind, Token* literal) :
        PrimaryExpressionSyntax(kind), literal(literal)
    {
        childCount += 1;
    }

protected:
    TokenOrSyntax getChild(uint32_t index) const override final {
        switch(index) {
            case 0: return literal;
            default: return nullptr;
        }
    }
};

// ----- DIRECTIVES -----

struct DirectiveSyntax : public SyntaxNode {
    Token* directive;
    Token* endOfDirective;

    DirectiveSyntax(SyntaxKind kind, Token* directive, Token* endOfDirective) :
        SyntaxNode(kind), directive(directive), endOfDirective(endOfDirective)
    {
        childCount += 2;
    }

protected:
    TokenOrSyntax getChild(uint32_t index) const override {
        switch(index) {
            case 0: return directive;
            case 1: return endOfDirective;
            default: return nullptr;
        }
    }
};

struct IncludeDirectiveSyntax : public DirectiveSyntax {
    Token* fileName;

    IncludeDirectiveSyntax(Token* directive, Token* endOfDirective, Token* fileName) :
        DirectiveSyntax(SyntaxKind::IncludeDirective, directive, endOfDirective), fileName(fileName)
    {
        childCount += 1;
    }

protected:
    TokenOrSyntax getChild(uint32_t index) const override final {
        switch(index) {
            case 0: return directive;
            case 1: return endOfDirective;
            case 2: return fileName;
            default: return nullptr;
        }
    }
};

struct MacroArgumentDefaultSyntax : public SyntaxNode {
    Token* equals;
    TokenList tokens;

    MacroArgumentDefaultSyntax(Token* equals, TokenList tokens) :
        SyntaxNode(SyntaxKind::MacroArgumentDefault), equals(equals), tokens(tokens)
    {
        childCount += 2;
    }

protected:
    TokenOrSyntax getChild(uint32_t index) const override final {
        switch(index) {
            case 0: return equals;
            case 1: return &tokens;
            default: return nullptr;
        }
    }
};

struct MacroFormalArgumentSyntax : public SyntaxNode {
    Token* name;
    MacroArgumentDefaultSyntax* defaultValue;

    MacroFormalArgumentSyntax(Token* name, MacroArgumentDefaultSyntax* defaultValue) :
        SyntaxNode(SyntaxKind::MacroFormalArgument), name(name), defaultValue(defaultValue)
    {
        childCount += 2;
    }

protected:
    TokenOrSyntax getChild(uint32_t index) const override final {
        switch(index) {
            case 0: return name;
            case 1: return defaultValue;
            default: return nullptr;
        }
    }
};

struct MacroFormalArgumentListSyntax : public SyntaxNode {
    Token* openParen;
    SeparatedSyntaxList<MacroFormalArgumentSyntax> args;
    Token* closeParen;

    MacroFormalArgumentListSyntax(Token* openParen, SeparatedSyntaxList<MacroFormalArgumentSyntax> args, Token* closeParen) :
        SyntaxNode(SyntaxKind::MacroFormalArgumentList), openParen(openParen), args(args), closeParen(closeParen)
    {
        childCount += 3;
    }

protected:
    TokenOrSyntax getChild(uint32_t index) const override final {
        switch(index) {
            case 0: return openParen;
            case 1: return &args;
            case 2: return closeParen;
            default: return nullptr;
        }
    }
};

struct DefineDirectiveSyntax : public DirectiveSyntax {
    Token* name;
    MacroFormalArgumentListSyntax* formalArguments;
    TokenList body;

    DefineDirectiveSyntax(Token* directive, Token* endOfDirective, Token* name, MacroFormalArgumentListSyntax* formalArguments, TokenList body) :
        DirectiveSyntax(SyntaxKind::DefineDirective, directive, endOfDirective), name(name), formalArguments(formalArguments), body(body)
    {
        childCount += 3;
    }

protected:
    TokenOrSyntax getChild(uint32_t index) const override final {
        switch(index) {
            case 0: return directive;
            case 1: return endOfDirective;
            case 2: return name;
            case 3: return formalArguments;
            case 4: return &body;
            default: return nullptr;
        }
    }
};

}