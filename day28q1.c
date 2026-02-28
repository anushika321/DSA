int intersectPoint(struct Node* head1, struct Node* head2)
{
    if (head1 == NULL || head2 == NULL)
        return -1;

    int len1 = 0, len2 = 0;
    struct Node *temp1 = head1, *temp2 = head2;

    // Find length of first list
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }

    // Find length of second list
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    temp1 = head1;
    temp2 = head2;

    // Move pointer of longer list ahead
    int diff = (len1 > len2) ? (len1 - len2) : (len2 - len1);

    if (len1 > len2) {
        while (diff--)
            temp1 = temp1->next;
    } else {
        while (diff--)
            temp2 = temp2->next;
    }

    // Move both pointers together
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2)   // compare addresses
            return temp1->data;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return -1;  // No intersection
}
