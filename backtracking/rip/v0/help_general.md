# What should be done?

## Let's try to understand the problem

### What's the problem?

- We are trying - if necessary - to balance a str comprised of ' ',
'(' and ')'.

Examples :
	- Unbalanced
		- '))'
		- '())'

	- Balanced
		- ' '
		- '('

### Why backtracking?

- We are try to exploring EVERY way of balancing a str, which implies:

	- Removing that '(' or ')',
	- Exploring what happens next in that scenario
	- Coming back to that point
	- Readding it - to explore another...

### What the DFS like? What is or isn't part of the decision tree? And Why?

- E.g. "())" 

	- 1 ')' to remove max.

	- Each node is a Character.

	- Recursion, every function instance is responsible from parenthesis
	 removal / recovery at that character address.

		- For each node, multiple choices can be made (remove, keep), so
		ou will have to write at least 2 recursive calls...

### What kind of process leads to a parenthesis removal?

- E.g. "()())()"

- The decision of removing a ( or ) depends on...

	- What's needed to be removed for the str to be BALANCED
	(1 right parenthesis (rp) in the example).
	Removal credits in that context...

	- Where we ARE, on a ' ', a '(' or a ')'.

	- What scenario we're in, do we decide to remove it or will we do it
	later...
