#include <iostream>

class LinkedList {
    struct LinkedListNode {
        int _data{-1};
        LinkedListNode *_next{nullptr};
    };

    LinkedListNode* _start {nullptr};
    size_t _size {0};

public:
    virtual ~LinkedList() {
        auto node = _start;
    }
    [[nodiscard]] size_t size() const {
        return _size;
    }

    void add(int data) {
        //create a new node for the chain.
        auto new_node = new LinkedListNode();
        new_node->_data = data;

        //is this the first node in the chain?
        if (_start == nullptr) {
            //it is the first node in the chain, add a new node and link to start pointer.
            _start = new_node;
        } else {
            //not the first node.

            //find the end of the chain
            auto node = _start;
            auto prev = (LinkedListNode*)nullptr;

            while (node != nullptr) {
                prev = node;
                node = node->_next;
            }

            //attach the new node to the end of the chain
            prev->_next = new_node;
        }

        //increase the number of total nodes
        _size++;
    }

    //inserts a node in an existing chain at the specified index. \param shows what inserting in function.
    /// \param data - the data to be inserted into the new node.
    /// \param index - the index of the new node.

    void insert(int data, int index) {

        //check for invalid index
        if(index > _size) throw std::invalid_argument("index out of range");

        //if inserting at the end, just add a new node.
        if (index == _size) return add(data);

        //create the new node
        auto node = new LinkedListNode();
        node->_data = data;

        //find the position to insert the node.
        auto curr = _start;
        auto prev = (LinkedListNode*)nullptr;

        for (auto i = 0; curr != nullptr && i < index; ++i) {
            prev = curr;
            curr = curr->_next;
        }

        //insert the node.
        if (prev == nullptr) {
            //inserting at the start of the chain.
            node->_next = _start;
            _start = node;
        } else {
            //inserting in the middle or end of the chain.
            node->_next = prev->_next;
            prev->_next = node;
        }
        //increase the total number of nodes
        _size++;
    }

    /// Delete a node in the chain
    /// \param data delete the node with data as its value

    void remove(int data) {

        auto node = _start;
        auto prev = (LinkedListNode*)nullptr;

        //find the node to delete
        while (node != nullptr && node->_data != data) {
            prev = node;
            node = node->_next;
        }

        //did I find the node to delete?
        if (node != nullptr) {
            //we found it!

            // am I deleting the first node?
            if (prev == nullptr) {
                //delete the first node
                _start = node->_next;
            } else {
                //delete a node in the middle or end of the chain.
                prev->_next = node->_next;
            }

            delete node;
            //decrease the total number of nodes
            _size--;
        }

    }

    friend std::ostream& operator<<(std::ostream& output, LinkedList& list);
};

std::ostream& operator<<(std::ostream& output, LinkedList& list) {
    auto node = list._start;

    while (node != nullptr) {
        std::cout << node->_data << " ";
        node = node->_next;
    }

    return output;
}



int main() {

    auto list = LinkedList();

    // Test 1 - Add some numbers to the linked list
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    // Test 2 - Print out the list
    std::cout << "Test 1 - Adding Nodes" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << list << std::endl;

    //test 2 - insert node at the start of an existing chain.
    list.insert(0, 0);

    std::cout << "\nTest 2 - Inserting Nodes" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << list << std::endl;

    //test 3 - insert a node in the middle of an existing chain.
    list.insert(6, 1);

    std::cout << "\nTest 3 - Insert Node(s) in the middle!" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << list << std::endl;

    //test 4 - insert a node at the end of a chain.
    list.insert(7, 7);

    std::cout << "\nTest 4 - Insert Node(s) at the end" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << list << std::endl;

    //test 5 - Delete a node in the linked list.
    list.remove(0); //remove the first zero in the chain.

    std::cout << "\nTest 5 - delete the first node" << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << list << std::endl;

    //test 6 - Delete a node in the middle of the chain.
    list.remove(3);

    std::cout << "\nTest 6 - delete a middle node" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << list << std::endl;

    //test 7 - Delete a node at the end of the chain
    list.remove(7);

    std::cout << "\nTest 7 - delete end node" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << list << std::endl;



    return 0;
}