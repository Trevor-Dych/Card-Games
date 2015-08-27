# Card-Games
Our experimental group project

----- Project Overview -----

main.cpp
	The main event loop of the program. Should offer users the chance to select which game they would like to play.
	Also allows users the option to exit the program.

Card -- Jeremy
	A simple class, containing two characters (the suite and face)

	Public Members:
	char suite
		The suite of the card
		S = Spade
		C = Club
		D = Diamond
		H = Heart

	char face
		The rank of a card
		2 - 10, J = Jack, Q = Queen, K = King, A = Ace
		Note that the character '1' will be used to represent 10

	Public Functions:
	void print()
		Prints the card to cout

	bool operator<(const Card rhs)
	bool operator>(const Card rhs)
	bool operator<=(const Card rhs)
	bool operator>=(const Card rhs)
	bool operator==(const card rhs)
	bool operator!=(const Card rhs)
		Boolean comparisons. Self explanatory.
		Cards are ordered by face value. If suite value is ranked, it must be done within the game
			face: 2 < 3 < ... < 10 < J < Q < K < A

	void operator=(const Card rhs)
		Sets one card equal to the other

Deck -- Trevor
	An object containing a deck of cards.

	Public Functions:
		void shuffle()
			shuffles the deck

		Card draw()
			Removes the top card from the deck
			Returns: Card drawn
				The top card of the deck

		void addDeck(int num)
			Adds another deck of cards (incase you want multi deck blackJack or a really long game of war)
			Inputs:
				int num
					The number of decks to add

		void replenish()
			Replenishes the deck (back to one deck)

Hand -- Angela
	An object containing a smaller group of cards

	Public Functions:
		void addCard(Card input)
			Adds the selected card to the hand

		void discard(unsigned int card)
			Removes the designated card from the hand

		void order()
			Orders the cards in the hand 

		int size()
			Returns the number of cards in the hand

		const Card& operator[] (unsigned int i)
			Overloading bracket access for cards
			Only access of cards, no modification

		void print()
			Prints the hand to cout

		void discard()
			Empties the hand


Blackjack -- Alex
	Object containing the game of blackjack (No return value)
	At the end of the game, prompt user to play another hand or return to the main menu
	Dealer stands on soft 18, hard 17, and anything greater; hits on anything else

	Public Functions:
		void play()
			Instantiates the game

War -- Jeremy
	An object containing the game of war
	At the end of the game, return to the main menu

	Public Functions:
		void play()
			Instantiates the game

Group Guidelines:

Public functions must be defined exactly as stated here so that objects can communicate across files succesfully. It is your choice how you implement them. 

You may make any unparamaterized constructors, private functions or private data members that you wish.
If you feel the need, you may make any additional helper classes that you want, but notify the group to their existence to avoid duplicate naming.
If you would like an additional public function for a class that you are not overseeing, request it.
if you write an additional public function or modify an existing one, notify the group and update any documentation affected.

Above all, don't mess with someone else's code. Peruse it as you wish, but do not modify code or make any comment about it unless your input is requested.
