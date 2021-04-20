// Побудувати список символів. Визначити найбільше значення списку і помістити його на початок списку. Надрукувати початковий і змінений списки.
#include <iostream>
#include <string>

using namespace std;

struct Node {
  char ch;  //
  Node *Next, *Prev;
};

class list {
  Node *Head, *Tail;

 public:
  int size = 0;

  list() : Head(NULL), Tail(NULL){};

  void push(char ch);

  void show();

  char get(int i);

  void remove(int index);
};

void list::push(char ch) {
  Node *temp = new Node;
  temp->Next = NULL;
  temp->ch = ch;

  if (Head != NULL) {
    temp->Prev = Tail;
    Tail->Next = temp;
    Tail = temp;
  } else {
    temp->Prev = NULL;
    Head = Tail = temp;
  }
  ++size;
}

char list::get(int index) {
  if (index >= size) {
    cout << " ERROR " << endl;
    throw logic_error("index cannot be bigger than currSize");
  }

  Node *currNode = Head;
  for (int i = 0; i < index; ++i) {
    currNode = currNode->Next;
  }

  return currNode->ch;
}

void list::show() {
  Node *temp = Head;
  while (temp != NULL) {
    cout << temp->ch << " ";
    temp = temp->Next;
  }
  cout << endl;
}

void list::remove(int index) {
  Node *previous = Head;
  Node *toDelete = Head;
  for (int i = 0; i < index; ++i) {
    previous = toDelete;
    toDelete = (toDelete->Next);
  }
  previous->Next = toDelete->Next;
  toDelete->Next = NULL;
  --size;
  delete toDelete;
}

int main() {
  list l;
  cout << "enter text\n";

  string input;
  getline(std::cin, input);

  for (int j = 0; j < input.length(); ++j) {
    l.push(input[j]);
  }

  cout << "read completed, the list is" << endl;
  l.show();

  cout << "finding the max value" << endl;
  list reverted;

  int maxInd = 0;
  char max = l.get(maxInd);

  for (int k = 0; k < l.size; ++k) {
    if (l.get(k) > max) {
      max = l.get(k);
      maxInd = k;
    }
  }
  cout << "the biggest is " << max << "\n";
  reverted.push(max);
  l.remove(maxInd);
  for (int i = 0; i < l.size; ++i) {
    reverted.push(l.get(i));
  }
  cout << "final list is\n";
  reverted.show();
}