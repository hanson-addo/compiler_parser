%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int lineno;
extern char* yytext;
extern int yylex();

typedef struct SymbolNode {
    char* name;
    int lineno;
    int type; //1=int, 2==boolean, 3==Array, 4==ArrayFunc, 5==Intfucnt, 6==BooleanF , 7==Procedure, 8==defFunc,9==file, 10 == error
    int param;
    struct SymbolNode* next;
} SymbolNode;

typedef struct SymbolTable {
    SymbolNode* head;
    struct SymbolTable* parent;
} SymbolTable;

void enterScope();
void exitScope();
void insert(char* name, int lineno,int type,int param);
int lookup(char* name, int lineno);
int lookupType(char* name_1);
int updateVar(char* name, int type);
int getTopType();

SymbolTable* current_scope = NULL;
char* dataType[]={NULL,"Integer","Boolean","Array","ArrayFunc","Intfunction","BooleanF","Procedure","defFunct"};
int paramCount = 0;
int frq = 0;
int begin = 0;
%}

%union{
    int val;
    char* name;
    int boolean;
    char op;
    }
%token DEF_T FED_T IF_T FI_T ELSE_T WHILE_T ELIHW_T
%token INPUT_T PRINT_T RETURN_T 
%token ID INT_LIT
%token RP LP RB LB COMMA COLON
%token ASSIGN TRUE_T FALSE_T 
%nonassoc OR
%nonassoc AND 
%nonassoc LT LE GT GE EQ NE
%right NOT
%left PLUS MINUS '+' '-'
%left MULT '*'

%type<name> exp ID TRUE_T FALSE_T 
%type<val> INT_LIT


%%

program		:	{enterScope();}function_list end_list {exitScope();}            
		    ;

function_list	: function_list {enterScope(); paramCount = 0; begin = 1;} function
		        |	
		        ;

function        :   DEF_T ID LP parameters RP COLON statements FED_T {exitScope();}
                {   
                    if(lookup($2,lineno)== 0){
                        printf("Line %d: Duplicate function in scope: %s\n", lineno-begin, $2);
                    }else{
                        insert($2,lineno,8,paramCount);//add paramcount for function only
                    }                        
                } 
                |       DEF_T ID LP RP COLON statements  FED_T 
                {
                    if(lookup($2,lineno)== 0){
                        printf("Line %d: Duplicate function in scope: %s\n", lineno-begin, $2);
                    }else{
                        insert($2,lineno,8,paramCount);//add paramcount for function only
                    }
                }                 
		        ;

parameters	:	parameters COMMA ID 
            {   
                paramCount++;    
                if(lookup($3,lineno)== 0){
                    printf("Line %d: Duplicate variable in scope: %s\n", lineno, $3);
                }else{
                    insert($3,lineno,1,-1);
                }
            }
		    |	parameters COMMA ID LB RB 
            {
                paramCount++;
                if(lookup($3,lineno)== 0){
                    printf("Line %d: Duplicate variable in scope: %s\n", lineno, $3);
                }else{
                    insert($3,lineno,3,-1);
                }
            }
            |	ID
            {
                paramCount++;
                if(lookup($1,lineno)== 0){
                    printf("Line %d: Duplicate variable in scope: %s\n", lineno, $1);
                }else{
                    insert($1,lineno,-1,-1);
                }
            }
            |	ID LB RB 
            {   
                paramCount++;
                if(lookup($1,lineno)== 0){
                    printf("Line %d: Duplicate variable in scope: %s\n", lineno, $1);
                }else{
                    insert($1,lineno,3,-1);
                }
                
            }
            ;

statements	:	statements {begin++;}statement
            |	{begin++;}statement
            ;
statement       :       assignment_stmt
                |       print_stmt
                |       input_stmt
                |       condition_stmt
                |       while_stmt
                |       call_stmt
		        |	    return_stmt
                ;

return_stmt     :       RETURN_T exp {begin =1;}
                {
                    if(lookupType($2) == 8 ){
                        printf("Line %d: Recursive function not supported: %s\n", lineno, $2);
                    }
                }
                |       RETURN_T{begin =1;}
                ;

call_stmt       :       ID LP RP //y()
                {
                    if(lookup($1,lineno)==-1){
                        printf("Line %d: Function not declared: %s\n", lineno, $1);
                    }
                    if((lookup($1,lineno)== 0) && (lookupType($1)== 8) && (getParam($1) != frq)){//if exist
                        printf("Line %d: Illegal number of parameters: function : %s\n", lineno, $1);
                    }
                    
                }
                |      ID LP {frq = 0;}param_list RP //y(x)
                {
                    if(lookup($1,lineno)==-1){ //does not exist
                        printf("Line %d: Function not declared: %s\n", lineno, $1);
                    }
                    if((lookup($1,lineno)== 0) && (lookupType($1)== 8) && (getParam($1) != frq)){//if exist
                        printf("Line %d: Illegal number of parameters: function : %s\n", lineno, $1);
                    }
                    
                }
                ;

assignment_stmt :       ID ASSIGN exp //x=1
                {
                    if(lookup($1,lineno) == 0 ){//if it exists
                        if(lookupType($1) == lookupType($3)){
                            updateVar($1,lookupType($3));
                        }else{
                            printf("Line %d: Type mismatch in assignment statement\n", lineno);
                        }                       
                    }else{
                        insert($1,lineno,lookupType($3),getParam($1));
                    }
                             
                }
                |       ID LB exp RB ASSIGN exp //a[i]=1
                {
                    if(lookup($1,lineno) == 0 ){//if it exists
                        if(lookupType($1) == lookupType($6)){
                            updateVar($1,lookupType($6));
                        }if(lookupType($6) != 1){
                            printf("Line %d: Can only assign integers to arrays\n", lineno);
                        }if(lookupType($3) != 1){
                            printf("Line %d: Array indices must be type integer\n", lineno);
                        }if(lookupType($1) != 3){
                            printf("Line %d: Use of non-array type as an array: %s\n", lineno,$1);
                        }
                        else{
                            printf("Line %d: Type mismatch in assignment statement\n", lineno);
                        }                       
                    }else{
                        insert($1,lineno,lookupType($6),getParam($1));
                    }
                }
                ;

exp             :       exp EQ exp
                {
                    if((lookupType($1) != 1) || (lookupType($3) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
                |       exp NE exp
                {
                    if((lookupType($1) != 1) || (lookupType($3) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
                |       exp LT exp
                {
                    if((lookupType($1) != 1) || (lookupType($3) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
                |       exp LE exp
                {
                    if((lookupType($1) != 1) || (lookupType($3) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
                |       exp GT exp
                {
                    if((lookupType($1) != 1) || (lookupType($3) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
                |       exp GE exp
                {
                    if((lookupType($1) != 1) || (lookupType($3) != 1)){
                        printf("Line %d: Illegal types in expression operator and expects Integer\n", lineno);
                    }
                }
                |       exp AND exp
                {
                    if((lookupType($1) != 2) || (lookupType($3) != 2)){
                        printf("Line %d: Illegal types in expression operator and expects Boolean\n", lineno);
                    }

                }
                |       exp OR exp
                {
                    if((lookupType($1) != 2) || (lookupType($3) != 2)){
                        printf("Line %d: Illegal types in expression operator and expects Boolean\n", lineno);
                    }
                }
                |       NOT exp 
                {

                }
                |       exp PLUS exp
                {
                    if((lookupType($1) != 1) || (lookupType($3) != 1)) {
                        printf("Line %d: Illegal types in expression operator + expects Integers\n", lineno);
                    }
                    if(lookupType($1) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,$1);
                    }
                    if(lookupType($3) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,$3);
                    }
                }
                |       exp MINUS exp
                {
                    if((lookupType($1) != 1) || (lookupType($3) != 1)){
                        printf("Line %d: Illegal types in expression operator - expects Integers\n", lineno);
                    }
                    if(lookupType($1) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,$1);
                    }
                    if(lookupType($3) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,$3);
                    }

                }
                |       exp MULT exp
                {
                    if((lookupType($1) != 1) || (lookupType($3) != 1)){
                        printf("Line %d: Illegal types in expression operator * expects Integers\n", lineno);
                    }
                    if(lookupType($1) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,$1);
                    }
                    if(lookupType($3) == 8){
                        printf("Line %d: Illegal function usage: %s\n", lineno,$3);
                    }
                }
                |       MINUS exp // -x or -3
                {
                     if(lookupType($2) != 1){
                        printf("Line %d: Illegal types in expression operator expects Integers\n", lineno);
                    }
                }
                |       LP exp RP  //(x) or(x+y)....
                {
                    if(lookup($2,lineno)== -1){ //not exist
                        printf("Line %d: Undefined variable: %s\n", lineno, $2);
                    }else{

                    }
                }
                |       ID LB exp RB //a[1]
                {
                    if(lookup($1,lineno)==-1){
                        printf("Line %d: Array not declared: %s\n", lineno, $1);
                    }
                    
                }
                |       ID LP RP  // a()
                {
                    if(lookup($1,lineno)==-1){
                        printf("Line %d: Function not declared: %s\n", lineno, $1);
                    }if(lookupType($1) != 8){
                        printf("Line %d: Non-function variable used as a function: %s\n", lineno, $1);
                    }
                    
                }
                |       ID  LP param_list RP  // y(x)
                {
                    if(lookup($1,lineno)==-1){//not exist
                        printf("Line %d: Function not declared: %s\n", lineno, $1);
                    }if(lookupType($1) != 8){
                        printf("Line %d: Non-function variable used as a function: %s\n", lineno, $1);
                    }
                    
                }
                |       INT_LIT // 3,4 ....
                {
                    insert((char *)$1,lineno,1,-1);
                    $$ = $1;
                }
                |       ID  // x or 4 ...
                {
                    if(lookup($1,lineno)==-1){
                        printf("Line %d: Undefined variable: %s\n", lineno, $1);
                    }
                    $$ = $1;
                    
                }
                |       TRUE_T
                {
                    insert($1,lineno,2,-1);
                }
                |       FALSE_T
                {
                    insert($1,lineno,2,-1);
                }
                ;

int_list        :       int_list COMMA INT_LIT
                |       INT_LIT
                ;

print_stmt      :       PRINT_T exp 
                {
                    if(lookupType($2) != 1 && lookupType($2) != 9){ //if its a boolean
                        printf("Line %d: Print statement expect integers: %s\n", lineno, $2);
                    }
                }
                ;

input_stmt      :       ID ASSIGN INPUT_T 
                {
                    if(lookup($1,lineno) == 0 && lookupType($1) != 9 && lookupType($1) != -1){
                        printf("Line %d: Can only input integer type: %s\n", lineno, $1);
                    }else{
                        insert($1,lineno,9,-1);
                    }
                    
                    
                }
                ;

condition_stmt  :       IF_T exp COLON {begin =1;} statements optional_else FI_T 
                {
                    if(lookupType($2) != 2){
                        printf("Line %d: While statement requires boolean condition \n", lineno-begin);
                    }
                }
                ;

optional_else	:	ELSE_T COLON statements
                |
                ;

while_stmt      :       WHILE_T  exp {begin =1;}COLON statements ELIHW_T 
                {
                    if(lookupType($2) != 2){
                        printf("Line %d: While statement requires boolean condition \n", lineno-begin);
                    }
                }
                ;

param_list      :       param_list COMMA exp 
                {
                    frq++;

                }
                |       exp 
                {
                    frq++;
                    if(lookupType($1) == 2){
                        printf("Line %d: Illegal parameter type: Integer or array expected on function : %s\n", lineno, $1);
                    }
                    
                }
                ;

end_list        :       end_list end
                |       end
                ;

end             :       call_stmt 
                |       print_stmt
                |       ID ASSIGN INPUT_T 
                {
                    insert($1,lineno,9,-1);
                }
                |       ID ASSIGN exp
                {
                    insert($1,lineno,lookupType($3),-1);
                }       
                |       ID ASSIGN LB int_list RB
                {
                    insert($1,lineno,3,-1);
                }
                |       ID LB exp RB ASSIGN exp
                {
                    if(lookupType($3) != lookupType($6)){
                        printf("Line %d: Array variable miss match declared: %s != %s\n", lineno, $3,$6);
                    }else{
                        insert($1,lineno,3,-1);
                    }
                    
                }
                ; 
%%

yyerror() {
  fprintf(stderr,"Syntax error: line %d\n",lineno);
}

int yywrap() {
    return 1;
}


main(int argc, char **argv) {
    yyparse();
}



void enterScope() {
    SymbolTable* new_scope = (SymbolTable*) malloc(50*sizeof(SymbolTable));
    new_scope->head = NULL;
    new_scope->parent = current_scope;
    current_scope = new_scope;
}

void exitScope() {
    current_scope = current_scope->parent;
}

void insert(char* name, int lineno,int type,int param) {
    SymbolNode* node = (SymbolNode*) malloc(50*sizeof(SymbolNode));
    node->name = name;
    node->lineno = lineno;
    node->type = type;
    node->param =param;
    node->next = current_scope->head;
    current_scope->head = node;
}

int lookup(char* name, int lineno) {
    SymbolTable* scope = current_scope;
    while (scope != NULL) {
        SymbolNode* node = scope->head;
        while (node != NULL) {
            if (strcmp(node->name, name) == 0) {
                return 0;
            }
            node = node->next;
        }
        scope = scope->parent;
    }
    return -1;
}

int lookupType(char* name_1) {
    int first =-99; //default values

    SymbolTable* scope = current_scope; //check first
    while (scope != NULL) {
        SymbolNode* node = scope->head;
        while (node != NULL) {
            if (strcmp(node->name, name_1) == 0) {
                first = node->type;
                return first;
            }
            node = node->next;
        }
        scope = scope->parent;
    }
    return -1;// type mismatch
}

int getParam(char* name){
     SymbolTable* scope = current_scope;
    while (scope != NULL) {
        SymbolNode* node = scope->head;
        while (node != NULL) {
            if (strcmp(node->name, name) == 0) {
                return node->param;
            }
            node = node->next;
        }
        scope = scope->parent;
    }
    return -1;
}

int updateVar(char* name, int type) {
    SymbolTable* scope = current_scope;
    while (scope != NULL) {
        SymbolNode* node = scope->head;
        while (node != NULL) {
            if (strcmp(node->name, name) == 0) {
                node->type = type;
                return 0;
            }
            node = node->next;
        }
        scope = scope->parent;
    }
    return -1;
}


