#include <iostream>
using namespace std;
template <typename KEY_TYPE, typename DATA_TYPE>
struct Node
{
    KEY_TYPE key;
    DATA_TYPE data;
    Node<KEY_TYPE, DATA_TYPE> *left;
    Node<KEY_TYPE, DATA_TYPE> *right;
    Node<KEY_TYPE, DATA_TYPE> *next;
    Node(const KEY_TYPE &key, const DATA_TYPE &data) : key(key), data(data), left(NULL), right(NULL), next(NULL) {}

    ~Node()
    {
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

template <typename KEY_TYPE, typename DATA_TYPE>
class BST
{
public:
    Node<KEY_TYPE, DATA_TYPE> *root;
    // konstruktor dla pustego drzewa
    BST() : root(NULL) {}

    // destruktor (do zaimplementowania)
    void deleteSubtree(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node == NULL)
            return;

        deleteSubtree(node->left);
        deleteSubtree(node->right);
        delete node;
    }

    ~BST()
    {
        deleteSubtree(this->root);
    }

    // delete
    bool Delete(const KEY_TYPE &arg)
    {
        Node<KEY_TYPE, DATA_TYPE> *current = this->root;
        Node<KEY_TYPE, DATA_TYPE> *parent = NULL;
        bool isLeftChild = false;

        while (current != NULL && !(!(current->key < arg) && !(arg < current->key)))
        {
            parent = current;
            if (arg < current->key)
            {
                current = current->left;
                isLeftChild = true;
            }
            else
            {
                current = current->right;
                isLeftChild = false;
            }
        }

        if (current == NULL)
            return false;

        if (current->left == NULL && current->right == NULL)
        {
            if (current == root)
            {
                root = NULL;
            }
            else if (isLeftChild)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
            delete current;
        }
        else if (current->right == NULL)
        {
            if (current == root)
            {
                root = current->left;
            }
            else if (isLeftChild)
            {
                parent->left = current->left;
            }
            else
            {
                parent->right = current->left;
            }
            delete current;
        }
        else if (current->left == NULL)
        {
            if (current == root)
            {
                root = current->right;
            }
            else if (isLeftChild)
            {
                parent->left = current->right;
            }
            else
            {
                parent->right = current->right;
            }
            delete current;
        }
        else
        {
            Node<KEY_TYPE, DATA_TYPE> *successor = FindSuccessor(current);
            KEY_TYPE successorKey = successor->key;
            DATA_TYPE successorData = successor->data;
            Delete(successor->key);
            current->key = successorKey;
            current->data = successorData;
        }

        return true;
    }
    Node<KEY_TYPE, DATA_TYPE> *FindSuccessor(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        Node<KEY_TYPE, DATA_TYPE> *successor = node->right;
        while (successor->left != NULL)
        {
            successor = successor->left;
        }
        return successor;
    }

    // search
    DATA_TYPE *Search(const KEY_TYPE &k)
    {
        Node<KEY_TYPE, DATA_TYPE> *currentNode = this->root;
        while (currentNode != NULL)
        {
            if (!(k < currentNode->key) && !(currentNode->key < k))
                return &(currentNode->data);
            else if (k < currentNode->key)
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
        }
        return NULL;
    }

    Node<KEY_TYPE, DATA_TYPE> *nodeSearch(const KEY_TYPE &k)
    {
        Node<KEY_TYPE, DATA_TYPE> *currentNode = this->root;
        while (currentNode != NULL)
        {
            if (!(k < currentNode->key) && !(currentNode->key < k))
                return currentNode;
            else if (k < currentNode->key)
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
        }
        return NULL;
    }

    // insert
    bool Insert(const KEY_TYPE &k, const DATA_TYPE &d)
    {
        if (Search(k) != NULL)
            return false;

        Node<KEY_TYPE, DATA_TYPE> *inserted = new Node<KEY_TYPE, DATA_TYPE>(k, d);
        if (this->root == NULL)
        {
            this->root = inserted;
            return true;
        }

        Node<KEY_TYPE, DATA_TYPE> *current = this->root;
        Node<KEY_TYPE, DATA_TYPE> *parent = NULL;

        while (current != NULL)
        {
            parent = current;

            if (k < current->key)
                current = current->left;
            else
                current = current->right;
        }

        if (k < parent->key)
            parent->left = inserted;
        else
            parent->right = inserted;

        return true;
    }

    //
    void InOrder()
    {
        InorderDisplay(this->root);
    }
    void InorderDisplay(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node == NULL)
            return;

        InorderDisplay(node->left);
        cout << node->key << node->data;
        InorderDisplay(node->right);
    }
    // Postorder
    void PostOrder()
    {
        PostorderDisplay(this->root);
    }
    void PostorderDisplay(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node == NULL)
            return;

        PostorderDisplay(node->left);
        PostorderDisplay(node->right);
        cout << node->key << node->data;
    }
    // Preorder
    void PreOrder()
    {
        PreorderDisplay(this->root);
    }
    void PreorderDisplay(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node == NULL)
            return;

        cout << node->key << node->data;
        PreorderDisplay(node->left);
        PreorderDisplay(node->right);
    }
    // Levelorder
    class Queue
    {
    public:
        struct QueueNode
        {
            Node<KEY_TYPE, DATA_TYPE> *data;
            QueueNode *next;

            QueueNode(Node<KEY_TYPE, DATA_TYPE> *node) : data(node), next(NULL) {}
        };

        QueueNode *front;
        QueueNode *rear;
        int count;

        Queue() : front(NULL), rear(NULL), count(0) {}

        ~Queue()
        {
            while (!isEmpty())
                dequeue();
        }

        bool isEmpty()
        {
            return front == NULL;
        }

        void enqueue(Node<KEY_TYPE, DATA_TYPE> *node)
        {
            QueueNode *newNode = new QueueNode(node);

            if (isEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }

            count++;
        }

        void dequeue()
        {
            if (isEmpty())
                return;

            QueueNode *tmp = front;
            front = front->next;
            delete tmp;

            count--;
        }

        int size()
        {
            return count;
        }
    };

    void LevelOrder()
    {
        if (this->root == NULL)
            return;

        Queue queue;
        queue.enqueue(this->root);

        while (!queue.isEmpty())
        {
            int size = queue.size();

            for (int i = 0; i < size; i++)
            {
                Node<KEY_TYPE, DATA_TYPE> *current = queue.front->data;
                queue.dequeue();
                cout << current->key << current->data;

                if (current->left != NULL)
                    queue.enqueue(current->left);

                if (current->right != NULL)
                    queue.enqueue(current->right);
            }
        }
    }
    // Height
    int Height()
    {
        return valueOfHeight(this->root);
    }
    int valueOfHeight(Node<KEY_TYPE, DATA_TYPE> *node)
    {
        if (node == NULL)
            return -1;

        int leftSubtree = valueOfHeight(node->left);
        int rightSubtree = valueOfHeight(node->right);

        return 1 + (leftSubtree > rightSubtree ? leftSubtree : rightSubtree);
    }
};
