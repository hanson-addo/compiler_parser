%{
#include <stdlib.h>
#include <stdio.h>
#include "mython.tab.h"

int lineno = 1;
%}
%%
and		{yylval.op = '&';return AND;}
def		{return DEF_T;}
elihw		{return ELIHW_T;}
else		{return ELSE_T;}
false		{
                yylval.name=strdup(yytext);
                return FALSE_T;
            }
fed		{return FED_T;}
fi		{return FI_T;}
if		{return IF_T;}
input		{return INPUT_T;}
not		{return NOT;}
or		{return OR;}
print		{return PRINT_T;}
return		{return RETURN_T;}
true		{
                yylval.name=strdup(yytext);
                return TRUE_T;
            }
while		{return WHILE_T;}
\+		{yylval.op = '+';return PLUS;}
\-		{yylval.op = '-';return MINUS;}
\*		{yylval.op = '*';return MULT;}
\!		{yylval.op = '!';return NOT;}
\=\=		{return EQ;}
\>\=		{return GE;}
\<\=		{return LE;}
\<\>		{return NE;}
\<		{return LT;}
\>		{return GT;}
\=		{return ASSIGN;}
\,		{return COMMA;}
\:		{return COLON;}
\(		{return LP;}
\)		{return RP;}
\[		{return LB;}
\]		{return RB;}
"//".*		;
[0-9]*		{
                yylval.name=strdup(yytext);
                return INT_LIT;
            }
[a-z][a-zA-Z0-9_]*	{
                        yylval.name=strdup(yytext);
                        return ID;
                    }
[ \t]		;
[\n]		{lineno++;}
%%
