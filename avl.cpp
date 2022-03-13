#include "AVL.h"

AVL::AVL(){
    word = "";
    timesAppeared = 0;
    height = 1;
    left = NULL;
    right = NULL;
}

AVL::AVL(string word){
    this->word = word;
    timesAppeared = 1;
    height = 1;
    left = NULL;
    right = NULL;
}

AVL* AVL::addWord(AVL* root, string word){
    if(!root)
        return new AVL(word);
    else if(word > root->word)
        root->right = addWord(root->right, word);
    else if(word < root->word)
        root->left = addWord(root->left, word);
    else if(word == root->word){
        root->timesAppeared++;
    }
    root->height = 1 + (getHeight(root->left) > getHeight(root->right))? getHeight(root->left) : getHeight(root->right);
    int balance = getBalance(root);
    if (balance > 1 && word < root->left->word)
        return rotateRight(root);
    if (balance < -1 && word > root->right->word)
        return rotateLeft(root);
    if (balance > 1 && word > root->left->word){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && word < root->right->word){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

AVL* AVL::rotateRight(AVL* root)
{
    AVL* left = root->left;
    AVL* right = left->right;
    left->right = root;
    root->left = right;
    root->height = 1 + (getHeight(root->left) > getHeight(root->right))? getHeight(root->left) : getHeight(root->right);
    left->height = 1 + (getHeight(left->left) > getHeight(left->right))? getHeight(left->left) : getHeight(left->right);
    return left;
}

AVL* AVL::rotateLeft(AVL* root)
{
    AVL* right = root->right;
    AVL* left = right->left;
    right->left = root;
    root->right = left;
    root->height = 1 + (getHeight(root->left) > getHeight(root->right))? getHeight(root->left) : getHeight(root->right);
    right->height = 1 + (getHeight(right->left) > getHeight(right->right))? getHeight(right->left) : getHeight(right->right);
    return right;
}

AVL* AVL::searchWord(AVL* root, string word){
    if(!root || root->word == word)
        return root;
    else if(root->word > word)
        return searchWord(root->left, word);
    else if(root->word < word)
        return searchWord(root->right, word);
    return NULL;
}

AVL* AVL::deleteWord(AVL* root, string word){
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
        AVL* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        AVL* temp = root->left;
        delete root;
        return temp;
    }
    else {
        AVL* succParent = root;
        AVL* succ = root->right;
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
    if(!root) {
        return root;
    }
    int balance = getBalance(root);
    int balanceLeft = getBalance(root->left);
    int balanceRight = getBalance(root->right);
    if(balance > 1 && balanceLeft >= 0) {
        return rotateRight(root);
    }
    else if(balance > 1 && balanceLeft < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    else if(balance < -1 && balanceRight <=0 ) {
        return rotateLeft(root);
    }
    else if(balance < -1 && balanceRight > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

int AVL::getBalance(AVL* root) {
    if(root)
        return getHeight(root->left) - getHeight(root->right);
    return 0;
}

int AVL::getHeight(AVL* root) {
  if(root)
    return root->height;
  return 0;
}

 void AVL::inorder(AVL* root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->word << endl;
    inorder(root->right);
}

void AVL::preorder(AVL* root){
    if (!root)
        return;
    cout << root->word << endl;
    preorder(root->left);
    preorder(root->right);
}

void AVL::postorder(AVL* root){
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->word << endl;
}

void AVL::printInfo(AVL* root, string word){
    AVL* temp = searchWord(root, word);
    if(!temp)
        cout << "The word \"" << word << "\" is used 0 times." << endl;
    else
        cout << "The word \"" << word << "\" is used " << temp->timesAppeared << (temp->timesAppeared > 1  ? " times." : " time.") << endl;
}
