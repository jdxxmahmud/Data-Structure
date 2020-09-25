#include<stdio.h>
#include<stdlib.h>

void print();
void append(int my_roll);
void insert_node(int my_roll, int given_roll);
void search_node(int my_roll);
void delete_node(int my_roll);
struct node
{
    int roll;
    node *next;   /// This will contain the memory address of the next node
};

node *root = NULL;   /// This initialize the linked list. When this is empty.

void append(int my_roll)
{
    if(root==NULL)     /// First Case: If the list is empty
    {
        root = new node();
        root->roll = my_roll;    /// "->" this is used when we use pointers in structure.
        root->next = NULL; /// Because this will be the new tail.

        /// You have to define all the values of a node. That means roll and next.
    }
    else              /// Second Case: When the list is not empty
    {
        /// Here there will be elements. So I have to find the last element to append
            /// the new element after it.

        /// I will need the address of the root. So I will not use it(root)
            /// to find the last node.
        /// So I will create another node to find the last node.


        node *current_node = root; /// Make a copy of root node


        while(current_node->next != NULL)   /// The logic of finding the last node
        {
            current_node = current_node->next;  /// Go to the next address
        }

        /// When the loop breaks, it will be the last node, or tail.


        /// Now I have two things to do
            /// 1. Make a new node
            /// 2. Connect the new_node with the previous current_node(last node)


        node *new_node = new node();   /// 1. Create a new_node
        new_node->roll = my_roll;
        new_node->next = NULL;    /// This will be the new tail.

        current_node->next = new_node; /// List the last node with new_node


}
}

void insert_node(int my_roll, int given_roll)
{

    printf("\n\nTrying to insert %d after %d\n", my_roll, given_roll);
    node *current_node = root;

    while(current_node->roll != given_roll)   /// Going to the target node for insertion after it.
    {

        if(current_node->next == NULL)   /// I have reached the last node and not found the value.
        {
            printf("\nThe value %d has not been found. So insertion is not possible", given_roll);
            return;
        }


        current_node = current_node->next;
    }

    node *new_node = new node();
    new_node->roll = my_roll;

    new_node->next = current_node->next;    /// Linking the next element with new_node
    current_node->next = new_node;          /// Linking new_node with current_node


    printf("\nInserting %d after %d", my_roll, given_roll);
    printf("\nNew link list after insertion of %d", my_roll);
    print();
}

void search_node(int my_roll)
{

    node *current_node = root;

    int my_roll_index = 1;

    while(current_node->roll != my_roll)
    {
        if(current_node->next == NULL)   /// I have reached the last node and not found the value.
        {
            printf("The value %d has not been found\n\n\n\n", my_roll);
            return;
        }

        my_roll_index++ ;
        current_node = current_node->next;    /// Go to the next node if not found
    }

    printf("\nThe value %d has been found at position %d\n\n\n", my_roll, my_roll_index);


}


void delete_node(int my_roll)
{

    printf("\nDeleting %d from the linked list", my_roll);

    node *current_node = root;   /// Copying the root address
    node *previous_node = NULL;   /// As root does not have any previous node, so we initialize it as NULL

    while(current_node->roll != my_roll)  /// Searching the node by roll.
    {
        previous_node = current_node;    /// Moving the previous node as well as the current node
        current_node = current_node->next;
    }

    if(current_node == root)  ///   The required value is in the root node.
    {
        node *temp = root;      /// Store root address in the temporary variable
        root = root->next;      /// Shift root to the immediate next node
        delete(temp);     /// free the memory
    }
    else   /// If the node is note root
    {
        previous_node->next = current_node->next;    /// Link the previous node and the next node of the target node.
        delete(current_node);     /// Free the memory
    }

    printf("\n\nThe new list after deletion: \n");
    print();


    printf("Successfully deleted %d from the list", my_roll);
}


void print()
{
    if(root == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    node *current_node = root;  /// This line will be common for almost all the operations

    printf("\nThe elements of the list are: \n");

    while(current_node!= NULL) /// Loop until you reach NULL
    {
        printf("%d\n", current_node->roll,current_node->roll);
        current_node = current_node->next;
    }
}

int main()
{
    append(1);    /// Complexity O(n)
    append(3);
    append(5);
    append(7);
    append(8);
    print();     /// Complexity O(n)


    delete_node(5);     /// Complexity O()

    insert_node(6, 5);    /// Complexity O(n)



  ///  search_node(8);     /// Complexity O(n)




    return 0;
}
