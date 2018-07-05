class Stack {
    char arr[100];
    int sze;
public:
    Stack() {
        sze = 0;
    }

    void push(char x) {
        arr[sze] = x;
        ++sze;
    }

    void pop() {
        if (sze == 0) return;
        --sze;
    }
    
    int size() {
        return sze;
    }
    
    bool empty() {
        return sze == 0;
    }

    char top() {
        if (empty()) return '\0';
        return arr[sze - 1];
    }
};