#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    std::string name;
    int value;
};

// Recursive function to find possible combinations
void findCombination(std::vector<Item>& items, int index, int currentSum, int total, std::vector<Item>& currentSet, std::vector<Item>& bestSet) {

    if (currentSum == total) {
        if (currentSet.size() > bestSet.size()) {
            bestSet = currentSet;
        }
        return;
    }

    // If sum exceeds or we run out of items, stop
    if (currentSum > total || index >= items.size()) {
        return;
    }

    // Include the current item
    currentSet.push_back(items[index]);
    findCombination(items, index + 1, currentSum + items[index].value, total, currentSet, bestSet);

    // Exclude the current item (backtrack)
    currentSet.pop_back();
    findCombination(items, index + 1, currentSum, total, currentSet, bestSet);
}

int main() {
    // Define the items and their values
    std::vector<Item> items = {
        {"Starry Ore", 320},
        {"Glowy Ore", 280},
        {"Shiny Ore", 325},
        {"Builder Potion", 590},
        {"Wall Ring", 515},
        {"Research Potion", 250},
        {"Pet Potion", 250},
        {"Resource Potion", 240},
        {"Training Potion", 50},
        {"Clan House Roof", 515},
        {"Clan House Decoration", 515},
        {"Gold", 15},
        {"Elixir", 15},
        {"Dark Elixir", 30}
    };

    int total = 650;
    std::vector<Item> currentSet, bestSet;

    // Find the best combination
    findCombination(items, 0, 0, total, currentSet, bestSet);

    // Print the result
    std::cout << "Best Combination is: " << std::endl;
    for (auto& item : bestSet) {
        std::cout << item.name << " (" << item.value << ")" << std::endl;
    }

    return 0;
}
