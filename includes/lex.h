#ifndef __LEX_H__
#  define __LEX_H__

extern int yylex();
extern void yyerror(char*);
extern void RemoveDQuote(char*);

#endif /* End of __LEX_H__ */
