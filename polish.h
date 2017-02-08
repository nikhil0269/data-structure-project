
#define MAXPOL 20

int toppol;
char infixpol[MAXPOL];
char postfixpol[MAXPOL];
long int stackpol[MAXPOL];
//  prototypes
void infixpol_to_postfixpol();
void pushpol(char ch);
char poppol();
int priority_in(char);
int priority_stackpol(char);
void show_postfixpol();
long int evaluation_post();
long int pow(long int a,long int b)
{
long int temp=1;
int i;
for(i=0;i<b;i++)
temp=temp*a;
return temp;
}
void mainpolish()                                  // main function is here
{
	toppol=-1;
	printf("Enter a infixpol expression\n");
	scanf("%s",infixpol);
	infixpol_to_postfixpol();
	show_postfixpol();
        printf("\nThe value of postfixpol expression is=%ld",evaluation_post()); 
}

long int evaluation_post()
{
int i;
char ch;
long int a,b,temp,result;
for(i=0;i<strlen(postfixpol);i++)
{
ch=postfixpol[i];
if(ch>='0'&&ch<='9')
pushpol(ch-'0');
else
{
a=poppol();
b=poppol();
switch(ch)
{
case '+':
temp=a+b;
break;
case '-':
temp=b-a;
break;
case '*':
temp=b*a;
break;
case '/':
temp=b/a;
break;
case '^':
temp=pow(b,a);
break;
case '%':
temp=b%a;
break;
}
pushpol(temp);
}
}
result=poppol();
return result;
}
void show_postfixpol()
{
	int i;
	for(i=0;i<strlen(postfixpol);i++)
	{
		printf("%c",postfixpol[i]);
	}
}
int priority_in(char ch)
{
	switch(ch){

case '+':
case'-':
return 1;
break;
case '(':
return 0;
break;
case '*':
case '/':
case '%':
return 2;
break;
case '^':
return 3;
break;
default:
return 0;
}
}

int priority_stackpol(char ch)
{
        switch(ch){

case '+':
case'-':
return 1;
break;
case '(':
return 0;
break;
case '*':
case '/':
case '%':
return 2;
break;
case '^':
return 4;
break;
default:
return 0;
}
}
void pushpol(char ch)
{
	if(toppol>=MAXPOL-1)
	{
		printf("stackpol overflow\n");
		exit(0);
	}
	else
		stackpol[++toppol]=ch;

}

char poppol()
{
	char val;
	if(toppol==-1)
	{
		printf("stackpol underflow\n");
		exit(0);
	}
	else
		val=stackpol[toppol--];
	return val;
}

void infixpol_to_postfixpol()
{
	char ch,val;
	int i,p=0;
	for(i=0;i<strlen(infixpol);i++)
	{
		ch=infixpol[i];
		switch(ch)
		{
			case '(':
				pushpol(ch);
				break;
			case ')':
				while(1)
                                 {
                                    val=poppol();
                                    if(val!='(')
					postfixpol[p++]=val;
                                 else break; } 
					break;
					case '+':
					case '-':
					case'*':
					case'/':
					case'^':
					case '%':
					while((toppol!=-1)&&priority_stackpol(stackpol[toppol])>=priority_in(ch))
					{
						val=poppol();
						postfixpol[p++]=val;
					

					}
						pushpol(ch);
				
				break;
			default:
				postfixpol[p++]=ch;
		}
	}
          while(toppol!=-1)
{

val=poppol();
postfixpol[p++]=val;
}
}
