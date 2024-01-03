ListNode* removeNthFromEnd(ListNode* head, int n) {

	if(head == NULL) return NULL;

	
	ListNode* newNode = new ListNode(-1);
	newNode->next = head;

	ListNode *left = newNode, *right = newNode;

	for(int i = 0; i < n; i++) {
		right = right->next;
	}

	while (right->next) 
	{
		right = right->next;
		left = left->next;
	}

	ListNode *deletedNode = left->next;
	left->next = left->next->next;
	
	delete deletedNode;

	return newNode->next;
}