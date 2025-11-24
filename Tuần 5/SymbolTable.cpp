
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
};

struct symbolTable {
    Node a[100];
    int n;
	symbolTable() : n(0) {} 
	
    void put(const string& key, const string& val) {
        for (int i = 0; i < n; i++) {
            if (a[i].key == key) { 
                a[i].value = val; 
                return;
            }
        }
        a[n].key = key;
        a[n].value = val;
        n++;
    }

	string get(const string& key) {
    	for (int i = 0; i < n; i++) {
        	if (a[i].key == key) {
            	return a[i].value; 
        	}
    	}
    	return ""; 
	}

    void deleteKey(const string& key) {
        for (int i = 0; i < n; i++) {
            if (a[i].key == key) {
                a[i] = a[n - 1]; 
                n--;
                return;
            }
        }
    }

};

int main() {
	symbolTable st;
    st.put("x", "10");
    st.put("y", "20");
    st.put("z", "30");

    cout << "x = " << st.get("x") << endl; 
    cout << "y = " << st.get("y") << endl; 
    cout << "z = " << st.get("z") << endl; 
    st.deleteKey("y");
	cout << "\nSau khi xoa y:\n";
	cout << st.get("x") << endl; 
	cout  << st.get("y") << endl;
}
