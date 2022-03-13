#include "bst.h"

BST::BST(){
    word = "";
    timesAppeared = 0;
    left = NULL;
    right = NULL;
}

BST::BST(string word){
    this->word = word;
    timesAppeared = 1;
    left = NULL;
    right = NULL;
}

BST* BST::addWord(BST* root, string word){
    if(!root)
        return new BST(word);
    else if(word > root->word)
        root->right = addWord(root->right, word);
    else if(word < root->word)
        root->left = addWord(root->left, word);
    else if(word == root->word){
        root->timesAppeared++;
    }
    return root;
}

BST* BST::searchWord(BST* root, string word){
    if(!root || root->word == word)
        return root;
    else if(root->word > word)
        return searchWord(root->left, word);
    else if(root->word < word)
        return searchWord(root->right, word);
    return NULL;
}

BST* BST::deleteWord(BST* root, string word){
    if(!root)
        return root;
    else if(root->word > word){
        root->left = deleteWord(root->left, word);
        return root;
    }
    else if(root->word < word){
        root->right = deleteWord(root->right, word);
        return root;
    }
    if (root->left == NULL) {
        BST* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        BST* temp = root->left;
        delete root;
        return temp;
    }
    else {
        BST* succParent = root;
        BST* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->word = succ->word;
        delete succ;
        return root;
    }
}

 void BST::inorder(BST* root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->word << endl;
    inorder(root->right);
}

void BST::preorder(BST* root){
    if (!root)
        return;
    cout << root->word << endl;
    preorder(root->left);
    preorder(root->right);
}

void BST::postorder(BST* root){
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->word << endl;
}

void BST::printInfo(BST* root, string word){
    BST* temp = searchWord(root, word);
    if(!temp)
        cout << "The word \"" << word << "\" is used 0 times." << endl;
    else
        cout << "The word \"" << word << "\" is used " << temp->timesAppeared << (temp->timesAppeared > 1  ? " times." : " time.") << endl;
}
