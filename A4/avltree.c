/*
Patrick Copp
1007602
Assignment 4
November 2018
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void addKey(char[20]);
void initialize();
void *newNode(char[20],int);
struct node* insertNode(struct node *root,int,char[20]);
void inorder(struct node *root);
struct node findKey(char[20]);
void Tree_postOrder(struct node *);
struct node removeKey(char [20]);
int avl_node_height(struct node *);
struct node *avl_balance_node(struct node *);
int avl_balance_factor(struct node *);
struct node *avl_rotate_leftleft(struct node *);
struct node *avl_rotate_leftright(struct node *);
struct node *avl_rotate_rightleft(struct node *);
struct node *avl_rotate_rightright(struct node *);\
void avl_balance(struct node **);
void free_tree(struct node *);

struct node
{
  char key[20];
  int count;
  struct node *left,*right;
};

int totalCount=0;
int keyCounterCount=0;
struct node keyCount[10000];

int main()
{
  int user=0;
  char toFind[20];
  char newKey[20];
  char toRemove[20];
  struct node found;
  int onefirst=0;
  int frequency;
  struct node *root=NULL;
  struct node **doubleroot=malloc(sizeof(struct node));

  while(user!=7)
  {
    printf("1. Initialization\n2. Find\n3. Insert\n4. Remove\n5. Check Height and Size\n6. Find All (above a given frequency)\n7. Exit\navl/> ");
    scanf("%d",&user);

    if(user==1)
    {
      initialize();
      root=insertNode(root,keyCount[0].count,keyCount[0].key);
      *doubleroot=root;
      for(int i=1;i<keyCounterCount;i++)
      {
        insertNode(root, keyCount[i].count, keyCount[i].key);
        *doubleroot=root;
        avl_balance(doubleroot);
        root=*doubleroot;
      }
      
      onefirst=1;

    }
    else if(onefirst==0)
    {
      printf("Initialize the AVL tree first.\n");
    }

    else if(user==2)
    {
      printf("find key: ");
      scanf("%s",toFind);
      found=findKey(toFind);
      if(strcmp(found.key,toFind)==0)
      {
        printf("key: %s, frequency: %d\n",found.key,found.count);
      }
      else
      {
        printf("no_such_key\n");
      }

    }

    else if(user==3)
    {
      printf("insert key: ");
      scanf("%s",newKey);
      addKey(newKey);
      found=findKey(newKey);
      if(found.count==1)
      {
        insertNode(root,1,newKey);
      }

      for(int i=0;i<keyCounterCount;i++)
      {
        *doubleroot=root;
        avl_balance(doubleroot);
        root=*doubleroot;
      }

    }

    else if(user==4)
    {
      printf("remove key: ");
      scanf("%s",toRemove);
      found=removeKey(toRemove);
      if(strcmp(found.key,toRemove)==0)
      {
        printf("key: %s, frequency: %d\n",found.key,found.count);
        totalCount--;
      }
      else
      {
        printf("no_such_key\n");
        continue;
      }
      root=NULL;
      root=insertNode(root,keyCount[0].count,keyCount[0].key);
      *doubleroot=root;
      for(int i=1;i<keyCounterCount;i++)
      {
        insertNode(root, keyCount[i].count, keyCount[i].key);
        *doubleroot=root;
        avl_balance(doubleroot);
        root=*doubleroot;
      }
    }

    else if(user==5)
    {
      printf("height: %d, size: %d, total count: %d\n",avl_node_height(root),keyCounterCount,totalCount);
    }

    else if(user==6)
    {
      printf("frequency: ");
      scanf("%d",&frequency);
      for(int i=0;i<keyCounterCount;i++)
      {
        if(keyCount[i].count>frequency)
        {
          printf("key: %s, frequency: %d\n",keyCount[i].key,keyCount[i].count);
        }
      }
    }

  }

  return 0;

}

void initialize()
{
  FILE *fp;
  char hold,key[20];
  int count=0;
  bool whitespace=false;

  fp=fopen("A4_data_f18.txt","r");

  if(fp==NULL)
  {
    printf("File could not be initialized.\n");
    return;
  }

  while((hold=fgetc(fp))!=EOF)
  {
    if(hold == '\n' || hold == ' ')
    {
      key[count]='\0';
      if(!whitespace && strcmp("",key)!=0)
      {
        addKey(key);
      }
      memset(key,0,sizeof(key)); /*clears key*/
      count=0;
      whitespace=true;
      continue;
    }
    else
    {
      key[count]=hold;
      count++;
      whitespace=false;
    }
  }

  if(strcmp("",key)!=0)
  {
    addKey(key);
  }

  fclose(fp);
}

void addKey (char nodeKey[20])
{
  if(nodeKey==NULL)
  {
    return;
  }

  for(int i=0;i<keyCounterCount;i++)
  {
    if(strcmp(keyCount[i].key,nodeKey)==0)
    {
      keyCount[i].count++;
      totalCount++;
      return;
    }
  }
  strcpy(keyCount[keyCounterCount].key,nodeKey);
  keyCount[keyCounterCount].count++;
  keyCounterCount++;
  totalCount++;

}

void *newNode(char nodeKey[20],int count) /*mallocs node, sets left right to null sets count to count*/
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  strcpy(temp->key,nodeKey);
  temp->left=NULL;
  temp->right=NULL;
  temp->count=count;
  return temp;
}

struct node* insertNode(struct node * node,int count,char key[20]) /*puts node into right spot recursively*/
{
  if(node == NULL)
  {
    return newNode(key,count);
  }

  if(strcmp(key,node->key)<=0)
  {
    node->left = insertNode(node->left,count,key);
  }
  else if(strcmp(key,node->key)>0)
  {
    node->right = insertNode(node->right,count,key);
  }
  return node;

}

void inorder(struct node *root)/*prints in order*/
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf("%s\t%d\n",root->key,root->count);
    inorder(root->right);
  }
}

struct node findKey(char toFind[20])
{
  struct node found;
  found.count=0;


  for(int i=0;i<keyCounterCount;i++)
  {
    if(strcmp(toFind,keyCount[i].key)==0)
    {
      strcpy(found.key,toFind);
      found.count=keyCount[i].count;
      return found;
    }
  }

  return found;
}

void Tree_postOrder(struct node *n)
{

     if(n==NULL)
     {
       return;
     }
     Tree_postOrder(n->left);

     Tree_postOrder(n->right);

     printf("%s\n", n->key);

}

struct node removeKey(char toFind[20])
{
  struct node found;
  found.count=0;

  for(int i=0;i<keyCounterCount;i++)
  {
    if(strcmp(toFind,keyCount[i].key)==0)
    {
      strcpy(found.key,toFind);
      found.count=keyCount[i].count-1;
      keyCount[i].count--;
      if(keyCount[i].count==0)
      {
        keyCount[i]=keyCount[keyCounterCount-1]; /*set last one to this one, decrease size by one: basically deletes from array, we will have to remake avl tree after*/
        strcpy(keyCount[keyCounterCount-1].key,"");
        keyCount[keyCounterCount-1].count=0;
      }
      keyCounterCount--;
      return found;
    }
  }

  return found;
}


struct node *avl_balance_node(struct node *node)
{
	struct node *newroot = NULL;

	/* goes to bottom */
	if(node->left)
  {
		node->left  = avl_balance_node(node->left);
  }

	if(node->right)
  {
		node->right = avl_balance_node(node->right);
  }

	int bf = avl_balance_factor(node);

	if(bf >= 2)
  {
		/* Left Heavy */
		if(avl_balance_factor(node->left) <= -1)
    {
      newroot = avl_rotate_leftright(node);
    }

		else
    {
			newroot = avl_rotate_leftleft(node);
    }

	}
  else if(bf <= -2) {
		/* Right Heavy */
		if(avl_balance_factor(node->right) >= 1)
    {
			newroot = avl_rotate_rightleft(node);
    }
		else
    {
			newroot = avl_rotate_rightright(node);
    }
	}
  else
  {
		/*node is balanced*/
		newroot = node;
	}

	return(newroot);
}

int avl_balance_factor(struct node *node)
{
	int bf = 0;

	if(node->left) bf += avl_node_height(node->left);
	if(node->right) bf -= avl_node_height(node->right);

	return bf ;
}

int avl_node_height(struct node *node)
{
	int height_left = 0;
	int height_right = 0;

	if(node->left) height_left = avl_node_height(node->left);
	if(node->right) height_right = avl_node_height(node->right);
	return height_right > height_left ? ++height_right : ++height_left;
}

struct node *avl_rotate_leftleft(struct node *node)
{
 	struct node *a = node;
	struct node *b = a->left;

	a->left = b->right;
	b->right = a;

	return(b);
}

/* Left Right Rotate */
struct node *avl_rotate_leftright(struct node *node)
{
	struct node *a = node;
	struct node *b = a->left;
	struct node *c = b->right;

	a->left = c->right;
	b->right = c->left;
	c->left = b;
	c->right = a;

	return(c);
}

/* Right Left Rotate */
struct node *avl_rotate_rightleft(struct node *node)
{
	struct node *a = node;
	struct node *b = a->right;
	struct node *c = b->left;

	a->right = c->left;
	b->left = c->right;
	c->right = b;
	c->left = a;

	return(c);
}

/* Right Right Rotate */
struct node *avl_rotate_rightright(struct node *node)
{
	struct node *a = node;
	struct node *b = a->right;

	a->right = b->left;
	b->left = a;

	return(b);
}


void avl_balance(struct node **root)
{

	struct node *newroot = NULL;

	newroot = avl_balance_node(*root);

	if(newroot != *root)
  { /*if root changed*/
		*root= newroot;
	}
}


void free_tree(struct node *node)
{
       if (node != NULL)
       {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
      }
}
