# Filter

## Assignment

Write a program that filter a string parsed via `stdout` as seen in the
following examples.

`echo 'abc42' | ./filter abc` 
-> ***42

`echo 'ababababcdefdef' | ./filter abc` 
-> ababab***defdef

## Constraints

- Returns 1 if there is no arguments or more than one.
- In case or read error or allocation, print `Error: ` followed by the
errno error message

## Authorized

- perror
- printf