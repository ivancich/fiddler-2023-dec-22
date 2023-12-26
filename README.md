My C++ source code to search for the solutions to the December 22,
2023 Fiddler challenges -- both the regular and the extra credit --
are contained in this repository.

The solution to the extra credit challenge may not find the ultimate
best value. It searchs for 100,000,000 iterations with the assumption
that the best solution will be found by then.

On the other hand, the solution to the regular challenge does do an
exhaustive search w/ various heuristics to try to run as fast as
possible.


The regular challenge is as follows:

"The new year is almost upon us! From Dean Ballard comes an early
celebration of the number 2024:

"There are several rectangular prisms with integer edge lengths that
have an internal diagonal of length 2024.

"What is the greatest volume among these prisms?"


The extra credit challenge is as follows:

"From Dean Ballard comes yet another puzzle to ring in 2024:

"The Collatz Conjecture asserts that if you start with any positive
integer and repeatedly apply a certain operation, the resulting
sequence of numbers will always reach the number 1. The operation is:
For even numbers divide by 2; for odd numbers, multiply by 3 and add
1.

"For example, if you start with 11, the sequence goes: 11 → 34 → 17 →
52 → 26 → 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1.

"The Collatz Conjecture is a well-known unsolved problem in
mathematics. No proof has ever been found to show that it is true, nor
has any counterexample been found to show that it is false.

"What is the smallest starting number for which 2024 appears somewhere
in its Collatz sequence?"
