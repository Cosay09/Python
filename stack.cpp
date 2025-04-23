#include <iostream>
#include <cctype>
using namespace std;

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return '\0'; // safer than -1 for char
    return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {
    char exp[100];
    char *e, x;

    cout << "Enter the expression: ";
    cin >> exp;

    e = exp;

    while (*e != '\0') {
        if (isalnum(*e)) {
            cout << *e;
        }
        else if (*e == '(') {
            push(*e);
        }
        else if (*e == ')') {
            while ((x = pop()) != '(') {
                cout << x;
            }
        }
        else {
            while (priority(stack[top]) >= priority(*e)) {
                cout << pop();
            }
            push(*e);
        }
        e++;
    }

    while (top >= 0) {
        cout << pop();
    }

    cout << endl;
    return 0;
}

/*
#include <iostream>
using namespace std;

int ack(int m, int n)
{
    if (m == 0)
        return n+1;
    else if (m > 0 && n == 0)
        return ack(m-1, 1);
    else if (m > 0 && n > 0)
        return ack(m-1, ack(m, n - 1));
}

int main()
{
    int m, n; 
    cin >> m >> n;

    cout << ack(m, n);

    return 0;
}
*/
