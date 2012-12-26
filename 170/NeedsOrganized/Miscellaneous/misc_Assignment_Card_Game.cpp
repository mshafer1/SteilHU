// Assignment:
//	-create the PlayingCard data type and its methods
//	-create the Player data type and its methods

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;

void Player::display()
{
	cout << name << " has the following cards. " << endl;
	for(int i = 0; i < 13; i++)
	{
		cards[i].display();
	}
}

//todo  - Complete the Deck datatype and its methods
struct Deck
{
	PlayingCard cards[52];
	int cardsDealt;
	Deck();
	void display();
	void shuffle();
	void dealCard( PlayingCard& card);
	void deal( Player players[]);


};

Deck::Deck()
{
	cardsDealt = 0;
	string values[13] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace",};
	int i = 0;

	for(int value = 0; value < 13; value++)
	{
		for(int suit = 3; suit <= 6; suit++)
		{
			cards[i].value = values[value];
			cards[i].suit = (char)suit;
			i++;
		}
	}
}

void Deck::dealCard( PlayingCard& card)
{
	//todo
}

void Deck::deal( Player players[])
{
	//todo
}

void Deck::display()
{
	//todo
}

void Deck::shuffle()
{
	PlayingCard newCards[52];

	int cardsPlaced = 0;

	while(cardsPlaced < 52)
	{
		int randomCardPosition = rand() % 52;  //0-51
		bool cardIsAlreadyInList = false;

		for(int i = 0; i < cardsPlaced; i++)
		{
			if(newCards[i].suit == cards[randomCardPosition].suit &&
				newCards[i].value == cards[randomCardPosition].value )
			{
				cardIsAlreadyInList = true;
			}
		}

		if(!cardIsAlreadyInList)
		{
			newCards[cardsPlaced] = cards[randomCardPosition];
			cardsPlaced++;
		}

	}

	for(int i = 0; i < 52; i++)
	{
		cards[i] = newCards[i];
	}

}


void main()
{
	Deck deck;
	Player players[4];

	players[0].name = "Washington"; 
	players[1].name = "Adams";
	players[2].name = "Jefferson";
	players[3].name = "Madison";

	deck.display();
	deck.shuffle();
	deck.display();

	deck.deal(players);
	
	for(int i = 0; i < 4; i++)
	{
		players[i].display();
	}
}