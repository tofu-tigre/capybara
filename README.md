

<program> := [ <func-decl> ]

<func-decl> :=
  FN IDENTIFIER LEFT_PAREN RIGHT_PAREN ARROW <type-id> LEFT_CURLY [ <stmt> ] RIGHT_CURLY

<stmt> :=
  ( <var-decl> | <return-stmt> | <expr> ) SEMICOLON |
  LEFT_CURLY [ <stmt> ] RIGHT_CURLY |
  SEMICOLON

<var-decl> :=
  LET IDENTIFIER |
  LET IDENTIFIER COLON <type-id> 
  LET IDENTIFIER EQUAL <expr>

<return-stmt> :=
  RETURN |
  RETURN <expr>

<expr> :=
  <primary-expr> [ ( PLUS | MINUS ) <primary-expr> ]

<primary-expr> :=
  CONSTANT | IDENTIFIER | LEFT_PAREN <expr> RIGHT_PAREN

<type-id> :=
  U8 | U16 | U32 | U64 |
  I8 | I16 | I32 | I64 |
