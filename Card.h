#ifndef CARD_H
#define CARD_H

class Card
{
private:

	/*
	 * Two comparison functions, one for if this is a face card, the other for if
	 * this is a numeric card. bool lessThan is true if this is a less than Comparison,
	 * false if this is a greater than comparison
	 */
	bool faceCompare(bool lessThan, const Card rhs);
	bool numCompare(bool lessThan, const Card rhs);

public:
	Card(char face, char suite);
	char face, suite;

	// Prints the card to cout, no newline
	void print();

	bool operator<(const Card rhs);
	bool operator>(const Card rhs);
	bool operator<=(const Card rhs);
	bool operator>=(const Card rhs);
	bool operator==(const Card rhs);
	bool operator!=(const Card rhs);
		
	// Sets this card equal to rhs
	void operator=(const Card rhs);
};

#endif