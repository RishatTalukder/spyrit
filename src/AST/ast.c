#include <stdio.h>
#include "ast.h"

void print_ast_node(ASTNode *node) {
    switch (node->type)
    {
    case AST_VARIABLE_DECLARATION:
        printf("VariableDeclaration(\n");
            printf("    name = %s\n", node->variable_decl.name);
            printf("    type = %s\n", node->variable_decl.type);
            printf(")\n");
        break;

    case AST_OUTPUT_STATEMENT:
        printf("OutputStatement(\n");
            printf("    expression = %s\n", node->output_stmt.expression);
            printf(")\n");
        break;
    
    default:
    printf("Unknown node type\n");
        break;
    }
}