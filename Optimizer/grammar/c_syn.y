%{
	#include<stdio.h>
	#include "headers/defs.h"
	#include "headers/y.tab.h"
	#include <string.h>

	int for_depth_counter_var = 0;
	int direct_declarator_var = 0;
	int current_type_var = -1;
%}
%union{
	struct {
		int count_p;
		int count_m;
		int type;
		int size;
		int val;
		float fval;
		void * sentry;
		int t[4];
		char* string_val;
		int type_counter;


		char * string_exp;
	}vv;

	struct {
		int size, strideX, strideY;
		char *X, *Y;		
	} vec;
}

%token FOR WHILE DO IF ELSE RETURN
%token INT VOID FLOAT
%token CONST_Q //type qualifier  const int...
%token <vv> CONST_INT CONST_FLOAT IDENTIFIER STRING CONST
%token '='
%token '(' ')' ';' '}' '{' ']' '[' '/' '*' '+' '-' '<' '>' '%'
%token AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP INC DEC LEFT_OP RIGHT_OP
%type <vv> type_specifier declaration_specifiers primary_expression expression  compound_statement statement_list declaration_list identifier_list constant
%type <vv> selection_statement pointer direct_declarator declarator init_declarator declaration init_declarator_list initializer initializer_list statement postfix_expression
%type <vv> iteration_statement multiplicative_expression additive_expression shift_expression relational_expression equality_expression unary_expression assignment_expression init_vector
%type <vv> expression_statement and_expression exclusive_or_expression inclusive_or_expression logical_or_expression logical_and_expression assignment_operator opening_statement closing_statement;
%type <vec> vector_copy
%start optimizer_start
%%

optimizer_start : optimizer_copy_op;

optimizer_copy_op : FOR '(' IDENTIFIER '=' constant ';' IDENTIFIER '<' expression ';'  incr_expr ')' 
        '{' vector_copy ';' '}' 
        
		{  
			printf("N: %s\n", $9.string_val);
			printf("X: %s\n", $14.X);
			printf("incX: %d\n", $14.strideX);
			printf("Y: %s\n", $14.Y);
			printf("incY: %d\n", $14.strideY);
			//fprintf(yyout, "cblas_scopy(%s, %s, %s, %s, %s);", );
        }
        ;

vector_copy : IDENTIFIER '[' IDENTIFIER ']' '=' IDENTIFIER '[' IDENTIFIER ']'
            {
				if (strcmp($3.string_val, $8.string_val) == 0) {
					int len1 = strlen($1.string_val);
					int len2 = strlen($6.string_val);
					$$.X = malloc(sizeof(len1));
					$$.Y = malloc(sizeof(len2));
					strncpy($$.X, $1.string_val, len1);
					strncpy($$.Y, $6.string_val, len2);
					$$.strideX = 1;
					$$.strideY = 1;
				}
            }
            ;

incr_expr : IDENTIFIER '+' '+'
			| IDENTIFIER '=' IDENTIFIER '+' constant
			| IDENTIFIER '+' '=' constant
			;

expression :  IDENTIFIER | constant;
           ;

constant : CONST_INT | CONST_FLOAT ;
%%

int yyerror(const char *str)
{
	printf("error : %s\tline : %d\n",str,line_counter+1);
	return -1;
}

int yywrap()
{
return 1;
}
