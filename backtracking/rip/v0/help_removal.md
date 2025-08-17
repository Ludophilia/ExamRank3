# Parenthesis Removal

## What is the goal?

- Get how many '(' or ')' should be removed for the str to be balanced.

## What is the logic?

- When you see '(' you try to find its matching ')'...?

- "())"
	-> Remove 1 ')'
		- Why?
			- There's only 1 ')' to match 1 '('
			- 2 ')' - 1 '(' = 1 ')' <== Not as easy as this...

- "))("
	-> Remove 2 ')' + 1 '('
		- Why?
			- But  2 ')' - 1 '(' = 1 ')', no?
				- '(' position matters, so you need to treat '(' as a flag
				or something... count that decreases when a ')' is found...
			- when no '(' before: remove every ')', so 2 ')'

--> OK. So the logic is...
		- ')': count normally when '(' is at 0.
		- '(': count normally
		- ')': decrease '(' when '(' is > 0.

## Logic application

### Len 0 or 1

- ""
	- 0 '('
	- 0 ')'

- "("
	- 1 '('
	- 0 ')'

- ")"
	- 0 '('
	- 1 ')'

### Len 2

- "()"
	- 0 '('
	- 0 ')'

- "))"
	- 0 '('
	- 2 ')' 

- "(("
	- 2 '('
	- 0 ')'

### Len 3

- "())"
	- 0 '('
	- 1 ')'

- "))("
	- 1 '('
	- 2 ')'

- "(()"
	- 1 '('
	- 0 ')'

### Len 4 and more

- "()()"
	- 0 '('
	- 0 ')'

- "))(("
	- 2 '('
	- 2 ')'

- "((()"
	- 2 '('
	- 0 ')'

- ")((("
	- 3 '('
	- 1 ')'

- ")()("
	- 1 '('
	- 1 ')'

### Len 5 and more

- "()())()" (ah, that's the ')' example)
	- 0 '('
	- 1 ')'

- ")()())()"
	- 0 '('
	- 2 ')'

- "))() (((   ))"
	- 1 '('
	- 2 ')'