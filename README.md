* **Author: Hanson Addo**
### **Typechecking Mython Programs**

The Mython language was very loosely inspired by the langauge Python. 

## Declaration checking

The goal of this phase is build a simple symbol table to keep track of the names visible in the different scopes and to enforce the correct visibility. If a variable is used in a scope where it is not visible, print out a descriptive error message, including the variable name and the associated line number. Continue processing - in other words, do not exit the program.

## Checking the Type System

Each function definition defines a local scope. The parameters of the function are either integers or arrays, where arrays are denoted with []. Note that this is one of the few places in Mython where type information is given. New variables are 'declared' by using them in the left side of an assignment statement. The type of new variables (integer or boolean) is determined as described next. Variable names must be unique in a scope. Functions, if they return a result, may return boolean or integer. This return type is determined by the expression associated with the 'return' statements. 
