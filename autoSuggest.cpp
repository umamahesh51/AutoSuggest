#include<iostream>
void autoSuggest(Trie* root,char* prefix)
{   
    int i;
    char w[100];
    for(int i=0;prefix[i]!=0;i++)
    {
    	if(root->next[prefix[i]-'a']!=NULL)
    	  {
    	  	root=root->next[prefix[i]-'a'];
		  }
		  else
		  {   
		     cout<<"no words with the prefix "<<prefix;
		     return;
	    }
	}
	for(i=0;prefix[i]!='\0';i++)
	      w[i]=prefix[i];
	    w[i]='\0';
	   printHelper(root,w,i);// prints all possible words with given prefix
}
