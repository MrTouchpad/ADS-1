// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
	if (value < 1) {
		return 0;
	}
	int k = 0;
	for (int i = 1; i <= value; i++) {
		if (value % i == 0) {
			k += 1;
		}
	}
	if (k == 2) {
		return 1;
	}
	else {
		return 0;
	}
}
uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
    uint64_t count = 0;
    uint64_t candidate = 2;
    while (true) {
        if (checkPrime(candidate)) {
            count++;
            if (count == n) {
                return candidate;
            }
        }
        candidate++;
    }
}

uint64_t nextPrime(uint64_t value) {
      uint64_t candidate = value + 1;
    while (!checkPrime(candidate)) {
        candidate++;
    }
    
    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound <= lbound + 2) return 0;
    uint64_t count = 0;
    for (uint64_t i = lbound; i <= hbound - 3; i++) {
        if (checkPrime(i) && checkPrime(i + 2)) {
            count++;
        }
    }
    
    return count;
}
