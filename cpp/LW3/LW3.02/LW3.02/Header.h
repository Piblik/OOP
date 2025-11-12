#pragma once
#include <iostream>
#include <string>
using namespace std;

class Detail {
protected:
    string name;
    string material;
public:
    Detail() : name(""), material("") {}
    Detail(string n, string m) : name(n), material(m) {}
    void showInfo() const {
        cout << "      Detail: " << name << " | Material: " << material << endl;
    }
    string getName() const { return name; }
};

class Mechanism : public Detail {
protected:
    Detail details[5];
    int detailCount;
public:
    Mechanism() : Detail(), detailCount(0) {}
    Mechanism(string n, string m) : Detail(n, m), detailCount(0) {}

    bool addDetail(const Detail& d) {
        if (detailCount < 5) {
            details[detailCount++] = d;
            return true;
        }
        cout << "    Mechanism is full!\n";
        return false;
    }

    void showInfo() const {
        cout << "    Mechanism: " << name << " | Material: " << material << endl;
        for (int i = 0; i < detailCount; i++)
            details[i].showInfo();
    }

    int getDetailCount() const { return detailCount; }
    string getDetailName(int idx) const {
        if (idx < 0 || idx >= detailCount) return "";
        return details[idx].getName();
    }
};

class Node : public Mechanism {
protected:
    Mechanism mechs[5];
    int mechCount;
public:
    Node() : Mechanism(), mechCount(0) {}
    Node(string n, string m) : Mechanism(n, m), mechCount(0) {}

    bool addMechanism(const Mechanism& m) {
        if (mechCount < 5) {
            mechs[mechCount++] = m;
            return true;
        }
        cout << "  Node is full!\n";
        return false;
    }

    void showInfo() const {
        cout << "  Node: " << name << " | Material: " << material << endl;
        for (int i = 0; i < mechCount; i++)
            mechs[i].showInfo();
    }

    int getMechanismCount() const { return mechCount; }
    string getMechanismName(int idx) const {
        if (idx < 0 || idx >= mechCount) return "";
        return mechs[idx].getName();
    }

    Mechanism* getMechanismPtr(int idx) {
        if (idx < 0 || idx >= mechCount) return nullptr;
        return &mechs[idx];
    }
};

class Product : public Node {
protected:
    Node nodes[5];
    int nodeCount;
public:
    Product() : Node(), nodeCount(0) {}
    Product(string n, string m) : Node(n, m), nodeCount(0) {}

    bool addNode(const Node& n) {
        if (nodeCount < 5) {
            nodes[nodeCount++] = n;
            return true;
        }
        cout << "Product is full!\n";
        return false;
    }

    void showInfo() const {
        cout << "Product: " << name << " | Material: " << material << endl;
        for (int i = 0; i < nodeCount; i++)
            nodes[i].showInfo();
    }

    int getNodeCount() const { return nodeCount; }
    string getNodeName(int idx) const {
        if (idx < 0 || idx >= nodeCount) return "";
        return nodes[idx].getName();
    }

    Node* getNodePtr(int idx) {
        if (idx < 0 || idx >= nodeCount) return nullptr;
        return &nodes[idx];
    }
};
