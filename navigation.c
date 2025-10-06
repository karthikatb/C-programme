#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
	char url[100];
	struct Node *prev;
	struct Node *next;
};

struct Node* current = NULL;

void visitNewPage(char url[]) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->url, url);
	newNode->prev = current;
	newNode->next = NULL;
	
	if(current != NULL) {
		current->next = newNode;
	}
	
	current = newNode;
	printf("Visited: %s\n", current->url);
}

void goBack() {
	if(current == NULL || current->prev == NULL) {
		printf("Cannot go back, No previous page.\n");
	}else {
		current = current->prev;
		printf("Moved back to: %s\n", current->url);
	}
}

void goForward() {
	if (current == NULL || current->next == NULL) {
        printf("Cannot go forward, No next page.\n");
        } else {
        	current = current->next;
        	printf("Moved forward to: %s\n", current->url);
    	}
}

void displayCurrentPage() {
	if(current == NULL) {
		printf("No page visited yet.\n");
	}else {
		printf("Current Page: %s\n", current->url);
	}
}

int main() {
	int choice;
    	char url[100];

    do {
        printf("\nMenu\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("Enter URL to visit: ");
                fgets(url,100,stdin);  
                visitNewPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrentPage();
                break;
            case 5:
                printf("Exiting Browser Simulation.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}
