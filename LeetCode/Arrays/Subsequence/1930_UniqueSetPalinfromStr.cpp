/*
input = abascba

First occurence: a -> 0
                 b -> 1
                 c -> 4
                 s -> 3
Last occurence: a -> 6
                b -> 5
                c -> 4
                s -> 3

Now for each character of them we calculate number of unique characters between both occurences.

For a -> 0 : 6
        unique chars -> a, b, c, s -> 4 answers
For b -> 1 : 5
        unique chars -> a, c, s -> 3 answers
For c -> 4 : 4
        unique chars -> - -> 0 answers
For s -> 5 : 5
        unique chars -> - -> 0 answers

Final asnwer is 4 + 3 + 0 + 0 = 7
*/
