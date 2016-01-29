/*
 * functions.h
 *
 *  Created on: 18 sty 2016
 *      Author: kubalobo
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//Deklaracje wszystkich funkcji nie zwi¹zanych z sortowaniem

//arrchk.cpp
int arrchk(int* arr, int size);

//arrgen.cpp
int nextrand();
int nextrand(int minv, int maxv);
inline void swap(int& a, int& b);
inline int invert(int& a, int& b);
void error_message();
int* array_random(int size, int minv, int maxv, int* target);
int* array_partially_sorted(int size, int inv, int* target);
int* array_ascending(int size, int* target);
int* array_descending(int size, int* target);
int* arrgen(int argc, char* argv[]);



#endif /* FUNCTIONS_H_ */
