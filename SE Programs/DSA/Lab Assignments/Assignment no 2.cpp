#include<iostream>
#include<cmath>
#include<stack>
#include <bits/stdc++.h>
#include<string.h>

using namespace std; 

float scanNum(char ch) 
{
   int value;
   value = ch;
   return float(value-'0');   //return float from character
}

bool isOperator(char c) 
{ 
    return (!isalpha(c) && !isdigit(c)); 
}

bool is_Operand(char c) 
{ 
    return isdigit(c); 
} 

//Function to return precedence of operators
int prec(char c) 
{ 
	if(c == '^') 
	return 3; 
	else if(c == '*' || c == '/') 
	return 2; 
	else if(c == '+' || c == '-') 
	return 1; 
	else
	return -1; 
} 

// The main function to convert infix expression to postfix expression 
void infixToPostfix(string s) 
{ 
	stack<char> st; 
	st.push('N'); 
	int l = s.length(); 
	string ns; 
	for(int i = 0; i < l; i++) 
	{ 
		// If the scanned character is an operand, add it to output string. 
		if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
		{
		    ns+=s[i]; 
		}

		// If the scanned character is an ‘(‘, push it to the stack. 
		else if(s[i] == '(')
		{
		    st.push('(');
		}
		
		// If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered. 
		else if(s[i] == ')') 
		{ 
			while(st.top() != 'N' && st.top() != '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			    ns += c; 
			}
			
			if(st.top() == '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			} 
		} 
		
		//If an operator is scanned 
		else
		{ 
			while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
			{ 
				char c = st.top(); 
				st.pop(); 
				ns += c; 
			} 
			st.push(s[i]); 
		} 

	} 
	//Pop all the remaining elements from the stack 
	while(st.top() != 'N') 
	{ 
		char c = st.top(); 
		st.pop(); 
		ns += c; 
	} 
	
	cout<<ns<<endl; 

} 

string inToPost(string infix) 
{ 
    infix = '(' + infix + ')'; 
    int l = infix.size(); 
    stack<char> char_stack; 
    string output; 
  
    for (int i = 0; i < l; i++) { 
  
        // If the scanned character is an operand, add it to output. 
        if (isalpha(infix[i]) || isdigit(infix[i])) 
            output += infix[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if (infix[i] == '(') 
            char_stack.push('('); 
  
        // If the scanned character is an ‘)’, pop and output from the stack  
        // until an ‘(‘ is encountered. 
        else if (infix[i] == ')') { 
  
            while (char_stack.top() != '(') { 
                output += char_stack.top(); 
                char_stack.pop(); 
            } 
  
            // Remove '(' from the stack 
            char_stack.pop();  
        } 
  
        // Operator found  
        else { 
              
            if (isOperator(char_stack.top())) { 
                while (prec(infix[i]) 
                   <= prec(char_stack.top())) { 
                    output += char_stack.top(); 
                    char_stack.pop(); 
                } 
  
                // Push current Operator on stack 
                char_stack.push(infix[i]); 
            } 
        } 
    } 
    return output; 
} 

string infixToPrefix(string infix) 
{ 
    /* Reverse String 
     * Replace ( with ) and vice versa 
     * Get Postfix 
     * Reverse Postfix  *  */
    int l = infix.size(); 
  
    // Reverse infix 
    reverse(infix.begin(), infix.end()); 
  
    // Replace ( with ) and vice versa 
    for (int i = 0; i < l; i++) 
    { 
  
        if (infix[i] == '(') 
        { 
            infix[i] = ')'; 
            i++; 
        } 
        else if (infix[i] == ')') 
        { 
            infix[i] = '('; 
            i++; 
        } 
    } 
  
    string prefix = inToPost(infix); 
  
    // Reverse postfix 
    reverse(prefix.begin(), prefix.end()); 
  
    return prefix; 
} 

int isOperand(char ch) 
{
   if(ch >= '0' && ch <= '9')
      return 1;   //character is an operand
   return -1;   //not an operand
}

float operation(int a, int b, char op) 
{
   //Perform operation
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a);
   else
      return -1;
}

float postfixEval(string s) {
   int a, b;
   stack<float> stc;
   string::iterator it;
   for(it=s.begin(); it!=s.end(); it++) 
   {
      //read elements and perform postfix evaluation
      if(prec(*it) != -1) 
      {
         a = stc.top();
         stc.pop();
         b = stc.top();
         stc.pop();
         stc.push(operation(a, b, *it));
      }
      else if(isOperand(*it) > 0) 
      {
         stc.push(scanNum(*it));
      }
   }
   return stc.top();
}

double evaluatePrefix(string exprsn) 
{ 
    stack<double> Stack; 
  
    for (int j = exprsn.size() - 1; j >= 0; j--) { 
  
        // Push operand to Stack 
        // To convert exprsn[j] to digit subtract 
        // '0' from exprsn[j]. 
        if (is_Operand(exprsn[j])) 
            Stack.push(exprsn[j] - '0'); 
  
        else { 
  
            // Operator encountered 
            // Pop two elements from Stack 
            double o1 = Stack.top(); 
            Stack.pop(); 
            double o2 = Stack.top(); 
            Stack.pop(); 
  
            // Use switch case to operate on o1 
            // and o2 and perform o1 O o2. 
            switch (exprsn[j]) { 
            case '+': 
                Stack.push(o1 + o2); 
                break; 
            case '-': 
                Stack.push(o1 - o2); 
                break; 
            case '*': 
                Stack.push(o1 * o2); 
                break; 
            case '/': 
                Stack.push(o1 / o2); 
                break; 
            } 
        } 
    } 
  
    return Stack.top(); 
} 

//Driver program to test above functions 
int main() 
{ 
	string exp, post, pre;
	int choice;
	
	do
	{
	    cout<<"1.Infix to Postfix Conversion\n2.Infix to Prefix Conversion\n3.Postfix Expression Evaluation\n4.Prefix Expression Evaluation\n5.Exit"<<endl;
	
	    cout<<"Enter your choice: ";
	    cin>>choice;
	    
	    switch(choice)
	    {
	        case 1:
	        {
	            cout<<"Enter expression: ";
	            cin>>exp;
	            cout<<"Postfix Expression: ";
	            infixToPostfix(exp);
	            break;
	        }
	        
	        case 2:
	        {
	            cout<<"Enter expression: ";
	            cin>>exp;
	            cout<<"Prefix Expression: "<<infixToPrefix(exp)<<endl;
	            break;
	        }
	        
	        case 3:
	        {
	            cout<<"Enter postfix expression: ";
	            cin>>post;
	            cout<<"Answer is: "<<postfixEval(post)<<endl;
	            break;
	        }
	        
	        case 4:
	        {
	            cout<<"Enter prefix expression: ";
	            cin>>pre;
	            cout<<"Answer is: "<<evaluatePrefix(pre)<<endl;
	            break;
	        }
	        
	        case 5:
	        {
	            cout<<"Done!!"<<endl;
	            break;
	        }
	        
	        default:
	        {
	            cout<<"Wrong choice!!"<<endl;
	            break;
	        }
	    }
	}while(choice!=5);
	
	return 0; 
} 
