#include "Header.h"

void showMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Create product\n";
    cout << "2. Add node to product\n";
    cout << "3. Add mechanism to node\n";
    cout << "4. Add detail to mechanism\n";
    cout << "5. Show product info\n";
    cout << "0. Exit\n";
    cout << "==========================\n";
    cout << "Your choice: ";
}

int askIndex(const string& prompt, int maxIndex) {
    int idx;
    while (true) {
        cout << prompt;
        if (!(cin >> idx)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << " Invalid input. Enter number.\n";
            continue;
        }
        cin.ignore(10000, '\n');
        if (idx < 0 || idx > maxIndex) {
            cout << " Index out of range (0.." << maxIndex << ").\n";
            continue;
        }
        return idx;
    }
}

int main() {
    Product products[5];
    int productCount = 0;

    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            if (productCount >= 5) {
                cout << "Max 5 products allowed!\n";
                break;
            }
            string pName, pMat;
            cout << "Enter product name: ";
            getline(cin, pName);
            cout << "Enter product material: ";
            getline(cin, pMat);
            products[productCount++] = Product(pName, pMat);
            cout << "Product created!\n";
            break;
        }

        case 2: {
            if (productCount == 0) {
                cout << "No products yet!\n";
                break;
            }
            cout << "Select product index:\n";
            for (int i = 0; i < productCount; i++)
                cout << " [" << i << "] " << products[i].getName() << endl;

            int pIdx = askIndex("Product index: ", productCount - 1);

            string nName, nMat;
            cout << "Enter node name: ";
            getline(cin, nName);
            cout << "Enter node material: ";
            getline(cin, nMat);

            products[pIdx].addNode(Node(nName, nMat));
            cout << "Node added!\n";
            break;
        }

        case 3: {
            if (productCount == 0) { cout << "No products!\n"; break; }
            cout << "Select product index:\n";
            for (int i = 0; i < productCount; i++)
                cout << " [" << i << "] " << products[i].getName() << endl;
            int pIdx = askIndex("Product index: ", productCount - 1);

            Product* prod = &products[pIdx];
            if (prod->getNodeCount() == 0) { cout << "No nodes in this product!\n"; break; }

            cout << "Select node index:\n";
            for (int i = 0; i < prod->getNodeCount(); i++)
                cout << " [" << i << "] " << prod->getNodeName(i) << endl;
            int nIdx = askIndex("Node index: ", prod->getNodeCount() - 1);

            string mName, mMat;
            cout << "Enter mechanism name: ";
            getline(cin, mName);
            cout << "Enter mechanism material: ";
            getline(cin, mMat);

            Node* node = prod->getNodePtr(nIdx);
            node->addMechanism(Mechanism(mName, mMat));
            cout << "Mechanism added!\n";
            break;
        }

        case 4: {
            if (productCount == 0) { cout << "No products!\n"; break; }
            cout << "Select product index:\n";
            for (int i = 0; i < productCount; i++)
                cout << " [" << i << "] " << products[i].getName() << endl;
            int pIdx = askIndex("Product index: ", productCount - 1);

            Product* prod = &products[pIdx];
            if (prod->getNodeCount() == 0) { cout << "No nodes in product!\n"; break; }

            cout << "Select node index:\n";
            for (int i = 0; i < prod->getNodeCount(); i++)
                cout << " [" << i << "] " << prod->getNodeName(i) << endl;
            int nIdx = askIndex("Node index: ", prod->getNodeCount() - 1);

            Node* node = prod->getNodePtr(nIdx);
            if (node->getMechanismCount() == 0) { cout << "No mechanisms in node!\n"; break; }

            cout << "Select mechanism index:\n";
            for (int i = 0; i < node->getMechanismCount(); i++)
                cout << " [" << i << "] " << node->getMechanismName(i) << endl;
            int mIdx = askIndex("Mechanism index: ", node->getMechanismCount() - 1);

            string dName, dMat;
            cout << "Enter detail name: ";
            getline(cin, dName);
            cout << "Enter detail material: ";
            getline(cin, dMat);

            Mechanism* mech = node->getMechanismPtr(mIdx);
            mech->addDetail(Detail(dName, dMat));
            cout << "Detail added!\n";
            break;
        }

        case 5: {
            if (productCount == 0) { cout << "❌ No products!\n"; break; }
            cout << "Select product index:\n";
            for (int i = 0; i < productCount; i++)
                cout << " [" << i << "] " << products[i].getName() << endl;
            int pIdx = askIndex("Product index: ", productCount - 1);
            products[pIdx].showInfo();
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
