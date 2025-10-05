#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_LEN 	100
#define LANG_LEN	30

struct Book
{
	char title[TITLE_LEN];
	double price;
	int pages;
	char language[LANG_LEN];
	double weight;
	int year;
	struct Book * next;
};

struct Book * head = NULL;

void insertAtBeginning(char * title, double price, int pages, char * language, double weight, int year)
{
	struct Book * newBook = (struct Book *) malloc(sizeof(struct Book));
	strcpy(newBook->title, title);
	newBook->price = price;
	newBook->pages = pages;
	strcpy(newBook->language, language);
	newBook->weight = weight;
	newBook->year = year;
	newBook->next = head;
	head = newBook;
}

void insertAtEnding(char * title, double price, int pages, char * language, double weight, int year)
{
	struct Book * newBook = (struct Book *) malloc(sizeof(struct Book));
	strcpy(newBook->title, title);
	newBook->price = price;
	newBook->pages = pages;
	strcpy(newBook->language, language);
	newBook->weight = weight;
	newBook->year = year;
	newBook->next = NULL;
	
	if (head == NULL)
	{
		head = newBook;
	} else {
		struct Book * linkedlist = head;
		while(linkedlist->next != NULL)
		{
			linkedlist = linkedlist->next;
		}
		linkedlist->next = newBook;
	}
}

void printBooks()
{
	struct Book * current = head;
	printf("\nBooks list:\n");
	while(current != NULL)
	{
		printf("Title: %s | Price: %.2f | Pages: %d | Language: %s | Weight: %.2f kg| Year: %d\n",
		current->title, current->price, current->pages, current-> language, current->weight, current->year);
		current = current->next;
	}
}

void searchByTitle(char * title)
{
	struct Book * current = head;
	while(current != NULL)
	{
		if (strcmp(current->title, title) == 0)
		{
			printf("\nFound book: %s (%d)\n", current->title, current->year);
			return;
		}
		current = current->next;
	}
	printf("\nBook with title \"%s\" not founds.\n", title);
}

void searchByYear(int year)
{
	struct Book * current = head;
	int found = 0;
	printf("\nBooks, published in %d:\n", year);
	while(current != NULL)
	{
		if (current->year == year)
		{
			printf("- %s\n", current->title);
			found += 1;
		}
		current = current->next;
	}
	if (found != 0)
	{
		printf("Total books found: %d\n", found);
	}
	else 
	{
		printf("No books for this year.\n");
	}
}

void deleteFromBeginning()
{
	if (head == NULL) return;
	struct Book * temp = head;
	head = head->next;
	free(temp);
	printf("\nThe first book has been deleted.\n");
}

void deleteFromEnd()
{
	if (head == NULL) return;
	if (head->next == NULL) 
	{
		free(head);
		head = NULL;
		printf("\nThe last book has been deleted.\n");
		return;
	}
	struct Book * current = head;
	while(current->next->next != NULL)
	{
		current = current->next;
	}
	free(current->next);
	current->next = NULL;
	printf("\nThe last book has been deleted.\n");
}

void deleteByTitle(char * title)
{
	if (head == NULL) return;
	struct Book * current = head;
	struct Book * prev = NULL;
	
	while(current != NULL)
	{
		if (strcmp(current->title, title) == 0)
		{
			if (prev == NULL)
			{
				head = current->next;
			} else {
				prev->next = current->next;
			}
			free(current);
			printf("\nBook with title \"%s\" has been deleted.\n", title);
			return;
		}
		prev = current;
		current = current->next;
	}
	printf("\nBook with title \"%s\" not found for delete.\n", title);
}

int main ()
{
	
	insertAtBeginning("Harry Potter and the Philosopher's Stone", 1150, 248, "Ukrainian", 1.500, 2016);
	insertAtBeginning("Harry Potter and the Chamber of Secrets", 1200, 264, "Ukrainian", 1.700, 2016);
	insertAtEnding("Harry Potter and the Prisoner of Azkaban", 1200, 336, "Ukrainian", 1.695, 2017);
	insertAtEnding("Harry Potter and the Goblet of Fire", 1300, 464, "Ukrainian", 2.454, 2021);
	
	insertAtBeginning("Harry Potter and the Order of the Phoenix", 1400, 576, "Ukrainian", 2.955, 2022);
	insertAtBeginning("Harry Potter and the Half-Blood Prince", 1301, 542, "English", 0.550, 2005);
	insertAtEnding("Harry Potter and the Deathly Hallows", 420, 640, "Ukrainian", 0.610, 2007);
	
	
	printBooks();
	
	searchByTitle("Harry Potter and the Chamber of Secrets");
	searchByYear(2016);
	
	deleteFromBeginning();
	printBooks();
	
	deleteFromEnd();
	printBooks();
	
	deleteByTitle("Harry Potter and the Half-Blood Prince");
	printBooks();
	
	return 0;
}
