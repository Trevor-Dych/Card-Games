#include "Card.cpp"

// STD I/O
#include <iostream>

using namespace std;

void Card::print()
{
	if (isnum(face))
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

bool Card::faceCompare(bool comp)
{
	// rhs is not a face card
	if (isnum(rhs.face))
	{
		return comp;
	}

	// rhs is a face card
	else
	{
		if (this->face == 'J' && rhs.face != 'J')
		{
			return comp;
		}

		else if (this->face == 'A')
		{
			return !comp;
		}

		else if (this->face == 'Q')
		{
			if (rhs.face == 'J' || rhs.face == 'Q')
			{
				return !comp;
			}

			else
			{
				return comp;
			}
		}

		// This is a king
		else
		{
			if (rhs.face == 'A')
			{
				return comp;
			}

			else
			{
				return !comp;
			}
		}
	}
}

bool Card::numCompare(bool comp)
{
	// rhs is 2 through 10
	if (isnum(rhs.face))
	{
		// This card is 10, rhs can't be strictly greater than
		if (this->face == '1')
		{
			return !comp;
		}

		// rhs is 10, must be strictly greater than
		else if (rhs.face == '1')
		{
			return comp;
		}
		
		// Both this and rhs are 2 through 9
		else
		{
			if (comp)
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
		return comp;
	}
}

bool Card::operator<(const Card rhs)
{
	// This card is 2 through 10
	if (isnum(this->face))
	{
		return numCompare(true);
	}

	// This is a face card
	else
	{
		return faceCompare(true);
	}
}

bool Card::operator>(const Card rhs)
{
	// This card is 2 through 10
	if (isnum(this->face))
	{
		return numCompare(false);
	}

	// This is a face card
	else
	{
		return faceCompare(false);
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

bool Card::operator==(const card rhs)
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