#include <iostream>
using namespace std;
const int MAX = 100;
int arr[MAX ];
int size = 0;

void createArray() {
    cout << "Enter number of elements: ";
    cin >> size;
    if (size > MAX ) {
        cout << "Maximum size exceeded!\n";
        size = 0;
    }
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void displayArray() {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    if (size >= MAX) {
        cout << "Array is full. Cannot insert.\n";
    }
    int pos, value;
    cout << "Enter position to insert (0 to " << size << "): ";
    cin >> pos;
    if (pos < 0 || pos > size) {
        cout << "Invalid position.\n";
    }
    cout << "Enter value to insert: ";
    cin >> value;
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
    cout << "Element inserted.\n";
}

void deleteElement() {
    if (size == 0) {
        cout << "Array is empty. Cannot delete.\n";
    }
    int pos;
    cout << "Enter position to delete (0 to " << size - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= size) {
        cout << "Invalid position.\n";
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted.\n";
}

void linearSearch() {
    if (size == 0) {
        cout << "Array is empty.\n";

    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n—— MENU ——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}