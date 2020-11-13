%{
	#include<stdio.h>
	#include "headers/defs.h"
	#include "headers/y.tab.h"

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

}

%token FOR WHILE DO IF ELSE RETURN
%token INT VOID FLOAT
%token CONST_Q //type qualifier  const int...
%token <vv> CONST_INT CONST_FLOAT IDENTIFIER STRING CONST
%token '='
%token '(' ')' ';' '}' '{' ']' '[' '/' '*' '+' '-' '<' '>' '%'
%token AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP INC DEC LEFT_OP RIGHT_OP
%type <vv> type_specifier declaration_specifiers primary_expression expression  compound_statement statement_list declaration_list identifier_list
%type <vv> selection_statement pointer direct_declarator declarator init_declarator declaration init_declarator_list initializer initializer_list statement postfix_expression
%type <vv> iteration_statement multiplicative_expression additive_expression shift_expression relational_expression equality_expression unary_expression assignment_expression
%type <vv> expression_statement and_expression exclusive_or_expression inclusive_or_expression logical_or_expression logical_and_expression assignment_operator
%start optimizer_start
%%

optimizer_start : iteration_statement
		| iteration_statement optimizer_start

//==================================START-EXTERNAL======================================================================
translation_unit
	: compound_statement {
		printf("DONE ! \n");
		return 0;
	}
	//| translation_unit compound_statement
	;
compound_statement
	: '{' '}' {

	}
	| '{' statement_list '}' {

	}
	| '{' declaration_list '}' {

	}
	| '{' declaration_list statement_list '}' {
	}
	;

//=====================================EXTERNAL-END=====================================================================

//=====================================statement-START==================================================================

statement_list
	: statement {
	}
	| statement_list statement {

	}
statement
	: //labeled_statement
	  compound_statement {
	  }
	| expression_statement {
	}
	| selection_statement {
	}
	| iteration_statement {
	}
	;
expression_statement
	: ';' {
	}
	| expression ';' {

	}
	;

//=======================================Statement-END==================================================================

//=======================================LOOP-Conditional-EXR================================================================
selection_statement
	: IF '(' expression ')' compound_statement {

	}
	| IF '(' expression ')' compound_statement ELSE compound_statement {
	}
iteration_statement :
	 WHILE {printf("START-WHILE\n ");}'(' expression ')' compound_statement {printf("END-WHILE\n ");}

	| iter_counter FOR '(' expression_statement expression_statement expression')' compound_statement {

	}
iter_counter : {}
//=======================================CONDITIONAL-EXPR-END===========================================================

//==================================START-ASSIGNEMENT===================================================================
expression:
 	assignment_expression {

 	}
	| expression ',' assignment_expression {


	}
	;
postfix_expression
	: primary_expression {

	}
	//| postfix_expression '[' expression ']'
	//| postfix_expression '(' ')'
	//| postfix_expression INC
	//| postfix_expression DEC

unary_expression
	: postfix_expression {

	}
	| INC unary_expression {

	}
	| DEC unary_expression {

	}
	;
multiplicative_expression
	: unary_expression {

	}
	| multiplicative_expression '*' unary_expression {



	}
	| multiplicative_expression '/' unary_expression {


	}
	| multiplicative_expression '%' unary_expression {

	}
	;
additive_expression
	: multiplicative_expression {

	}
	| additive_expression '+' multiplicative_expression {

	}
	| additive_expression '-' multiplicative_expression {

	}
	;
shift_expression
	: additive_expression {
	}
	| shift_expression LEFT_OP additive_expression {

	}
	| shift_expression RIGHT_OP additive_expression {
	}
	;
relational_expression
	: shift_expression{
	}
	| relational_expression '<' shift_expression {

	}
	| relational_expression '>' shift_expression {

	}
	| relational_expression LE_OP shift_expression{

	}
	| relational_expression GE_OP shift_expression {

	}
	;
equality_expression
	: relational_expression{
	}
	| equality_expression EQ_OP relational_expression {
	}
	| equality_expression NE_OP relational_expression {
	}
	;
and_expression
	: equality_expression {
	}
	| and_expression '&' equality_expression {

	}
	;
exclusive_or_expression
	: and_expression{
	}
	| exclusive_or_expression '^' and_expression {

	}
	;
inclusive_or_expression
	: exclusive_or_expression {
	}
	| inclusive_or_expression '|' exclusive_or_expression {

	}
	;
logical_and_expression
	: inclusive_or_expression {
	}
	| logical_and_expression AND_OP inclusive_or_expression {

	}
	;
logical_or_expression
	: logical_and_expression {
	}
	| logical_or_expression OR_OP logical_and_expression {

	}
	;
//TODO add conditional assignement

assignment_expression :
	logical_and_expression {
		$$.string_exp = $1.string_exp;
	}
	| unary_expression assignment_operator assignment_expression {

	}
	;
assignment_operator
	: '=' {
	}
	;
//====================================ASSIGNEMENT-END=================================================================
//DONE TODO================================================
declaration_list
	: declaration {

	}
	| declaration_list declaration {
	}
	;//=================================================USED

//DONE
declaration :

	declaration_specifiers init_declarator_list ';' {
	}
	; //==========================================================USED

//DONE
declaration_specifiers
	:
	type_specifier {
	}

	;
//=======================================================USED
//DONE
type_specifier
	: VOID {


	}
	| INT  {

	}
	| FLOAT {

	}
	;
//DONE
init_declarator_list
	: init_declarator {


	}
	| init_declarator_list ',' init_declarator {



	}
	;

//DONE
init_declarator
	: declarator {


	}
	| declarator '=' initializer {


	}

	;

//DONE
declarator
	: pointer direct_declarator {

	}
	| direct_declarator {

	}
	;

// DONE
direct_declarator
	: IDENTIFIER {


	}
        //| direct_declarator '[' ']' {
        // 	$$.count_p = $1.count_p +1;
       // 	// TODO maybe add the array size
        //}
        | direct_declarator '[' CONST_INT ']' {

        }
        //| direct_declarator '(' ')'

        //| direct_declarator '(' identifier_list ')'


        ;
// DONE
pointer
	: '*'{

	}
	//| '*' type_qualifier_list
	| '*' pointer {

	}
	;


initializer
	: assignment_expression {


	}
	| '{' initializer_list '}' {

	}
	;
initializer_list
	: initializer {
	}
	| initializer_list ',' initializer {


	}
	;

//DONE
primary_expression
	: IDENTIFIER {

	}
	| CONST_INT {


	}
	| CONST_FLOAT {

	}
	//| STRING {
	//TODO Not implemented yet
	//}
	| '(' expression ')' {



	}
	;


//DONE
identifier_list
	: IDENTIFIER {

	}
	| identifier_list ',' IDENTIFIER {

	}
	;
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