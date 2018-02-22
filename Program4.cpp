//David Wallace
//2/22/2018
#include<iostream>
#include<sstream>
#include<string>
#include "Stack.h"
#include "Queue.h"
using namespace std;

//method declarations
double calculateExpression(string);
bool isLowerPriority(char, char);

int main (){
	
	//static variables
	char repeat = 'y';
	double result;
	
	string infixString;
	string postFixString;
	
	Stack<char> stack;
	Queue<char> infixQ;
	Queue<char> postFixQ;
	
	cout<<"\nInfix to Postfix Converter"<<endl;

	while(repeat=='y' || repeat =='Y'){
		
		cout<<"\nPlease input infix"<<endl;
		
		getline(cin,infixString);
		
		//clear white spaces complete implemented as a q
		
		for(int i =0; i<=infixString.length();i++){
			if(infixString[i]== ' '){
			}
			else{
			
				infixQ.push_back(infixString[i]);
				
			}
		}
			
			//start of algorithm
		while(!infixQ.isEmpty()){
			
			char token = infixQ.pop_front();
			if(token == '(' ){stack.push(token);}
			
			else if (token== ')'){
				while(stack.peek()!= '('){
					postFixQ.push_back(stack.pop());
					
				}
				stack.pop();
				
			}
			else if(token =='+'||token=='-'||token=='*'||token=='/'){
				while((!stack.isEmpty()) && (isLowerPriority(token,stack.peek())== true ))
				{
					postFixQ.push_back(stack.pop());	
				}
				stack.push(token);
			}
			else{
				postFixQ.push_back(token);
				
			}
			
			
		}
		
		while(!stack.isEmpty())
		{
			postFixQ.push_back(stack.pop());
			
		}
	
	
	cout<<"\n\n\nInfix expression: ";
	cout<<infixString<<endl;
		
	
	
	cout<<"Postfix expression: ";
	postFixQ.display();
	
	while(!postFixQ.isEmpty()){
		
		char holder= postFixQ.pop_front();//holder holds top of postFixQ while loop removes null terminator'\0'
		if(holder!='\0'){
			postFixString+=holder;
		}
	}
	
	result = calculateExpression(postFixString);
	cout<<"Result of the expression: "<<result<<endl<<endl;
		
		
	cout<<"Would you like to run the program again?(Y/N)";
	cin>>repeat;		
	cout<<endl<<endl;
	cin.ignore();//removes \n for next iteration using getline
		
	}
	cout<<"\nGoodbye";
}
	

	
bool isLowerPriority(char first,char second){
	
	if(second ==')'){return true;}
	if(second == '('){return false;}
	if((first =='+'||first =='-')&&(second =='+' ||second=='-')){return true;}
	if((first =='*'||first =='/')&&(second =='*' ||second=='/')){return true;}
	if((first =='+'||first =='-')&&(second =='*' ||second=='/')){return true;}
	if((first =='*'||first =='/')&&(second =='+' ||second=='-')){return false;}
}

double calculateExpression(string postFixString){
	
	double result;
	double operand1;
	double operand2;
	double temp;
	
	Stack <double>stack; 	
	
	for(int i = 0; i<postFixString.length();i++){
		
		if(postFixString[i]!='+'&&postFixString[i]!='-'&&postFixString[i]!='*'&&postFixString[i]!='/')
		{
			
			temp = static_cast<double>(postFixString[i]);
			temp = temp-48;
			stack.push(temp);
			
		}
		else{
			
			operand2 = stack.pop();
			operand1 = stack.pop();
			
			if(postFixString[i]=='+'){
				result = operand1+operand2;
			}
			else if(postFixString[i]=='-'){
				result = operand1 - operand2;	
			}
			else if(postFixString[i]=='*'){
					result = operand1*operand2;
			}
			else{
					result = operand1/operand2;
			}
		stack.push(result);
		}
	}
	return result;
		
}
	
	
