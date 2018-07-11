/*
 * Darius Hooks
 * COMP 333
 * Project 3
 * 11/29/16
*/

/*FACTS*/
male(chauncey).
male(henry1).
male(ernest).
male(henry2).
male(phillip).
male(lamorris).
male(jason).
male(james).
male(tt).
male(terrance).
male(darius).
male(tyler).
female(ellamae).
female(lucille).
female(sharry).
female(chaundra).
female(karen).
female(felicia).
female(yolanda).
female(tonia).
female(curlie).
female(gentcella).
female(brenda).
parent(henry1,henry2).
parent(henry1,phillip).
parent(henry1,sharry).
parent(henry1,chaundra).
parent(henry1,karen).
parent(henry1,felicia).
parent(henry1,yolanda).
parent(henry1,tonia).
parent(ellaMae,henry2).
parent(ellamae,phillip).
parent(ellamae,sharry).
parent(ellamae,chaundra).
parent(ellamae,karen).
parent(ellamae,felicia).
parent(ellamae,yolanda).
parent(ellamae,tonia).
parent(ernest,curlie).
parent(ernest,gentcella).
parent(ernest,brenda).
parent(ernest,lamorris).
parent(ernest,jason).
parent(ernest,james).
parent(lucille,curlie).
parent(lucille,gentcella).
parent(lucille,brenda).
parent(lucille,lamorris).
parent(lucille,jason).
parent(lucille,james).
parent(henry2,terrance).
parent(henry2,darius).
parent(henry2,tyler).
parent(gentcella,tt).
parent(gentcella,darius).
parent(gentcella,tyler).


/*RULES*/
grandparent(X,Z):-parent(X,Y),parent(Y,Z).
grandfather(X,Z):-male(X),parent(X,Y),parent(Y,Z).
grandmother(X,Z):-female(X),parent(X,Y),parent(Y,Z).
mother(X,Y):-female(X),parent(X,Y).
father(X,Y):-male(X),parent(X,Y).