#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

template <typename T>
class CircularlyLinkedList
{
    private:
    class Node
    {
        public:
        T elem;
        Node* next;

        Node(const T& element, Node* nxt = nullptr) : elem(element), next(nxt) {}
    };
    int sz{0};
    Node* tail{nullptr};
    public:
    CircularlyLinkedList() {}

    int size() const {return sz;}
    bool empty() const { return sz == 0; }
    T& front() { return tail->next->elem; }
    const T& front() const { return tail->next->elem; }
    T& back() { return tail->elem; }
    const T& back() const { return tail->elem; }

    void push_front(const T& elem)
    {
        if (sz == 0) {
            tail = new Node(elem);
            tail->next = tail;
        } else {
            tail->next = new Node(elem, tail->next);
        }
        sz++;
    }

    void append(const T& elem)
    {
        push_front(elem);
        tail = tail->next;
    }

    void pop_front()
    {
        Node* head = tail->next;
        if (head == tail)
            tail = nullptr;
        else
            tail->next = head->next;
        delete head;
        sz--;
    }

    void step()
    {
        if (tail != nullptr)
            tail = tail->next;
    }

    int rollDice()
    {
        int min = 1, max = 6, num;
        num = (rand() % (max - min + 1) + min) + (rand() % (max - min + 1) + min);
        for(int c = 0; c < num; c++)
        {
            step();
        }
        return num;
    }
};

int main(void)
{
    srand(static_cast<unsigned>(time(nullptr)));

    CircularlyLinkedList monopolyBoard = CircularlyLinkedList<string>();

    monopolyBoard.append("Go");
    monopolyBoard.append("Mediteranean Avenue");
    monopolyBoard.append("Community Chest");
    monopolyBoard.append("Baltic Avenue");
    monopolyBoard.append("Income Tax");
    monopolyBoard.append("Reading Railroad");
    monopolyBoard.append("Oriental Avenue");
    monopolyBoard.append("Chance");
    monopolyBoard.append("Vermont Avenue");
    monopolyBoard.append("Conneticut Avenue");

    monopolyBoard.append("Jail");
    monopolyBoard.append("St. Charles Place");
    monopolyBoard.append("Electric Company");
    monopolyBoard.append("States Avenue");
    monopolyBoard.append("Virginia Avenue");
    monopolyBoard.append("Pennsylvania Railroad");
    monopolyBoard.append("St. James Place");
    monopolyBoard.append("Community Chest");
    monopolyBoard.append("Tennesse Avenue");
    monopolyBoard.append("New York Avenue");

    monopolyBoard.append("Free Parking");
    monopolyBoard.append("Kentucky Avenue");
    monopolyBoard.append("Chance");
    monopolyBoard.append("Indiana Avenue");
    monopolyBoard.append("Illinois Avenue");
    monopolyBoard.append("B&O Avenue");
    monopolyBoard.append("Atlantic Avenue");
    monopolyBoard.append("Ventnor Avenue");
    monopolyBoard.append("Water Works");
    monopolyBoard.append("Marvin Gardens");

    monopolyBoard.append("Go To Jail");
    monopolyBoard.append("Pacific Avenue");
    monopolyBoard.append("North Carolina Avenue");
    monopolyBoard.append("Community Chest");
    monopolyBoard.append("Pennsylvania Avenue");
    monopolyBoard.append("Short Line");
    monopolyBoard.append("Chance");
    monopolyBoard.append("Park Place");
    monopolyBoard.append("Luxury Tax");
    monopolyBoard.append("Boardwalk");

    cout << monopolyBoard.front() << endl;

    monopolyBoard.step();

    cout << monopolyBoard.front() << endl;

    cout << "Rolled " << monopolyBoard.rollDice() << endl;

    cout << monopolyBoard.front() << endl;

    for(int i = 0; i < 13; i++)
    {
        cout << "Rolled a " << monopolyBoard.rollDice() << ", now on "
            << monopolyBoard.front() << endl;
    }

    return 0;
}