ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode *dummy = new ListNode(0, head);
	ListNode *currNode = dummy, *nextNode = dummy, *prevNode = dummy;
	int count = -1;

	while(currNode) {
		count++;
		currNode = currNode->next;
	}   

	while(count >= k) {
		currNode = prevNode->next;
		nextNode = currNode->next;

		for(int i = 1; i < k; i++) {
			currNode->next = nextNode->next;
			nextNode->next = prevNode->next;
			prevNode->next = nextNode;
			nextNode = currNode->next;
		}

		prevNode = currNode;
		count -= k;
	}

	return dummy->next;

}