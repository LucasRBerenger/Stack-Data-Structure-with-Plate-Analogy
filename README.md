# Stack Data Structure with Plate Analogy

Welcome to the kitchen! This repository contains two implementations of the stack data structure in C, using a fun and whimsical analogy of stacking and washing plates in a kitchen.

## Stack Structure

The stack is a fundamental data structure that follows the Last In, First Out (LIFO) principle. Just like a stack of plates, items are added and removed from the top of the stack.

## Analogy: Stacking Plates

In both implementations, I've used a kitchen scenario to illustrate the concept of a stack. Imagine a stack of plates in a kitchen. You can add new plates on top of the stack or remove the top plate for cleaning.

## Humor and Didactic Approach

We've infused humor and a didactic approach to make learning about stacks more enjoyable. From warnings about overloaded stacks causing kitchen disasters to magical kitchens where plates never run out, I've tried to make the learning experience both informative and entertaining.

## Function Organization

I've chosen to keep all functions in the .c files rather than creating a separate .h file for simplicity. This decision was made to keep the project straightforward and easy to understand, especially for beginners.

## Files

### Static Stack (stack_static.c)

This implementation uses a static array to represent the stack. It simulates the stacking and washing of plates in a kitchen with a humorous twist.

### Dynamic Stack (stack_dynamic.c)

This implementation uses dynamic memory allocation with linked lists to represent the stack. The kitchen analogy is extended to a magical kitchen where plates never run out, adding an element of whimsy to the learning experience.

## How to Use

Compile the C files using a C compiler such as gcc:

```bash
gcc -o stack_static stack_static.c
gcc -o stack_dynamic stack_dynamic.c
