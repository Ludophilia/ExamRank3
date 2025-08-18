# Help permutations

## Development of 1 2

Just to understand the purpose of the neutral swap and actually what's going on
with that array...

[1 2]

* at=0
* [1] 2 (loop0)
* = **1 2** (loop0)
	* at=1 (2-1)
	* -> print

* at=0
* [1 2] (loop1)
* = **2 1** (loop1)
	* at=1
	* -> print

## Development of 1 2 3 

Same purpose as above.

[1 2 3]

* at=0
* [1] 2 3 (loop0)
* = **1 2 3** (loop0)
	* at=1 
	* 1 [2] 3 (loop0)
	* = **1 2 3**
		* at=2 (3 - 1)
		* -> print
	* at=1
	* 1 [2 3] (loop1)
	* = **1 3 2**
		* at=2
		* -> print

* at=0
* [1 2] 3 (loop1)
* = **2 1 3** (loop1)
	* at=1
	* 2 [1] 3 (loop0)
	* = **2 1 3**
		* at=2
		* ->  print
	* at=1
	* 2 [1 3] (loop1)
	* = **2 3 1**
		* at=2
		* ->  print

* at=0
* [1] 2 [3] (loop2)
* = **3 2 1** (loop2)
	* at=1
	* 3 [2] 1 (loop0)
	* = **3 2 1**
		* at=2
		* ->  print
	* at=1
	*3 [2 1] (loop1)
	* = **3 1 2**
		* at=2
		* ->  print
