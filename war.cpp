// Bach Nguyen
// Class (CECS 325-02)
// Program 2 - More War
// Due Date: 2/27/2024
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Card
{
    private:
        char rank;
        char suit;

    public:
        Card() {}
        Card(char rank, char suit) : rank(rank), suit(suit) {}

       int compare(Card other)
        {
            int rankInt, otherInt;
            if (rank >= '2' && rank <= '9')
                rankInt = rank - '0';
            else if (rank == 'T')
                rankInt = 10;
            else if (rank == 'J')
                rankInt = 11;
            else if (rank == 'Q')
                rankInt = 12;
            else if (rank == 'K')
                rankInt = 13;
            else if (rank == 'A')
                rankInt = 1;

            if (other.rank >= '2' && other.rank <= '9')
                otherInt = other.rank - '0';
            else if (other.rank == 'T')
                otherInt = 10;
            else if (other.rank == 'J')
                otherInt = 11;
            else if (other.rank == 'Q')
                otherInt = 12;
            else if (other.rank == 'K')
                otherInt = 13;
            else if (other.rank == 'A')
                otherInt = 1;

            if (rankInt < otherInt) 
            {
                return -1;
            }
            else if (rankInt > otherInt) 
            {
                return 1;
            } 
            else 
            {
                return 0;
            }
        }
        
        void display()
        {
            if (rank == 'T')
                cout << "10" << suit;
            else
                cout << rank << suit; 
        }
};

class Deck
{
    private:
        Card cards[52]; 
        const char suits[4] = { 'C', 'S', 'D', 'H' };
        const char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9' , 'T', 'J', 'Q', 'K'};
        int top;
    public:
        Deck()
        {
            top = 0;
            int index = 0;
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 13; ++j)
                {
                    cards[index++] = Card(ranks[j], suits[i]);
                }
            }
        }

        Card deal()
        {
            if (isEmpty())
            {
                throw "Error - Deck is empty";
            }
            return cards[top++];
        }
        
        void display()
        {
            for (int i = 0; i < 52; i++)
            { 
                cards[i].display();
                if (i == 12 || i == 25 || i == 38 || i == 51)
                {
                    cout << endl;
                }
                else if (i != 52)
                {
                    cout << ", ";
                }

            }
            cout << endl;
        }

        void shuffle()
        {
            srand(time(0));
            for (int i = 0; i < 52; i++)
            {
                int j = rand() % 52;
                swap(cards[i], cards[j]);
            }
        }

        bool isEmpty()
        {
            return top == 52;
        }

};

int main()
{
    Deck deck;
    string player1, player2;
    int numGames;
    int player1Score {0}; 
    int player2Score {0}; 
    int ties{0};

    cout << "Enter the name of the first player: ";
    cin >> player1;
    cout << "Enter the name of the second player: ";
    cin >> player2;
    cout << "How many games will they play? ";
    cin >> numGames;
    cout << "\n";

    cout << "Unshuffled deck: \n";
    deck.display();
    cout << "\n";
    

    cout << "Shuffled deck: \n";
    deck.shuffle();
    deck.display();
    cout << "\n";

    for (int i = 0; i < numGames; i++)
        {
            try
            {
                Card card1 = deck.deal();
                Card card2 = deck.deal();

                cout << "Game " << i + 1 << "\n";
                cout << "-------- \n";
                cout << "        " << player1 << "=>";
                card1.display();
                cout << endl;
                cout << "        " << player2 << "=>";
                card2.display();
                cout << endl;

                int result = card1.compare(card2);
                if (result == 1)
                {
                    cout << player1 << "=> Winner\n";
                    player1Score++;
                }
                else if (result == -1)
                {
                    cout << player2 << "=> Winner\n";
                    player2Score++;
                }
                else
                {
                    cout << "Tie game\n";
                    ties++;
                }
                    cout << endl;   
            }
            catch (const char* msg)
            {
                cout << msg << endl;
                break;
            }
        }
    cout << "------Final Stats-------" << endl;
    cout << "       " << player1 << " vs. " << player2 << endl;
    cout << "Wins   " << player1Score << "          " << player2Score << endl;
    cout << "Losses " << player2Score << "          " << player1Score << endl;
    cout << "Ties   " << ties << "           " << ties << endl;

    return 0;
}




