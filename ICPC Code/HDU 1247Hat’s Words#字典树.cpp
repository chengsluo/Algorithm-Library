#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int SIZE=26;
struct trie_node{
    bool isword;
    trie_node* ch[SIZE];
};
char s[50010][50];
trie_node*  create_trie()
{
    trie_node* pnode=new trie_node();
    pnode->isword=0;
    for(int i=0;i<SIZE;i++){
        pnode->ch[i]=NULL;
    }
    return pnode;
}
void trie_insert(trie_node *root,char *str)
{
    trie_node* node=root;
    char *p=str;
    while(*p){
        if(node->ch[*p-'a'] == NULL){
			node->ch[*p-'a'] = create_trie();
		}
		node = node->ch[*p-'a'];
		++p;
    }
    node->isword=1;
}
bool trie_search(trie_node* root,char *str)
{
    trie_node* node = root;
	char* p = str;
	while(*p && node!=NULL){
		node = node->ch[*p-'a'];
		++p;
	}
	if(node == NULL) return 0;
	else return node->isword;
}
int main()
{
    trie_node* root=create_trie();
    char str[50];
    int ct=0;
    while(scanf("%s",str)==1){
        strcpy(s[ct++],str);
        trie_insert(root,str);
    }
    for(int i=0;i<ct;i++){
        int len=strlen(s[i]);
        for(int j=1;j<len;j++){
            char t1[50]={'\0'};
            char t2[50]={'\0'};
            strncpy(t1,s[i],j);
            strncpy(t2,s[i]+j,len-j);
            if(trie_search(root,t1)&&trie_search(root,t2)){
                printf("%s\n",s[i]);
                break;
            }
        }
    }
    delete root;
    return 0;
}
