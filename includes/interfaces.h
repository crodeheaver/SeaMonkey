struct Node {
	virtual string tokenLiteral() = 0;
}

struct Statement : Node {
	virtual void statementLiteral() = 0;
}

struct Expression : Node {
	virtual void expressionNode() = 0;
}