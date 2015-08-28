#include "Card.h"

// STD I/O
#include <iostream>

using namespace std;

Card::Card(char face, char suite)
{
	this->face = face;
	this->suite = suite;
}

void Card::print()
{
	if (isdigit(face))
	{
		if (face != '1')
		{
			cout << face << " of ";
		}

		else
		{
			cout << "10 of ";
		}
	}

	else
	{
		switch (face)
		{
			case 'J':
				cout << "Jack of ";
			break;
			case 'Q':
				cout << "Queen of ";
			break;
			case 'K':
				cout << "King of ";
			break;
			case 'A':
				cout << "Ace of ";
			break;

		}
	}

	switch (suite)
	{
		case 'C':
			cout << "Clubs";
		break;
		case 'S':
			cout << "Spades";
		break;
		case 'D':
			cout << "Diamonds";
		break;
		case 'H':
			cout << "Hearts";
		break;
	}
}

bool Card::faceCompare(bool lessThan, const Card rhs)
{
	// rhs is not a face card
	if (isdigit(rhs.face))
	{
		return lessThan;
	}

	// rhs is a face card
	else
	{
		if (this->face == 'J' && rhs.face != 'J')
		{
			return lessThan;
		}

		else if (this->face == 'A')
		{
			return !lessThan;
		}

		else if (this->face == 'Q')
		{
			if (rhs.face == 'J' || rhs.face == 'Q')
			{
				return !lessThan;
			}

			else
			{
				return lessThan;
			}
		}

		// This is a king
		else
		{
			if (rhs.face == 'A')
			{
				return lessThan;
			}

			else
			{
				return !lessThan;
			}
		}
	}
}

bool Card::numCompare(bool lessThan, const Card rhs)
{
	// rhs is 2 through 10
	if (isdigit(rhs.face))
	{
		// This card is 10, rhs can't be strictly greater than
		if (this->face == '1')
		{
			return !lessThan;
		}

		// rhs is 10, must be strictly greater than
		else if (rhs.face == '1')
		{
			return lessThan;
		}
		
		// Both this and rhs are 2 through 9
		else
		{
			if (lessThan)
			{
				return this->face < rhs.face;
			}
			else
			{
				return this->face > rhs.face;
			}
		}
	}

	// rhs is a face card
	else
	{
		return lessThan;
	}
}

bool Card::operator<(const Card rhs)
{
	// This card is 2 through 10
	if (isdigit(this->face))
	{
		return numCompare(true, rhs);
	}

	// This is a face card
	else
	{
		return faceCompare(true, rhs);
	}
}

bool Card::operator>(const Card rhs)
{
	// This card is 2 through 10
	if (isdigit(this->face))
	{
		return numCompare(false, rhs);
	}

	// This is a face card
	else
	{
		return faceCompare(false, rhs);
	}
}

bool Card::operator<=(const Card rhs)
{
	return (*this < rhs || *this == rhs);
}

bool Card::operator>=(const Card rhs)
{
	return (*this > rhs || *this == rhs);
}

bool Card::operator==(const Card rhs)
{
	return (this->face == rhs.face);
}

bool Card::operator!=(const Card rhs)
{
	return (this->face != rhs.face);
}
		
void Card::operator=(const Card rhs)
{
	this->face = rhs.face;
	this->suite = rhs.suite;
}