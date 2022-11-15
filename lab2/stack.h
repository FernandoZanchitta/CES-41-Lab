#ifndef _STACK_H_
#define _STACK_H_
/**
 * Type for individual stack entry
 */
typedef struct stack_entry {
  char *data;
  struct stack_entry *next;
} stack_entry;

/**
 * Type for stack instance
 */
typedef struct stack_t
{
  struct stack_entry *head;
  size_t stackSize;  // not strictly necessary, but
                     // useful for logging
} stack_t;
char *copyString(char *);

/**
 * Push a value onto the stack
 */
void push(stack_t *, char *);

/**
 * Get the value at the top of the stack
 */
char *top(stack_t * );

/**
 * Pop the top element from the stack; this deletes both 
 * the stack entry and the string it points to
 */
void pop(stack_t *);

/**
 * Clear all elements from the stack
 */
void clear (stack_t *);

/**
 * Destroy a stack instance
 */
void destroyStack(stack_t **);
#endif