void reorderList(ListNode* head) {
	ListNode *slow = head, *fast = head->next;        

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode *temp1 = slow->next;
	slow->next = NULL;

	ListNode *forward = NULL, *prev = NULL, *curr = temp1;

	while(curr) {
		forward = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forward;
	}

	temp1 = prev;

	while(temp1) {
		ListNode *temp2 = head->next, *temp3 = temp1->next;

		head->next = temp1;
		temp1->next = temp2;
		head = temp2;
		temp1 = temp3;
	}
}