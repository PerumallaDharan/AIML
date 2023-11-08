print_numbers(N) :- N >= 1, print_numbers_recursive(1, N).
print_numbers_recursive(N, N) :-
    write(N), nl.
print_numbers_recursive(Current, N) :-
    write(Current), write(' '),
    Next is Current + 1,
    print_numbers_recursive(Next, N).

prog3 :-
    write('Enter a positive integer N: '),
    read(N),
    (N > 0 -> print_numbers(N); write('N must be a positive integer.')).

