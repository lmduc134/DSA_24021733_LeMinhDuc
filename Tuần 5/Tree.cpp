#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	
	Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// chen phan tu bst
Node* insert(Node* root, int value) {
	if(root == nullptr) {
		return new Node(value);
	}
	if(value < root->data) {
		root->left = insert(root->left, value);
	}
	else {
		root->right = insert(root->right,value);
	}
	return root;
}

// tim kiem tren bst
Node* search(Node* root, int x) {
	if(root == nullptr || root->data == x) {
		return root;
	}
	if(x > root->data) {
		return search(root->right, x);
	}
	else {
		return search(root->left, x);
	} 
}

// duyet cay theo 3 cach
void preOrder(Node* root) {
	if(root == nullptr) {
		return;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root) {
	if(root == nullptr) {
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(Node* root) {
	if(root == nullptr) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

// xoa phan tu bst

Node* findMin(Node* root) {
	while(root->left != nullptr) {
		root = root->left;
	}
	return root;
}

Node* remove(Node* root, int k) {
    if(root == nullptr)
        return nullptr;

    if(k < root->data)
        root->left = remove(root->left, k);
    else if(k > root->data)
        root->right = remove(root->right, k);
    else {
        if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right); 
        root->data = temp->data;           
        root->right = remove(root->right, temp->data);
    }
    return root;
}

int main() {
	Node* root = nullptr;
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 4);
	root = insert(root, 9);
	root = insert(root, 8);
	cout << "cay truoc khi xoa phan tu: " << endl;
	preOrder(root);
	cout << endl;
	int x = 4;
	Node* result = search(root, x);
	if(result != nullptr) {
		cout << "tim thay " << x << " trong cay" << endl;
	}
	else {
		cout << "khong tim thay " << x << " trong cay" << endl;;
	}
	cout << "cay sau khi xoa phan tu: " << endl;
	root = remove(root, 1);
	preOrder(root);
}
