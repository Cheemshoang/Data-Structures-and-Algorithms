#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val; //value
	Node *left;
	Node *right;
	
	//constructor: khoi tao node moi
	Node(int v) : val(v), left(nullptr), right(nullptr){}
};


class BinaryTree{
	private:
		//root la pointer den Node
		Node* root;
		
	public:
		//constructor: khoi tao root, val = nullptr
		BinaryTree(): root(nullptr){}
		
		
		// Ham tra e con tro toi Node(root) co the goi ngoai class
	    Node* getRoot() {
	        return root; //get root tu private
	    }
	    
		void insertRoot(int v){
			if(!root) root = new Node(v);
		}
		
		void insertLeft(Node* p, int v){
			if(p && !p -> left) p->left = new Node(v);
		}
		
		void insertRight(Node* p, int v){
			if(p && !p -> right) p->right = new Node(v);
		}
		
		// Transversal
	    
	    //Preorder: root-left-right
	    void preorder(Node* root){
	    	if(!root) return;
	    	cout << root->val << " ";
	    	preorder(root->left);
	    	preorder(root->right);
	    }
	    
	    //Inorder: left-root-right
	    void inorder(Node* root){
	    	if(!root) return;
	    	inorder(root->left);
	    	cout << root->val << " ";
	    	inorder(root->right);
	    }
	    
	    //Postorder: left-right-root
	    void postorder(Node* root){
	    	if(!root) return;
	    	postorder(root->left);
	    	postorder(root->right);
	    	cout << root->val << " ";
	    }
	    
	    //BFS on Binary tree (queue)
	    void levelOrder(Node* root){
	    	if(!root) return;
	    	
	    	queue<Node*> q;
	    	q.push(root);
	    	
	    	while(!q.empty()){
	    		Node* curr = q.front();
	    		q.pop();
	    		
	    		cout << curr->val << " ";
	    		
	    		if(curr->left) q.push(curr->left);
	    		if(curr->right) q.push(curr->right);
	    		
	    	}
	    }
	    
	    //Spiral (stack)
	    void spiral(Node* root) {
		    if (!root) return;
		
		    stack<Node*> s1; // level in right to left
		    stack<Node*> s2; // level in left to right
		
		    s1.push(root);
		
		    while (!s1.empty() || !s2.empty()) {
		        // xử lý stack s1: phải sang trái
		        while (!s1.empty()) {
		            Node* curr = s1.top();
		            s1.pop();
		            cout << curr->val << " ";
		
		            // push con vào s2: left trước right
		            if (curr->left) s2.push(curr->left);
		            if (curr->right) s2.push(curr->right);
		        }
		
		        // xử lý stack s2: trái sang phải
		        while (!s2.empty()) {
		            Node* curr = s2.top();
		            s2.pop();
		            cout << curr->val << " ";
		
		            // push con vào s1: right trước left
		            if (curr->right) s1.push(curr->right);
		            if (curr->left) s1.push(curr->left);
		        }
		    }
		}
	    
	    
	    
		
};

class BST{
	private:
		Node* root;
		
		//search 
		Node* search(Node* node, int val){
			if(!node || node->val == val) return node;
			else if(val < node->val) return search(node->left, val);
			else return search(node->right, val);
		}
		
		
		//insert
		Node* insert(Node* node, int val){
			if(!node) return new Node(val);
			if (val < node->val) node->left = insert(node->left, val);
			else if(val > node->val) node->right = insert(node->right, val);
			
			//val == node->val ko insert
			return node;
		}
		
		//findMin helper func
		Node* findMin(Node* node) {
	    while (node && node->left) 
	        node = node->left;
	    return node; //return min node
		}
		
		
		Node* remove(Node* node, int val) {
		    if (!node) return nullptr;  // node rong -> nullptr
		
		    if (val < node->val) 
		        node->left = remove(node->left, val);   
		    else if (val > node->val) 
		        node->right = remove(node->right, val); 
		    else {
		        // Node cần xóa
		        if (!node->left) { 
		            Node* temp = node->right; // node con phải thay thế
		            delete node; 
		            return temp;
		        } else if (!node->right) { 
		            Node* temp = node->left; // node con trái thay thế
		            delete node; 
		            return temp;
		        } else {
		            // Node có 2 con: tìm node nhỏ nhất bên phải (trai < node < phai)
		            Node* temp = findMin(node->right);
		            node->val = temp->val; // Thay giá trị
		            node->right = remove(node->right, temp->val); // Xóa node nhỏ nhất bên phải
		        }
		    }
		    return node; // Trả về node sau khi xóa
		}
		
		
		public:
		    BST() : root(nullptr) {}
		    Node* getRoot() { return root; }
		    Node* search(int val) { return search(root, val); }
		    void insert(int val) { root = insert(root, val); }
		    void remove(int val) { root = remove(root, val); }
		
		    void inorder(Node* node) {
		        if(!node) return;
		        inorder(node->left);
		        cout << node->val << " ";
		        inorder(node->right);
		    }

};


void testing_BinaryTree() {
    BinaryTree bt;

    // Level 0: root
    bt.insertRoot(10);
    Node* root = bt.getRoot();

    // Level 1
    bt.insertLeft(root, 5);
    bt.insertRight(root, 15);

    // Level 2
    bt.insertLeft(root->left, 3);
    bt.insertRight(root->left, 7);
    bt.insertLeft(root->right, 12);
    bt.insertRight(root->right, 18);

    // Level 3
    bt.insertLeft(root->left->left, 1);
    bt.insertRight(root->left->left, 4);
    bt.insertLeft(root->left->right, 6);
    bt.insertRight(root->left->right, 8);
    bt.insertLeft(root->right->left, 11);
    bt.insertRight(root->right->left, 13);
    bt.insertLeft(root->right->right, 17);
    bt.insertRight(root->right->right, 20);

    cout << "BinaryTree Traversals:" << endl;
    cout << "Preorder: ";
    bt.preorder(root);   
    cout << endl;

    cout << "Inorder: ";
    bt.inorder(root);    
    cout << endl;

    cout << "Postorder: ";
    bt.postorder(root);  
    cout << endl;

    cout << "Level-order: ";
    bt.levelOrder(root);  
    cout << endl;

    cout << "Spiral order: ";
    bt.spiral(root);
    cout << endl;
}

void testing_BST() {
    BST tree;

    // Insert node for BST
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "\nBST Traversals:" << endl;
    cout << "Inorder: ";
    tree.inorder(tree.getRoot());
    cout << endl;

    Node* found = tree.search(7);
    if (found) cout << "Found 7" << endl;
    else cout << "No 7" << endl;

    tree.remove(5); 
    cout << "Inorder after deleting 5: ";
    tree.inorder(tree.getRoot());
    cout << endl;
}

int main() {
    testing_BinaryTree();
    testing_BST();
    return 0;
}




