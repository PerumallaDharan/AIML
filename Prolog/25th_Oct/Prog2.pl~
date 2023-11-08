
read_elements(0, []) :- !.
read_elements(N, [X | Rest]) :-
    N > 0,
    write('Enter an element: '),
    read(X),
    N1 is N - 1,
    read_elements(N1, Rest).


print_even([]).
print_even([X | Rest]) :-
    0 is X mod 2,
    write(X), write(' '),
    print_even(Rest).
print_even([_ | Rest]) :-
    print_even(Rest).


main :-
    write('Enter the number of elements: '),
    read(N),
    read_elements(N, List),
    write('Even numbers in the list: '),
    print_even(List).

