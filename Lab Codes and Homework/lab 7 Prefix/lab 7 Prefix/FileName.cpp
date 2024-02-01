#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;
/*

bool delimitersOk(const string& expression) {
    stack<char> str;
 
    

    for (int i = 0; i <expression.length() ; i++)
    {
        
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            str.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {

            if (str.empty()) {
                return false;
            }

            char openDelimiter = str.top();
            str.pop();


            if ((expression[i] == ')' && openDelimiter != '(') || (expression[i] == ']' && openDelimiter != '[') || (expression[i] == '}' && openDelimiter != '{'))
            {
                return false;
            }
        }
    

    }
    return str.empty();
}

int main() {

    ifstream inputFile("input.txt",ios::binary);

    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int size;
    inputFile >> size;
    

    for (int i = 0; i < size; ++i) {
        string exp;

        getline(inputFile, exp);

        
        bool check = delimitersOk(exp);

        if (check) {
            cout << "Valid" << endl;
        }
        else {
            cout << "Invalid" << endl;
        }
    }

    inputFile.close();
    return 0;
}

*/


void test(int n)
{
    if (n > 1)
        test(n - 1);
    cout << n;
    
}

int sum(int n)
{
    if (n <= 0)
        return 1;
    return sum(n - 1) + n;

}
int main()
{
    sum(4);
}



































































































































