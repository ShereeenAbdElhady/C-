/*
Data structure: a collection of data elements whose organization is characterized
                by accessing operations that are used to store and retreive the individual data elements.

- Integers & float > simple data structure.
- Array            > complex data structure.
                  and it is the best data types in time accessing as it can be accessed randomly.
                  
- Linked list    > is the best data type from the point of view of memory
                   as the data elements are reserved in a discrete not contiguous memory
                   locations like the array
                   and that's why we use the pointers in the linked list so that each node
                   can refer to the next one using pointers.   
                  > Also linked list solves the bad insertion array problem as previously
                   using the array when we needed to insert a number, we had to shift 
                   all of the indecies starting from the index of the number that we need to insert
                   but using linked list, all we need to do is let the previous node pointer
                   points to the new node and the new node points to the next node
                   p[n-1] -> p[n] -> p[n+1]   

                   >Also it solves the bad removal array problem as well which is
                   when we need to remove specific index, then we will need to shift all 
                   of the other indecies.
                   
                   > there are two types of linked lists

                   Singly linked list: large access time O(N) as it is sequential, to reach one node
                   you have to pass through all of the previous ones.

                   StartPtr->                         <- EndPtr
                             [Node]-> [Node] -> [Node] 

                    Double linked list: 
                    StartPtr->                         <- EndPtr
                             [Node]-> [Node] -> [Node] 
                                   <-        <-       

- NB: as the linked list increases, the time increases                                   
                                   
- Linked list operations (functions) 
                       > Add first
                       > Add last
                       > Add index
                       > Delete first
                       > Delete last
                       > Delete index     
                       > Read index   
                       > Read first
                       > Read last                            
*/

                            /***** Passing a struct by value, pointer to struct and reference******/

                            /*  When working with linked lists in C++, you often pass either a struct (node) or a pointer to a struct (node pointer) to functions. 
                            The difference between these approaches affects performance and behavior:

1. Passing the Struct (By Value)
If you pass a struct by value, a copy of the struct is created and used within the function.
 Any modifications inside the function do not affect the original struct outside.

Example:
struct Node {
    int data;
    Node* next;
};

// Function that takes the struct by value
void modifyNode(Node node) 
{
    node.data = 100;  // This only changes the copied struct, not the original
}

int main() {
    Node node1 = {10, nullptr};

    modifyNode(node1);
    
    std::cout << "Original node data: " << node1.data << std::endl; // Output: 10 (unchanged)

    return 0;
}
Key Points:
         > Creates a new copy of the struct, increasing memory usage.
         > Any modifications are lost after the function call.
         > Can be inefficient for large data structures.

2. Passing a Pointer to the Struct
If you pass a pointer to a struct, you are passing the address of the struct, 
meaning any modifications made inside the function directly affect the original struct.

Example:
struct Node {
    int data;
    Node* next;
};

// Function that takes a pointer to the struct
void modifyNode(Node* node) {
    if (node) {
        node->data = 100;  // Modifies the original node
    }
}

int main() {
    Node node1 = {10, nullptr};

    modifyNode(&node1);
    
    std::cout << "Original node data: " << node1.data << std::endl; // Output: 100 (modified)

    return 0;
}
Key Points:
           > Avoids copying, making it more efficient.
           > Changes affect the original struct.
           > Function must check for nullptr to avoid dereferencing a null pointer.

3. Passing a Reference to the Struct
A reference behaves like a pointer but provides a cleaner syntax while still allowing modification of the original struct.

Example:
void modifyNode(Node& node) {
    node.data = 100;  // Modifies the original struct
}

int main() {
    Node node1 = {10, nullptr};

    modifyNode(node1);
    
    std::cout << "Original node data: " << node1.data << std::endl; // Output: 100 (modified)
}
Key Points:
         > Similar to passing a pointer but with simpler syntax.
         > Always valid (cannot be null).
         > Direct modifications affect the original struct.          

Which to Use in a Linked List?
For linked lists, always pass a pointer (or reference) to a struct because:
1- Nodes are dynamically allocated (new in C++).
2- Passing by value creates unnecessary copies.
3- You need to modify next pointers to update links between nodes.         */




                                  /******** Linked List ***********/
#include <iostream>

// structure to describe any element in the linked list
struct  Node
{
    /* data */
    int data;
    // points to the next node
    struct Node* Next;
    //points to the prev node, used in double linked list
    //struct Node* Prev;
};

// class to describe the linked list itself
class LinkedList
{
    private:
    //points to the first node in the list
    struct Node *first;
    // points to the last node in the list
    struct Node *last;
    // counter to count the number of nodes
    int counter;

    public:

    // Class constructor
    LinkedList()
    {
        first = nullptr;
        last = nullptr;
        counter = 0;
    }

    // Destructor to free memory
    ~LinkedList() 
    {
        Node* current = first;
        while (current != NULL)
         {
            Node* temp = current;
            current = current->Next;
            delete temp;
         }
    }
       

   // function to insert a node at the beginning of the linked list

    // /* This function has a critical issue related to memory allocation and pointer assignment.*/
    // void InsertFirst (Node* dd)
    // {
    //     /* Problem 1 Memory Leak & Overwritten Pointer
    //     You allocate memory for a new node with new Node, but then immediately overwrite temp with dd, 
    //     losing the reference to the allocated memory.
    //     This causes a memory leak because the originally allocated node (new Node) is never used or deleted.*/
    //     // dynamic memory allocation using new operator of size Node, to create new temp node
    //     Node *temp = new Node;
    //     // new temp node equals the new node to be inserted
    //     temp = dd;

    //     /* Problem 2 The Function Expects a Pre-Allocated Node
    //        function takes Node* dd as an argument, which implies that the caller is creating 
    //        and passing an already allocated node.
    //        However, the function currently treats dd like newly created data and tries to modify its Next pointer.
    //        If dd was already part of another list, this could break the other list’s structure.*/


    //     // next points to the start of the linked list to Null
    //     temp->Next = first;
    //     // assign the new node address to the start of the linked list
    //     first = temp;
    //     if (last == nullptr)
    //     {
    //         last = temp;
    //     }
    //     // counter to count the number of nodes
    //     counter++;
    // }

    /* The function is expecting a pre-allocated node */
    void InsertFirst (Node* dd)
    {
        if (dd == nullptr) 
        {
            // Prevent inserting a null node
            return; 
        }
        // Link new node to the current first node
        dd->Next = first; 
        // assign the new node address to the start of the linked list 
        first = dd;  
        // If list was empty, last should also point to dd      
        if (last == nullptr) 
        { 
            last = dd;
        }
        // Increment node count
        counter++;  
    }

    // /* Create a New Node Inside the Function */
    // void InsertFirst (int data)
    // {
    //     // dynamic memory allocation using new operator of size Node, to create new temp node
    //     Node* NewNode = new Node;
    //     // initialize the new node data
    //     NewNode->data = data;
    //     // next points to the start of the linked list to Null
    //     NewNode->Next = first;
    //     // assign the new node address to the start of the linked list
    //     first = NewNode;

    //     if (last == nullptr)
    //     {
    //         last = NewNode;
    //     }

    //     // Increment node count
    //     counter++; 
    // }


    void InsertLast (Node* dd)
    {
        if (dd == nullptr) 
        {
            // Prevent inserting a null node
            return; 
        }

        // Ensure the new node does not point to any next node
        dd->Next = nullptr;

        // If the list was empty 
        if (last == nullptr)
        {
            first = last = dd;
        }
        else
        {
            // Link the new node to the end of the list
            last-> Next = dd;
            // Update the last pointer
            last = dd;
        }
        // Increment node counter
        counter++;
    }

    void InsertIndex (int index, Node* dd)
    {
        if (dd == nullptr) 
        {
            // Prevent inserting a null node
            return; 
        }

        // if we need to add the node in the beginning 
        if (index <= 1)
        {
            InsertFirst(dd);
            return;
        }

        // if the index greater than the nodes counter, then insert last
        if (index > counter)
        {
            InsertLast(dd);
            return;
        }

        Node *temp1 = first;

        // Traverse to node at position (index - 1)
        for (int i =1; i < index-1 && temp1 != nullptr ; i++)
        {
            temp1 = temp1->Next;
        }

        // Ensure temp1 is valid before inserting
        if (temp1 == nullptr) return;

        // Insert the new node
        dd->Next = temp1->Next;
        temp1->Next = dd;
        counter++;

    }

    void DeleteFirst(void)
    {
        // save first node address
        Node* temp =  first;

        // in case of empty list
        if (temp == nullptr)
        {
            std::cout << "Error, you can't delete first node from an empty list" << std::endl;
            return;
        }
        
        // make the first node address points to the next node
        first = first->Next;
        // If list is now empty, reset last
        if (first == nullptr)
        {
            last = nullptr;
        }

        // delete the old first node
        delete temp;

        // Ensure counter doesn't become negative
        if (counter > 0)
        {
            // decrement nodes counter
            counter--;
        }
    }

    void DeleteLast (void)
    {
        // save first node address
        Node* temp =  first;

        // in case of empty list
        if (temp == nullptr)
        {
            std::cout << "Error, you can't delete last node from an empty list" << std::endl;
            return;
        }

        // in case there is only one node in the list
        if (first == last) 
        {
            delete first;
            first = last = nullptr;
            counter = 0; // Reset counter
            return;
        }

        while (temp->Next != last)
        {
            temp = temp->Next;
        }

        delete last;
        last = temp;
        temp->Next = nullptr;
        
        // Ensure counter doesn't become negative
        if (counter > 0)
        {
            // decrement nodes counter
            counter--;
        }
    }

    void DeleteIndex (int index)
    {
        if ( index <= 1)
        {
            DeleteFirst();

            return;
        }

        if (index >= counter)
        {
            DeleteLast();
            return;
        }
        Node *temp, *temp2;
        temp = first;

        // Traverse to node before the one to delete
        for (int i=1; i < index-1 && temp != nullptr ; i++)
        {
            temp = temp->Next;
        }
        // Node to delete
        temp2 = temp->Next;
        // Skip temp2
        temp->Next = temp2 ->Next;

        // Free memory
        delete temp2;

        // Ensure counter doesn't become negative
        if (counter > 0)
        {
             // decrement nodes counter
             counter--;
        }
    }

    Node ReadFirst (void)
    {
        if (first != nullptr)
        {
            return *first;
        }
        else
        {
            std::cout << " Error, you can't read first node from an empty list" << std::endl;

            Node temp = {0,nullptr};
            return temp;
        }
    }

    Node ReadLast (void)
    {
        if(last != nullptr)
        {
            return *last;
        }
        else
        {
            std::cout << "Error, you can't real last mnode from an empty list" << std::endl;

            Node temp = {0,nullptr};
            return temp;
        }
    }

    Node ReadIndex (int index)
    {
        if (index <= 1)
        {
            return ReadFirst();
        }

        if (index >= counter)
        {
            return ReadLast();
        }

        if (index < 1 || index > counter || first == nullptr)
        {
            std::cout << "Error: Index out of range!" << std::endl;
            Node temp = {0,nullptr};
            return temp;
        }

        Node* temp;

        temp = first;

        // Traverse to the node at the given index
        for (int i =1; i < index; i++)
        {
            temp = temp->Next;

        }

        return *temp;
    }

    int GetNodesCounter (void)
    {
        return counter;
    }

    void PrintList(Node* head) 
    {
        while (head) 
        {
            std::cout << head->data << " -> ";

            head = head->Next;
        }
        std::cout << "nullptr\n";
    }

    // Display the linked list
    void Display() 
    {
        if (first == NULL) {
            std::cout << "List is empty.\n";
            return;
        }
        Node* temp = first;
        while (temp != NULL) 
        {
            std::cout << temp->data << " -> ";
            temp = temp->Next;
        }
        std::cout << "NULL\n";
    }

};

int main ()
{
    /* Example When you are passing an existing node (already allocated elsewhere).*/
    Node* FirstNode = new Node{50, nullptr};
    Node* LastNode = new Node{100, nullptr};
    Node* Node2 = new Node{70, nullptr};
    Node* Node3 = new Node{80, nullptr};
    LinkedList list;
    list.InsertFirst(FirstNode);
    //list.PrintList(FirstNode);
    list.InsertLast(LastNode);
    list.InsertIndex(2,Node2);
    list.InsertIndex(3,Node3);
    list.DeleteFirst();
    list.DeleteLast();
    list.DeleteIndex(2);
    list.Display();
    std::cout << "first " << list.ReadFirst().data << std::endl;
    std::cout << "Node " << list.ReadIndex(3).data << std::endl;
    

    /* When you want the function to create a new node internally using new.*/

    // LinkedList list;
    // list.InsertFirst(10);
    // list.InsertFirst(20);
    // list.InsertFirst(30);

    return 0;
}
