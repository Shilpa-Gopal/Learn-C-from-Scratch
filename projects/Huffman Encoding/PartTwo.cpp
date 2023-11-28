#include "utility.h"
#include <queue>

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq, Node* left = nullptr, Node* right = nullptr)
        : ch(ch), freq(freq), left(left), right(right) {}
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void printCodes(Node* root, std::string str, std::ofstream& outputFile) {
    if (!root) {
        return;
    }

    if (root->ch != '$') {
        if (root->ch == 10) {
            outputFile << "LF " << str << "\n";
        } else if (root->ch == 13) {
            outputFile << "CR " << str << "\n";
        } else if (root->ch == 32) {
            outputFile << "SPACE " << str << "\n";
        } else {
            outputFile << root->ch << " " << str << "\n";
        }
    }

    printCodes(root->left, str + "0", outputFile);
    printCodes(root->right, str + "1", outputFile);
}

int main() {
    std::ifstream inputFile("freq.txt");
    std::ofstream outputFile("codetable.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    std::string line;

    while (std::getline(inputFile, line)) {
        char ch;
        int freq;

        if (line.substr(0, 2) == "LF") {
            ch = 10;
            freq = std::stoi(line.substr(3));
        } else if (line.substr(0, 2) == "CR") {
            ch = 13;
            freq = std::stoi(line.substr(3));
        } else if (line.substr(0, 5) == "SPACE") {
            ch = 32;
            freq = std::stoi(line.substr(6));
        } else {
            ch = line[0];
            freq = std::stoi(line.substr(2));
        }

        pq.push(new Node(ch, freq));
    }

    while (pq.size() != 1) {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('$', sum, left, right));
    }

    printCodes(pq.top(), "", outputFile);

    inputFile.close();
    outputFile.close();

    return 0;
}