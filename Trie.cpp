#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct Trie
{
	bool eow;
	struct Trie* next[26];
};
Trie* createNode()
{
	Trie* t=(Trie*)malloc(sizeof(Trie));
	t->eow=false;
	for(int i=0;i<26;i++)
	   t->next[i]=NULL;
	   return t;
}
bool insertWord(Trie* root,char *w)
{
	for(int i=0 ; w[i]!='\0' ; i++)
	{
		int idx=w[i]-'a';
		if(root->next[idx]==NULL)
		 {
		 	root->next[idx]=createNode();
		 }
		 root=root->next[idx];
	}
		if(root->eow==true)
		return false;
	    	root->eow=true;
		return true;
}
bool checkWord(Trie* root,char* w)
{
	for(int i=0;w[i]!=0 ; i++)
	{
		int idx=w[i]-'a';
		if(root->next[idx]==NULL)
		  return false;
		  root=root->next[idx];
	}
		if(root->eow)
		 return true;
		 return false;
}
void printHelper(Trie* root,char* w,int j)
{      
       if(root==NULL)
          return; 
       if(root->eow)
		  {
		  	cout<<w<<endl;   
		  }
    	for(int i=0;i<26;i++) // it is used to check all words with in a given node
    	{
		  	if(root->next[i]!=NULL)
		  	{
		  	  w[j]=i+'a';
		  	  w[j+1]='\0';
			  printHelper(root->next[i],w,j+1);		
	     	}
    	}
}
void printAllWords(Trie* root)
{  
    char word[100];
	printHelper(root,word,0) ;
}
int main()
{
	Trie* root;
	root=createNode();
	char a[1000];
	char c[]="um";
    do
    {
        cout<<"enter a word to insert , Enter N to stop inserting";
         cin>>a;
    	  if(a[0]=='N')
    	  break;
          if(insertWord(root,a))
	      cout<<"inserted "<<a<<endl;	 
	      else
	      cout<<"already there in trie\n";	 
	}while(1);
	 do
    {
    	cout<<"enter a word to check Enter N to stop inserting";
    	cin>>a;
    	 if(a[0]=='N')
    	  break;
      if(checkWord(root,a))
          cout<<"found "<<a<<endl;
      else 
	      cout<<"Not found \n" ;   
	}while(1);
	//printAllWords(root);
	autoSuggest(root,c);
	return 0;
}
