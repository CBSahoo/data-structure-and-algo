ListNode* mergeKLists(vector<ListNode*>& lists) {
	if(lists.empty()) 
		return NULL;

	return mergerKListsHelper(lists, 0, lists.size() - 1);
	
}

ListNode* mergerKListsHelper(vector<ListNode*>& lists, int start, int end) {
	if(start == end) {
		return lists[start];
	}

	if(start + 1 == end) {
		return merge(lists[start], lists[end]);
	}

	int mid = start + (end - start)/2;
	ListNode *left = mergerKListsHelper(lists, start, mid);
	ListNode *right = mergerKListsHelper(lists, mid + 1, end);

	return merge(left, right);
}

ListNode* merge(ListNode* list1, ListNode* list2) {
	ListNode* dummy = new ListNode(-1);
	ListNode* head = dummy;

	while(list1 != NULL && list2 != NULL) {

		if(list1->val <= list2->val) {
			head->next = list1;
			list1 = list1->next;
		} else {
			head->next = list2;
			list2 = list2->next;
		}

		head = head->next;
	}

	if(list1 != NULL) head->next = list1;
	if(list2 != NULL) head->next = list2;

	return dummy->next;
}