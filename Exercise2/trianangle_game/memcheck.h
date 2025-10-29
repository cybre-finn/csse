/*
 * FILE: memcheck.h
 *
 *       Interface to the memory leak checker.
 *
 */

#ifndef MEMCHECK_H
#define MEMCHECK_H

#include <stdlib.h>

void *checked_malloc_fn(unsigned long size, char *filename, int lineno);
void *checked_calloc_fn(unsigned long nmemb, unsigned long size,
                        char *filename, int lineno);
void *checked_free_fn(void *ptr, char *filename, int lineno);
void  print_memory_leaks(void);

/*
 * Macros which maintain the interface of the standard malloc/calloc/free
 * functions.
 */

#define checked_malloc(n)    checked_malloc_fn((n), __FILE__, __LINE__)
#define checked_calloc(n, m) checked_calloc_fn((n), (m), __FILE__, __LINE__)
#define checked_free(p)      checked_free_fn((p), __FILE__, __LINE__)

/*
 * Wrappers for standard malloc/calloc/free functions.
 */

#define malloc(n)    checked_malloc_fn((n), __FILE__, __LINE__)
#define calloc(n, m) checked_calloc_fn((n), (m), __FILE__, __LINE__)
#define free(p)      checked_free_fn((p), __FILE__, __LINE__)



#endif  /* MEMCHECK_H */

