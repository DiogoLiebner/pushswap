*This project was has been created as part of the 42 curriculum by dlima-li*

## Description

This repository contains an implementation of the push_swap project from the 42 curriculum.

The goal is to sort a list of integers using only a limited set of stack operations, while minimizing the number of moves.

'push_swap' takes a list of integers (passed as command-line arguments) and outputs a sequence of operations that will sort the list in ascending order.

It uses two stacks:

- Stack A: initially contains the input numbers.
- Stack B: used as temporary storage.

The allowed operations are:

| Operation | Description |
|-----------|-------------|
| 	sa  	| swap the first two elements of stack A |
| 	sb 		| swap the first two elements of stack B |
| 	ss 		| sa + sb |
| 	pa 		| push the top of stack B onto stack A |
| 	pb 		| push the top of stack A onto stack B |
|	  ra	 	| rotate stack A (top becomes bottom) |
| 	rb 		| rotate stack B |
| 	rr 		| ra + rb |
| 	rra		| reverse rotate stack A (bottom becomes top) |
| 	rrb 	| reverse rotate stack B |
| 	rrr 	| rra + rrb |

The program must also detect invalid input (non-numeric values, duplicates, overflow) and print "Error" before exiting.

##  Instructions

### Build

make

### Run

./push_swap 3 2 1 5 4

You can also provide space-separated arguments (quoted):

./push_swap "4523 55 235 5437"

## Algorithm & Implementation

### Data structures

Stacks are implemented using a singly linked list (t_stack). Each node stores an integer value and a placeholder 'index' field.

This structure is ideal for push_swap because all required operations (push, swap, rotate, reverse rotate) have predictable behavior, and there is no need for expensive array shifting.

### Sorting strategy

- For ≤ 5 elements, the program uses a simple deterministic routine (sort_small) that isolates minimum values and finishes with a 3-element sort (sort_three).
- For larger inputs, it uses a Turkish algorithm approach:
	1. Push all but 3 elements from A to B (keeping A small and easy to sort).
	2. Sort the remaining 3 elements in A.
	3. Repeatedly select the best element in B to insert back into A using a cost model.
	4. Rotate A so that the smallest value is at the top.

The selection strategy computes the “cheapest” move by considering:

- rotations needed in A to position the insertion point,
- rotations needed in B to bring a candidate value to the top,
- and whether those rotations can be combined (rr, rrr).

##  Why use the Turk algorithm with linked lists?

The “Turkish” algorithm (sometimes called the “cost-based insertion” strategy) is a practical choice for push_swap because it minimizes the total number of operations by choosing the best
candidate element to move from B to a at each step. It also works well with link-based stacks, where pushes and rotations are cheap and the stack bounds can change dynamically. This approach
then also scales better than brute-force approaches for bigger inputs

Using linked lists rather than arrays avoids expensive element shifts on push/pop and allows constant-time rotation logic, which is critical for fast move generation.

## Resources

42 push_swap Subject
Valgrind - memory-leak checking
Stack operations explained (https://levelupsynergy.in/articles/implementation-of-stack-in-c))
