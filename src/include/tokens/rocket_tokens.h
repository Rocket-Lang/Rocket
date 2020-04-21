#ifndef BOOST_TOKENS
#define BOOST_TOKENS

enum datatype_tokens{
    INT,
    STRING,
    CHAR,
    BOOL,
    BYTE,
    DOUBLE,
    FLOAT,
    UINT,
    UBYTE,
    UDOUBLE,
    UFLOAT
};

enum expression_tokens{
    FUN,
    INCLUDE,
    IF,
    IFNOT,
    ELSEIF,
    ELSE,
    SWITCH,
    CASE,
    BREAK,
    CONTINUE,
    RETURN,
    AND,
    OR,
    WHILE,
    FOR,
    DO
};

enum other_tokens{
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,
    TIMES_TIMES,
    PLUS_EQUAL,
    MINUS_EQUAL,
    TIMES_EQUAL,
    PLUS_PLUS,
    MINUS_MINUS,
    DEVIDE_EQUAL,
    OPEN_PARANTHESES,
    CLOSE_PARANTHESES,
    OPEN_BRACKETS,
    CLOSE_BRACKETS,
    OPEN_BRACES,
    CLOSE_BRACES,
    COMMA,
    SEMICOLON,
    EQUAL,
    TIMES,
    PLUS,
    MINUS,
    DEVIDE,
    DOT,
    BACKSLASH,
    MODULO,
    DOUBLE_EQUAL,
    COMMENT,
    COLON,
    EXCLAMATION,
    QUOTATION
};



#endif