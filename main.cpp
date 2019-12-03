#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include "Data.h"
using namespace std;

int main() {
    ifstream in;
    ofstream out;
    string name;
    string height;
    string weight;
    string dash;
    string bench;

    in.open("../2019_nfl_combine_results.csv");
    if(!in.is_open()) {
        cout << "Unable to open 2019_nfl_combine_results.csv" << endl;
        return 1;

    }

    out.open("../stacked.txt");
    if(!out.is_open()) {
        cout << "Unable to open stacked.txt" << endl;
        return 1;

    }

    cout << "Reading 2019_nfl_combine_results.csv" << endl;

    // create containers
    stack<Data> stack;
    queue<Data> queue;
    priority_queue<Data> priorityQueue;

    // push data into stack, queue, and priority queue
    while(!in.eof()) {
        getline(in, name, ',');
        getline(in, height, ',');
        getline(in, weight, ',');
        getline(in, dash, ',');
        getline(in, bench, '\n');
        int h = stoi(height);
        int w = stoi(weight);
        double d = stoi(dash);
        int b = stoi(bench);
        Data data(name, h, w, d, b);
        stack.push(data);
        queue.push(data);
        priorityQueue.push(data);

    }

    in.close(); // close 2019_nfl_combine_results.csv

    cout << "Writing data in stack to stacked.txt" << endl;
    while(!stack.empty()) {
        out << stack.top();
        stack.pop(); // pop off stack
    }

    out.close(); // close stacked.txt

    out.open("../queued.txt");
    if(!out.is_open()) {
        cout << "Unable to open queued.txt" << endl;
        return 1;

    }

    cout << "Writing data in queue to queued.txt" << endl;
    while(!queue.empty()) {
        out << queue.front();
        queue.pop(); // dequeue
    }

    out.close(); // close queue.txt

    out.open("../sorted.txt");
    if(!out.is_open()) {
        cout << "Unable to open sorted.txt" << endl;
        return 1;

    }

    cout << "Writing data in priority queue sorted by height to sorted.txt" << endl;
    while(!priorityQueue.empty()) {
        out << priorityQueue.top();
        priorityQueue.pop(); // dequeue from priority
    }

    out.close(); // close sorted.txt

    return 0;
}