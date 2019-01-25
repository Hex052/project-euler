# Problem 27
## Restrictions

* `b` must be prime (in case `n = 0`)
* `a` must be nonzero (given)
* `n^2 + an` must be even
	* therefore `a` must be odd (conveniently avoids having to skip over 0)
* `a + b` must be greater than 0 (provable with `n = 1`)
	* `a` must be be between `1 - b` and `b - 1` (if `a = b`, then result is even)
	* `a` really starts at `2 - b`, since `a` must be odd
* Number of primes produced will be less than `b`
	* if `n = b`, then the formula becomes `n^2 + an + n`, which is definitely not prime.
	* To possibly produce more primes than their formula, start at index 13 (41 is index 12)
