//checking valid string which contains only (){}[]
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

struct node{
	char data;
	struct node *link;
}*top=NULL,*newnode,*temp;

void create_node(char element){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=element;
	newnode->link=NULL;
}
void push(char element){
	create_node(element);
	if(top==NULL)
		top=newnode;
	else{
		newnode->link=top;
		top=newnode;
	}
}
char pop(){
	char res='#';
	if(top==NULL)
		return res;
	else{
		temp=top;
		top=top->link;
		res = temp->data;
		free(temp);
		return res;
	}
}

int isValidInput(char string[]){
	int i=0,valid=0;
	for(i=0;i<strlen(string)-1;i++)
	 if(string[i]=='('||string[i]==')'||
	 	string[i]=='{'||string[i]=='}'||
	 	string[i]=='['||string[i]==']')
	 		valid=1;
	return valid;
}

int isMatchingPair(char c1, char c2){
	if(c1=='('&&c2==')')
		return 1;
	if(c1=='{'&&c2=='}')
		return 1;
	if(c1=='['&&c2==']')
		return 1;
	return 0;
}

int evaluate(char string[]){
	int i=0;
	char ch,x;
	for(i=0;i<strlen(string);i++){
		ch=string[i];
		if(ch=='('||ch=='{'||ch=='[')
			push(ch);
		else if(ch==')'||ch=='}'||ch==']')
			if(top==NULL)
				return 0;
			else if(!isMatchingPair((x=pop()),ch))
				return 0;
	}
	if(top==NULL)
		return 1;
	return 0;
}

int main(){
	
	int i=0;
	char string[MAX];
	printf("Enter string: ");
	fgets(string,MAX,stdin);
	
	if(!isValidInput(string))
		printf("Invalid Input\n");
	else
		if(evaluate(string))
 			printf("true\n");
 		else
 			printf("false\n");

	return 0;
}
