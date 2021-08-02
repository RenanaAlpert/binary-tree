#include <iostream>
#include <string>
#include <queue>

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        //template <typename T>
        class Node
        {
            T value;
            Node *left;
            Node *right;
            Node *parent;

            explicit Node(T val = 0, Node *l = nullptr, Node *r = nullptr, Node *p = nullptr) : value(val), left(l), right(r), parent(p){};

        public:
            T &get_value()
            {
                return this->value;
            }

            Node *get_left()
            {
                return this->left;
            }

            Node *get_right()
            {
                return this->right;
            }

            Node *get_parent()
            {
                return this->parent;
            }

            friend ostream &operator<<(ostream &out, const Node &n)
            {
                return out;
            }
        };

        Node *root;

    public:
        BinaryTree<T>(){};
        ~BinaryTree<T>(){};
        BinaryTree<T> &add_root(T root)
        {
            return *this;
        }
        BinaryTree<T> &add_left(T father, T l)
        {
            return *this;
        }
        BinaryTree<T> &add_right(T father, T r)
        {
            return *this;
        }

        //template <typename T>
        class iterator
        {
            private:
                Node *current;
                std::queue<Node> q;
                void preorder(Node *n)
                {
                    /*if (n == nullptr)
                    {
                        return;
                    }
                    else
                    {
                        this->q.push(*n);
                        preorder(n->get_left());
                        preorder(n->get_right());
                    }*/
                }
                void postorder(Node *n)
                {
                    /*if (n == nullptr)
                    {
                        return;
                    }
                    else
                    {
                        postorder(n->get_left());
                        postorder(n->get_right());
                        this->q.push(*n);
                    }*/
                }
                void inorder(Node *n)
                {
                    /*if (n == nullptr)
                    {
                        return;
                    }
                    else
                    {
                        inorder(n->get_left());
                        this->q.push(*n);
                        inorder(n->get_right());
                    }*/
                }

            public:
                explicit iterator(const std::string type, Node *pTree = nullptr) : current(pTree)
                {
                    if (current != nullptr)
                    {
                        if(type.compare("pre")){
                            preorder(this->current);
                        }
                        else if(type.compare("in")){
                            inorder(this->current);
                        }
                        else if(type.compare("post")){
                            postorder(this->current);
                        }
                        this->current = &(this->q).front();
                    }
                }
                iterator &operator++()
                {
                    return *this;
                }
                iterator &operator++(int)
                {
                    return *this;
                }
                bool operator==(const iterator &other) const
                {
                    return false;
                }
                bool operator!=(const iterator &other) const
                {
                    return false;
                }
                T &operator*() const
                {
                    return this->current->get_value();
                }

                T *operator->() const
                {
                    return &(this->current->get_value());
                }

                friend ostream &operator<<(ostream &out, const iterator &num)
                {
                    return out;
                }
        };

        BinaryTree<T>::iterator begin()
        {
            return begin_inorder();
        }
        BinaryTree<T>::iterator end()
        {
            return end_inorder();
        }
        BinaryTree<T>::iterator begin_preorder()
        {
            return iterator("pre", root);
        }
        BinaryTree<T>::iterator end_preorder()
        {
            return iterator("pre");
        }
        BinaryTree<T>::iterator begin_inorder()
        {
            return iterator("in", root);
        }
        BinaryTree<T>::iterator end_inorder()
        {
            return iterator("in");
        }
        BinaryTree<T>::iterator begin_postorder()
        {
            return iterator("post", root);
        }
        BinaryTree<T>::iterator end_postorder()
        {
            return iterator("post");
        }

        friend ostream &operator<<(ostream &out, const BinaryTree<T> &num)
        {
            return out;
        }
    };
}