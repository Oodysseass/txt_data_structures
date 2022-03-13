#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * Class denoting an AVL search tree with words.
 */
class AVL
{
public:
    string word;
    AVL *left, *right;
    long long unsigned int timesAppeared;
    long long unsigned int height;


    /**
     * Default constructor
     */
    AVL();

    /**
     * Initializes a node with its word and 1 time appeared.
     *
     * @param word the word the node will store.
     */
    AVL(string word);

    /**
     * Inserts recursively a word to the AVL, then balances the tree if necessary.
     *
     * @param root the starting node of the tree.
     * @param word the word to be added to the tree.
     * @return the new node with the word.
     */
    AVL* addWord(AVL* root, string word);

    /**
     * Searches the tree recursively for a word.
     *
     * @param root the starting node of the tree.
     * @param word the word to be searched.
     * @return the node with the word or NULL if the word is not in the tree.
     */
    AVL* searchWord(AVL* root, string word);

    /**
     * Deletes a word from the AVL, then balances the tree if necessary.
     *
     * @param word the word to be removed.
     * @return the new root.
     */
    AVL* deleteWord(AVL* root, string word);

    /**
     * Rotates the AVL to the right, then reassigns the right heights.
     *
     * @param root the root of the subtree to be rotated.
     * @return new root.
     */
    AVL* rotateRight(AVL* root);

    /**
     * Rotates the AVL to the right, then reassigns the right heights.
     *
     * @param root the root of the subtree to be rotated.
     * @return new root.
     */
    AVL* rotateLeft(AVL* root);

    /**
     * Prints the tree in inorder order. (i.e. in sorted order)
     *
     * @param root the starting node of the tree.
     */
    void inorder(AVL* root);

    /**
     * Prints the tree in preorder order.
     *
     * @param root the starting node of the tree.
     */
    void preorder(AVL* root);

    /**
     * Prints the tree in postorder order.
     *
     * @param root the starting node of the tree.
     */
    void postorder(AVL* root);

    /**
     * Prints how many times a word is used.
     *
     * @param root the starting node of the tree.
     * @param word the word to be searched.
     */
    void printInfo(AVL* root, string word);

    /**
     * Gets the height of the node, that is how many levels of nodes are under this node.
     *
     * @param root the root whose height we need.
     * @return the height of the root.
     */
    int getHeight(AVL* root);

    /**
     * Gets the balance of the node, that is the difference of heights between left
     * and right children.
     *
     * @param root the root whose balance we need.
     * @return the balance of the root
     */
    int getBalance(AVL* root);
};
#endif // AVL_H
