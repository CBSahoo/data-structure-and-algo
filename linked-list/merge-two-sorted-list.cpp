ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode *head = NULL, *temp = head, *traverse = head;

	while(list1 != NULL && list2 != NULL) {
		if(list1->val <= list2->val) {
			temp = list1;
			list1 = list1->next;
		} else {
			temp = list2;
			list2 = list2->next;
		}

		temp->next = NULL;

		if(head == NULL) {
			head = temp;
		} else {
			traverse->next = temp;
		}

		traverse = temp;
	}

	while(list1 != NULL) {
		temp = list1;
		list1 = list1->next;

		temp->next = NULL;

		if(head == NULL) {
			head = temp;
		} else {
			traverse->next = temp;
		}
		traverse = temp;
	}

	 while(list2 != NULL) {
		temp = list2;
		list2 = list2->next;

		temp->next = NULL;

		if(head == NULL) {
			head = temp;
		} else {
			traverse->next = temp;
		}
		traverse = temp;
	}

	return head;
}