# HELP, what should be done?

## Example of strs

### BALANCED

- ""
- "()"
- "(())"

- "()()"

Always starts with '(' ? Finds another ')' somewhere... 
str is balanced if '(' opened == ')' closed

### UNBALANCED: 
	
- "))((" 
	- [2 x ( + 2 x )] Looks balanced but is not... , so there is a lot to 
		remove...
	- "    "

- "))()"
	- "  ()"

- "()())()"
	- [3 x ( + 4 x )] One ) should be removed... while maintaining "logic"
	- "()() ()"
	- "()( )()"
	- "( ())()"

- If a str starts with ')', nothing that could be done...? Depends
	on what could be done after that, maybe there's a pair of '()'
	or two just after...

## Let's try to understand the problem

### What's the point of backtracking here?
	
	- Exploring every way of balancing a str, so coming back to 
	a modification in the str (removing a '(' or ')') to explore another...
	
### What does constitute a choice here?

	- Removing a parenthesis?
	
### What choice should be undone?
	
	- Readding a parenthesis?

### What should the traversal look like? What is or isn't part of the decision 
### tree? And Why?

	- E.g. "()())()" [1rp in (3 x '(') + (4 x ')')]

	- Character to character.
	
	- Recursion, every function instance is responsible from parenthesis
		 removal / recovery at that character address.

	- For each node, multiple choices can be made (remove, keep), so
	you will have to write at least 2 recursive calls...

### What kind of process leads to a parenthesis removal?

	- E.g. "()())()" [3 x ( + 4 x )]

	- The decision of removing a ( or ) depends on...

		- What's needed to be removed for the str to be BALANCED
		(1 right parenthesis (rp) in the example).

		- Where we ARE, on a ' ', a '(' or a ')'.

		- What has come before '(' or ')'.
			- If on a ')' ; no '(' before  ; and ')' should be removed... 
				- REMOVE?
			- If on a ')' ; a '(' before  ; and ')' should be removed...
				- REMOVE ALSO? After all... ')' should go and maybe backtracking pruning will help.

			- ...


## == Ideas ==
	

	
	// - Track open and closed via a boolean balanced / unbalanced for
	// example. When unbalanced, something should happen. 

	