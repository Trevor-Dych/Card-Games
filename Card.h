#ifndef CARD_H
#define CARD_H

class Card
{
private:
	bool faceCompare(bool comp);
	bool numCompare(bool comp);
	// bool comp = true for comparing less than, false for comparing greater than
public:
	char face, suite;

	void print();

	bool operator<(const Card rhs);
	bool operator>(const Card rhs);
	bool operator<=(const Card rhs);
	bool operator>=(const Card rhs);
	bool operator==(const card rhs);
	bool operator!=(const Card rhs);
		
	// Sets this card equal to rhs
	void operator=(const Card rhs);
};

#endif