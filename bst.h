#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * Class denoting a binary search tree with words.
 */
class BST
{
public:
    string word;
    BST *left, *right;
    long long unsigned int timesAppeared;


    /**
     * Default constructor
     */
    BST();

    /**
     * Initializes a node with its word and 1 time appeared.
     *
     * @param word the word the node will store.
     */
    BST(string word);

    /**
     * Inserts recursively a word to the BST.
     *
     * @param root the starting node of the tree.
     * @param word the word to be added to the tree.
     * @return the new node with the word.
     */
    BST* addWord(BST* root, string word);

    /**
     * Searches the tree recursively for a word.
     *
     * @param root the starting node of the tree.
     * @param word the word to be searched.
     * @return the node with the word or NULL if the word is not in the tree.
     */
    BST* searchWord(BST* root, string word);

    /**
     * Deletes a word from the tree.
     *
     * @param word the word to be removed.
     * @return the new root.
     */
    BST* deleteWord(BST* root, string word);

    /**
     * Prints the tree in inorder order. (i.e. in sorted order)
     *
     * @param root the starting node of the tree.
     */
    void inorder(BST* root);

    /**
     * Prints the tree in preorder order.
     *
     * @param root the starting node of the tree.
     */
    void preorder(BST* root);

    /**
     * Prints the tree in postorder order.
     *
     * @param root the starting node of the tree.
     */
    void postorder(BST* root);

    /**
     * Prints how many times a word is used.
     *
     * @param root the starting node of the tree.
     * @param word the word to be searched.
     */
    void printInfo(BST* root, string word);
};
#endif // BST_H
