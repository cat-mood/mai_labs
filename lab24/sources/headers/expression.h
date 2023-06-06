#pragma once

typedef enum {
    TOKEN_NONE,
    TOKEN_VAR_NAME,
    TOKEN_CONST,
    TOKEN_OPER,
    TOKEN_BR_R,
    TOKEN_BR_L
} token_type;

typedef enum {
    BR,
    LOW,
    MIDDLE,
    HIGH
} priority;

typedef enum {
    LEFT,
    RIGHT
} oper_associativity;

typedef struct {
    char var_name[50];
    double cnst;
    char oper;
    priority oper_priority;
    oper_associativity oper_assoc;
    token_type type;
} token;

typedef enum {
    TOKEN_READ_OK,
    TOKEN_READ_END,
    TOKEN_READ_ERROR
} token_read_result;

typedef enum {
    EXPR_READ_OK,
    EXPR_READ_END,
    EXPR_READ_ERROR
} expr_read_result;
