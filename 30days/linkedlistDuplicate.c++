Node* removeDuplicates(Node *head)
{
    Node *ptr, *dup;
    bool flag = false;

    ptr = head;

    while (ptr != NULL && ptr->next != NULL) {
        while (!flag) {
            if (ptr->data == ptr->next->data) {
                dup = ptr->next;              // ptr->next is a duplicate with ptr
                ptr->next = ptr->next->next;  // set ptr->next to next, next node
                delete(dup);                  // delete dup
            }
            if ((ptr->next == NULL) || (ptr->data != ptr->next->data))
                flag = true;
        }
        ptr = ptr->next;
        flag = false;
    }
    return head;
}
