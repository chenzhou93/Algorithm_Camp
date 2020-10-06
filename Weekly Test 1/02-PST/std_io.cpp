#include <iostream>
#include <stack>
using namespace std;

// 代码实现开始

stack<string> opStack;
stack<string> numStack;

bool comparePriority(string op1, string op2){
    bool res = true;
    if((op1 == "+" || op1 == "-") && (op2 == "+" || op2 == "-")){
        res = true;
    }

    if((op1 == "+" || op1 == "-") && (op2 == "*" || op2 == "/")){
        res = false;
    }

    if((op1 == "*" || op1 == "/") && (op2 == "+" || op2 == "-")){
        res = true;
    }

    if((op1 == "*" || op1 == "/") && (op2 == "*" || op2 == "/")){
        res = true;
    }
    return res;

}

// expr：算术表达式
// 返回值：加上括号后的表达式
string solve(string expr) {
    string res = "";
    for(int i=0; i<expr.length(); i++){
        string s(1, expr[i]);
        string exp = s;
        
        if(expr[i] >= '0' && expr[i] <= '9' && i<expr.length()-1){
            numStack.push(exp);
        }else{
            if(i==expr.length()-1){
                numStack.push(exp);
            }
            string tmp;
            while(!opStack.empty()){
                string operator2 = opStack.top();
                if(comparePriority(operator2, exp)){//算前面的
                    string num1 = numStack.top();
                    numStack.pop();
                    string num2 = numStack.top();
                    numStack.pop();
                    tmp = "("+ num2 + operator2 + num1 + ")";
                    opStack.pop();
                    numStack.push(tmp);
                }else{
                    break;
                }
            }
            opStack.push(exp);
        }
    }

    // while(!opStack.empty()){
    //     string tmp;
    //     string operator2 = opStack.top();
    //     string num1 = numStack.top();
    //     numStack.pop();
    //     string num2 = numStack.top();
    //     numStack.pop();
    //     tmp = "("+ num2 + operator2 + num1 + ")";
    //     opStack.pop();
    //     numStack.push(tmp);
    // }

    res = numStack.top();
        
    return res;
}

// 代码实现结束

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << solve(s) << '\n';
    return 0;
}

