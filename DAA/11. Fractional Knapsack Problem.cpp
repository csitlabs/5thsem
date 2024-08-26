//11. Fractional Knapsack Problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double valuePerWeight;

    Item(int v, int w) : value(v), weight(w) {
        valuePerWeight = (double)v / w;
    }
};

// Comparison function to sort items by value per weight in descending order
bool compare(Item a, Item b) {
    return a.valuePerWeight > b.valuePerWeight;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    // Sort items by value per weight
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int i = 0;
    while (capacity > 0 && i < items.size()) {
        // Take as much as possible of the current item
        int takeWeight = min(items[i].weight, capacity);
        totalValue += takeWeight * items[i].valuePerWeight;
        capacity -= takeWeight;
        i++;
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Fractional Knapsack Problem" << endl;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter the value and weight for each item:\n";
    for (int i = 0; i < n; ++i) {
        int value, weight;
        cout << "Item " << i + 1 << " (value weight): ";
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(items, capacity);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}

