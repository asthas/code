#include <stdio.h>
#include <stdlib.h>
#define RED 0
#define BLACK 1

struct node {
	int key;
	int color;
	struct node* parent;
	struct node* left;
	struct node* right;
};

typedef struct node NODE;

void insertNode ();
void placeNode  (NODE* tmp);
void travelTree (NODE* trv);
void printNode  (NODE* tmp);

NODE* root = NULL;

void insertNode () {
	NODE* tmp = malloc (sizeof(NODE));
	
	printf ("Enter value to insert: ");
	scanf  ("%d", &(tmp->key));
	
	tmp->left   = NULL;
	tmp->right  = NULL; 
	tmp->parent = NULL;

	tmp->color  = BLACK; 
	
	if (!root) {
		root = tmp;
	} else {
		placeNode (tmp);
	}
}

void placeNode (NODE* tmp) {
	NODE* trv = root;
	
	while (trv) {
		if (tmp->key > trv->key) {
			if (!trv->right) {
				tmp->parent = trv;
				trv->right = tmp;
				return;
			}
			trv = trv->right;
		} else {
			if (!trv->left) {
				tmp->parent = trv;
				trv->left  = tmp;
				return;
			}
			trv = trv->left;
		}
	}

}

void travelTree (NODE* trv) {

	if (!trv) {
		printf ("\n\n");
		return;
	}
	travelTree (trv->left);
	printNode  (trv);
	travelTree (trv->right);

}

void printNode (NODE* tmp) {
	printf ("KEY:   %d\n", tmp->key);

	if (tmp->color == RED)
		printf ("COLOR: RED\n");
	else
		printf ("COLOR: BLACK\n");

	if (tmp->parent != NULL)
		printf ("PARENT:  %d\n", (tmp->parent)->key);
	else
		printf ("ROOT NODE\n");
	
	if (tmp->left != NULL)
		printf ("LEFT:  %d\n", (tmp->left)->key);
	
	if (tmp->right != NULL) 
		printf ("RIGHT: %d\n", (tmp->right)->key);
}

int main () {

	int choice = 0;

	do {
		insertNode ();
		travelTree (root);
		printf ("Enter 1 to continue: ");
		scanf  ("%d", &choice);
	} while (choice);

	return 0;
}
