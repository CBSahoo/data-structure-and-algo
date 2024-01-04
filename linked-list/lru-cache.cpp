class LRUCache {
	public:
		class Node  {
			public:
				int key;
				int val;
				Node *prev, *next;

				Node(int key, int val) {
					this->key = key;
					this->val = val;
				}
		};

		Node *head = new Node(-1, -1);
		Node *tail = new Node(-1, -1);

		int lruCap;
		map<int, Node*> mp;

		LRUCache(int capacity) {
			lruCap = capacity;
			head->next = tail;
			tail->prev = head;
		}

		void insertNode(Node *root) {
			Node *temp = head->next;

			root->next = temp;
			root->prev = head;

			head->next = root;
			temp->prev = root;
		}

		void deleteNode(Node *root) {
			Node *prevNode = root->prev;
			Node *nextNode = root->next;

			prevNode->next = nextNode;
			nextNode->prev = prevNode;
		}

		int get(int key) {
			
			if(mp.find(key) != mp.end()) {
				Node *temp = mp[key];
				int ans = temp->val;

				mp.erase(key);
				deleteNode(temp);
				insertNode(temp);

				mp[key] = head->next;
				return ans;
			}

			return -1;
		}

		void put(int key, int value) {
			if(mp.find(key) != mp.end()) {
				Node *temp = mp[key];
				mp.erase(key);
				deleteNode(temp);
			}

			if(mp.size() == lruCap) {
				mp.erase(tail->prev->key);
				deleteNode(tail->prev);
			}

			insertNode(new Node(key, value));
			mp[key] = head->next;
		}
};