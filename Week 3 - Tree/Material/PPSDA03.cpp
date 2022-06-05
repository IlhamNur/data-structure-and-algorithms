#include <iostream>
#include <vector>
using namespace std;

// node
typedef struct Node{
    string value;
    Node *parent = nullptr;
    vector <Node*> children;
}Node;

//tree
typedef struct Tree {
    Node *root = nullptr;
}Tree;


int main () {
    //node parent
    Node parent;
    parent.value = "Dono";

    //node clildren
    Node child1, child2, child3;
    child1.value = "Andi";
    child1.parent = &parent;
    child2.value = "Budi";
    child2.parent = &parent;
    child3.value = "Cindy";
    child3.parent = &parent;

    //parent punya anak siapa aja
    parent.children.push_back(&child1);
    parent.children.push_back(&child2);
    parent.children.push_back(&child3);

    //buat tree
    Tree family;
    family.root = &parent;

    cout << "anak ke-1 : "<< family.root->children[0]->value << endl;
    cout << "anak ke-2 : "<< family.root->children[1]->value << endl;
    cout << "anak ke-3 : "<< family.root->children[2]->value << endl;

    return 0;

}