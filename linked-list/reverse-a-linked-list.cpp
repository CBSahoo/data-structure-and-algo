ListNode* reverseList(ListNode* head) {
	ListNode *nextNode = NULL, *prevNode = NULL;

	while(head) {
		nextNode = head->next;
		head->next = prevNode;
		prevNode = head;
		head = nextNode;
	}

	head = prevNode;
	return head;
}