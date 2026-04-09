#include <stdio.h>

int main()
{
char cards[] = "JQK";
char a_cards = cards[2];
cards[2] = cards[1];
cards[1] = cards[0];
cards[0] = cards[2];
cards[2] = cards[1];
cards[1] = a_cards;
puts (cards);
return 0;
}