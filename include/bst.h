#include <memory>
#include <string>
#include <optional>

template <typename T>
class BST {

    private:
    class Node {
        friend class BST;
        private:
            T data;
            std::shared_ptr<Node> left;
            std::shared_ptr<Node> right;
        
        public:
            Node(T data): data{data} {};
            ~Node() = default;
    };

    private:
    std::shared_ptr<Node> root;
    uint16_t size = 0;
    std::shared_ptr<Node> insert_node(std::shared_ptr<Node> node, T data) {
        if (data == node->data) {
            return node;
        } else if (data < node->data) {
            if (!node->left) {
                node->left = std::make_shared<Node>(data);
                return node->left;
            } else {
                return insert_node(node->left, data);
            }
        } else {
            if (!node->right) {
                node->right = std::make_shared<Node>(data);
                return node->right;
            } else {
                return insert_node(node->right, data);
            }
        }

    }
    std::string in_order_trav_node(std::shared_ptr<Node> node) {
        if (!node) {
            return "";
        }
        return in_order_trav_node(node->left) 
        + std::to_string(node->data) + " " + in_order_trav_node(node->right);
    }

    std::optional<std::shared_ptr<Node>> find_node(std::shared_ptr<Node> node, T data) {
        if (!node) {
            return std::optional<std::shared_ptr<Node>>();
        } 
    }

    public:
    BST() = default;
    std::shared_ptr<Node> insert(T data) {
        if (!root) {
            root = std::make_shared<Node>(data);
            return root;
        }
        return insert_node(root, data);
    }

    std::string in_order_traversal() {
        return in_order_trav_node(root);
    }

    std::optional<std::shared_ptr<Node>> find(T data) {
        return find_node(root, data);
    }

};