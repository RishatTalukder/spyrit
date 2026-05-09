#ifndef AST_H
#define AST_H

typedef enum ASTNodeType
{
    AST_VARIABLE_DECLARATION,
    AST_OUTPUT_STATEMENT,
} ASTNodeType;

typedef struct VariableDeclairation
{
    char name[256];
    char type[256];
} VariableDeclairation;

typedef struct OutputStatement
{
    char expression[256];
} OutputStatement;

typedef struct ASTNode
{
    ASTNodeType type;

    union
    {
        VariableDeclairation variable_decl;
        OutputStatement output_stmt;
    };

} ASTNode;

void print_ast_node(ASTNode *node);

#endif
