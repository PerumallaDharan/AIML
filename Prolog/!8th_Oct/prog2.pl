male(bhishma).
male(vyasa).
male(santanu).
male(vichitravirya).
male(pandu).
male(dhritarashtra).
male(yudhishthira).
male(bhima).
male(arjuna).
male(nakula).
male(sahadeva).
male(krishna).

female(ganga).
female(satyavati).
female(kunti).
female(gandhari).
female(draupadi).
female(subhadra).

father(bhishma, vichitravirya).
father(santanu, bhishma).
father(vyasa, dhritarashtra).
father(vyasa, pandu).
father(vyasa, vichitravirya).
father(pandu, yudhishthira).
father(pandu, bhima).
father(pandu, arjuna).
father(pandu, nakula).
father(pandu, sahadeva).
father(dhritarashtra, duryodhana).
father(dhritarashtra, duhsasana).
father(dhritarashtra, dushala).
father(krishna, pradyumna).
father(yudhishthira, prativindhya).
father(bhima, sutasoma).
father(arjuna, srutakirti).
father(nakula, sataneeka).
father(sahadeva, srutasena).

mother(ganga, bhishma).
mother(satyavati, vichitravirya).
mother(kunti, yudhishthira).
mother(kunti, bhima).
mother(kunti, arjuna).
mother(kunti, nakula).
mother(kunti, sahadeva).
mother(gandhari, duryodhana).
male(bhishma).
male(vyasa).
male(santanu).
male(vichitravirya).
male(pandu).
male(dhritarashtra).
male(yudhishthira).
male(bhima).
male(arjuna).
male(nakula).
male(sahadeva).
male(krishna).

female(ganga).
female(satyavati).
female(kunti).
female(gandhari).
female(draupadi).
female(subhadra).

father(bhishma, vichitravirya).
father(santanu, bhishma).
father(vyasa, dhritarashtra).
father(vyasa, pandu).
father(vyasa, vichitravirya).
father(pandu, yudhishthira).
father(pandu, bhima).
father(pandu, arjuna).
father(pandu, nakula).
father(pandu, sahadeva).
father(dhritarashtra, duryodhana).
father(dhritarashtra, duhsasana).
father(dhritarashtra, dushala).
father(krishna, pradyumna).
father(yudhishthira, prativindhya).
father(bhima, sutasoma).
father(arjuna, srutakirti).
father(arjuna, abhimanyu).
father(nakula, sataneeka).
father(sahadeva, srutasena).

mother(ganga, bhishma).
mother(satyavati, vichitravirya).
mother(kunti, yudhishthira).
mother(kunti, bhima).
mother(kunti, arjuna).
mother(kunti, nakula).
mother(kunti, sahadeva).
mother(gandhari, duryodhana).
mother(gandhari, duhsasana).
mother(gandhari, dushala).
mother(subhadra, abhimanyu).


grandfather(X, Y) :- father(X, Z), parent(Z, Y).
grandmother(X, Y) :- mother(X, Z), parent(Z, Y).


parent(X, Y) :- father(X, Y).
parent(X, Y) :- mother(X, Y).mother(gandhari, duhsasana).
mother(gandhari, dushala).
mother(subhadra, abhimanyu).

grandfather(X, Y) :- father(X, Z), parent(Z, Y).
grandmother(X, Y) :- mother(X, Z), parent(Z, Y).

parent(X, Y) :- father(X, Y).
parent(X, Y) :- mother(X, Y).

