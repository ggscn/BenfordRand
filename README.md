# benford-rand
a C++ random number generator based on the constraints of Benford's law

Put simply, [Newcomb-Benford's law](https://en.wikipedia.org/wiki/Benford%27s_law) suggests that the first digit of any number is more likely to start with a 1 than it is a 2, and more likely to start with a 2 than a 3, and so on... It was discovered when Newcomb noticed that the pages in a book of logarithm tables were more worn on pages where the result started with a 1. 

This C++ code performs random number generation based on the probabilities that a given number should exist provided by Benford's law. 
