int evalRPN(vector<string>& tokens) {
	stack<int> st;
	int n = tokens.size();

	for(int i = 0; i < n; i++) {
		if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
			int a = st.top();
			st.pop();

			int b = st.top();
			st.pop();

			if(tokens[i] == "+") st.push(b + a);
			if(tokens[i] == "-") st.push(b - a);
			if(tokens[i] == "*") st.push(b * a);
			if(tokens[i] == "/") st.push(b / a);

		} else {
			st.push(stoi(tokens[i]));
		}
	}

	return st.top();
}