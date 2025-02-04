//Jacqueline Vermette
//Cop4530 2024


#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;
using namespace cop4530;
//all the helper functions

bool isOperator(const string& token);
bool isNumber(const string& token);
bool isVariable(const string& token);
bool isValidDouble(const string& str, double& result);
int getPrecedence(const string& g);


bool isAlpha(char c);
bool isDigit(char c);
bool isAlphaNum(char c);
bool convertInfixToPostfix(const string& infix, string& postfix);


double evaluatePostfix(const string& postfix, bool& success);


int main(){




    string line;

    cout << "Welcome to infix converter:" << endl;

    
do{

    cout << "Please enter infix expression (or type exit to stop): ";

    getline(cin, line);
        


if (line == "exit"){

break;
} 



if (!line.empty()){

    string postfix;


if (convertInfixToPostfix(line, postfix)){


    cout << "Postfix expression: " << postfix << endl;
                
    bool evaluationSuccess = false;

    double result = evaluatePostfix(postfix, evaluationSuccess);


                
    cout << "Postfix evaluation: ";
if (evaluationSuccess){

    cout << postfix << " = " << result << endl;
}
else{


    cout << postfix << " = " << postfix << endl;

    }
}
}
} 
while(true);
    


    return 0;
}




//1 million bool functions 
//Inspo sorta from assign 1
bool isAlpha(char c){

    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');

}


bool isDigit(char c){

    return c >= '0' && c <= '9';
}

bool isAlphaNum(char c){

    return isAlpha(c) || isDigit(c);

}


bool isValidDouble(const string& str, double& result){


if (str.empty()) return false;
    

size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;

bool hasDigits = false;

bool hasDecimal = false;
    
for (size_t i = start; i < str.length(); i++){

	if (isDigit(str[i])){

        hasDigits = true;

}
else if(str[i] == '.' && !hasDecimal){

	hasDecimal = true;
        
		
}
else{
    return false;


	}
}
    
if(!hasDigits) return false;


    
    //Used stringstream for conversion
    istringstream iss(str);
    iss >> result;
    
    return !iss.fail() && iss.eof();


}



bool convertInfixToPostfix(const string& infix, string& postfix){


Stack<string> operatorStack;
istringstream iss(infix);

string token;

bool lastWasOperand = false;

postfix = "";
    
while (iss >> token){

if(isNumber(token) || isVariable(token)){

    if(lastWasOperand){

cout << "Error: Missing operator between operands" << endl;

    return false;


}

	postfix += token + " ";

    lastWasOperand = true;


}else if(token == "("){

    operatorStack.push(token);

    lastWasOperand = false;

}else if(token == ")"){

if (!lastWasOperand){

    cout << "Invalid expression" << endl;


return false;

}
            

bool foundMatching = false;


while(!operatorStack.empty() && operatorStack.top() != "("){

    postfix += operatorStack.top() + " ";

    operatorStack.pop();
    foundMatching = true;

}
            

if (operatorStack.empty() || !foundMatching){

cout << "Invalid" << endl;

return false;

}
            
operatorStack.pop();

}else if(isOperator(token)){

    if(!lastWasOperand){

        cout << "Invalid expression" << endl;

        return false;
}
            
while(!operatorStack.empty() && operatorStack.top() != "(" && getPrecedence(operatorStack.top()) >= getPrecedence(token)){

    postfix += operatorStack.top() + " ";
    operatorStack.pop();

}
    operatorStack.push(token);
    lastWasOperand = false;


}else{


    cout << "Error: Invalid input:'" << token << "'" << endl;

    return false;


}
}
    
if(!lastWasOperand){

    cout << "Missing operand in postfix string. Unable to evaulate" << endl;


    return false;
}
    
while(!operatorStack.empty()){


if (operatorStack.top() == "("){

    cout << "Error: Mismatched parentheses" << endl;

    return false;

}

    postfix += operatorStack.top() + " ";
    operatorStack.pop();

}
    
if (!postfix.empty() && postfix[postfix.length()-1] == ' '){


        postfix = postfix.substr(0, postfix.length()-1);

}
    
    return true;
}

double evaluatePostfix(const string& postfix, bool& success){


    Stack<double> operandStack;

    istringstream iss(postfix);

    string token;
    success = true;
    

while (iss >> token){

    if (isNumber(token)){


    double value;


if (!isValidDouble(token, value)){

	success = false;
    return 0.0;


}

    operandStack.push(value);

}else if (isVariable(token)){


    success = false;
    return 0.0;
	

}else if(isOperator(token)){

    if (operandStack.size() < 2){
		cout << "Error: Invalid postfix expression - not enough operands" << endl;

            success = false;
            return 0.0;

}
            
    double operand2 = operandStack.top();

    operandStack.pop();

    double operand1 = operandStack.top();

    operandStack.pop();
            

if (token == "+") operandStack.push(operand1 + operand2);
else if (token == "-") operandStack.push(operand1 - operand2);

else if (token == "*") operandStack.push(operand1 * operand2);

else if (token == "/"){
    if (operand2 == 0){
        cout << "Error: Division by zero" << endl;
        success = false;
        return 0.0;


}
    operandStack.push(operand1 / operand2);
}
}
}
    
    if (operandStack.size() != 1){
	cout << "Invalid postfix expression, too many operands" << endl;

    success = false;
    return 0.0;

}
    
    return operandStack.top();
}

bool isOperator(const string& token){

    return token == "+" || token == "-" || token == "*" || token == "/";

}



bool isNumber(const string& token){

if (token.empty()){
	return false;
}; 

    double dummy;
    return isValidDouble(token, dummy);
}




bool isVariable(const string& token){


if (token.empty() || !isAlpha(token[0])){
	return false;
} 
    
    
for (char c : token){

    if (!isAlphaNum(c) && c != '_'){
		return false;
	} 

}
    

    return true;
}




int getPrecedence(const string& g){

if (g == "*" || g == "/") return 2;

if (g == "+" || g == "-") return 1;

    return 0;
}
