/*
 * sort.h
 *
 *  Created on: 18 sty 2016
 *      Author: kubalobo
 */

#ifndef SORT_H_
#define SORT_H_

//bubble_sort.cpp
inline void exch(int a[], int i, int j);
inline void cmp_exch(int a[], int i, int j);
void bubble_sort(int a[], int size);

void insertion_sort(int a[], int size);

inline int min(int a, int b);
void merge(int a[], int aux[], int lo, int mid, int hi);
void merge_sort_bottom_up(int a[], int aux[], int size);
void merge_sort_bottom_up(int a[], int size);

void merge_sort(int a[], int aux[], int lo, int hi);
void merge_sort(int a[], int size);

void quick_sort_3way(int a[], int lo, int hi);
void quick_sort_3way(int a[], int size);

int partition(int a[], int lo, int hi);
void quick_sort(int a[], int lo, int hi);
void quick_sort(int a[], int size);

void selection_sort(int a[], int size);


//...

#endif /* SORT_H_ */
