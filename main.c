/*
 *	main.c
 *
 *	Created on: Aug 12, 2024
 *	Author: Youssef Maged Tadros
 */

/***********************INCLUDES***********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***********************STRUCTS***********************/

/* Define a structure to represent Student Data */

struct student{
	int id;				/*Student ID*/
	char name[50];		/*Student Name*/
	int age;			/*Student Age*/
	float gpa;			/*Student GPA*/
};
struct student stu;

/* Define a structure to represent a node in a linked list */

struct node{
	struct student data;
	struct node *next;
};

struct node *head=NULL;

/***********************FUNCTION PROTOTYPES***********************/

void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);




int main(void){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

int choice;			/*User choice from the menu*/
int ID;				/*Student ID to search for a student*/
float average_gpa;	/*Average GPA of students*/
printf("***************************************************************\n");
while(1){

printf(	"1) Add Student\n"
		"2) Display Students\n"
		"3) Search by ID\n"
		"4) Update Student by ID\n"
		"5) Delete Student by ID\n"
		"6) Calculate Average GPA\n"
		"7) Search for Highest GPA\n"
		"8) Exit\n"
		"Enter your choice:  ");
		scanf("%d",&choice);


switch(choice){

case 1:	printf("***************************************************************\n");
		printf("Enter Student ID:	");
		scanf(" %d",&stu.id);
		printf("Enter Student Name:	");
		//puts(stu.name);
		scanf("%s",stu.name);
		printf("Enter Student Age:	");
		scanf(" %d",&stu.age);
		printf("Enter Student GPA:	");
		scanf(" %f",&stu.gpa);
		addStudent(&stu);
		break;
case 2:	printf("***************************************************************\n");
		displayStudents();
		break;
case 3:	printf("***************************************************************\n");
		printf("Enter the ID :	");
		scanf("%d",&ID);
		searchStudentByID(ID);
		break;
case 4:	printf("***************************************************************\n");
		printf("Enter the ID :	");
		scanf("%d",&ID);
		updateStudent(ID);
		break;
case 5:	printf("***************************************************************\n");
		printf("Enter the ID :	");
		scanf("%d",&ID);
		deleteStudent(ID);
		break;
case 6:	printf("***************************************************************\n");
		average_gpa=calculateAverageGPA();
		printf("The average GPA is:	%.2f  \n",average_gpa);
		printf("***************************************************************\n");
		break;
case 7:	printf("***************************************************************\n");
		searchHighestGPA();
		break;
case 8: break;
default: printf("Wrong Choice \n");
		 printf("***************************************************************\n");
		 break;
}
if(choice==8){
	printf("Exiting....");
	break;
}
}

	return 0;
}

/***********************FUNCTION DEFINITIONS***********************/

void addStudent(const struct student *const ptr){
	printf("***************************************************************\n");

	// pointer to loop in linked list
	struct node *current = NULL;

	if(head==NULL){

		// Allocate memory for new node
		struct node*element=(struct node*)malloc(sizeof(struct node));

		if(element==NULL){
			printf("The list is full ! \n");
			return;
		}


		head=element;					/*The added node will be the head*/
		element->next=NULL;
		element->data.id=ptr->id;
		strcpy(element->data.name,ptr->name);
		element->data.age=ptr->age;
		element->data.gpa=ptr->gpa;
		return;

	}

	current=head;
	while(current->next!=NULL){
		if(current->data.id==ptr->id){
			printf("The ID is already reserved ! \n");
			printf("***************************************************************\n");
			return;
		}
		current=current->next;
	}

    // Check the last node for a duplicate ID
    if(current->data.id == ptr->id){
        printf("The ID is already reserved! \n");
        printf("***************************************************************\n");
        return;
    }

	// Allocate memory for new node
	struct node*element=(struct node*)malloc(sizeof(struct node));

	if(element==NULL){
		printf("The list is full ! \n");
		return;
	}

	//The added node will be the last
	current->next=element;
	element->next=NULL;
	element->data.id=ptr->id;
	strcpy(element->data.name,ptr->name);
	element->data.age=ptr->age;
	element->data.gpa=ptr->gpa;


}


void displayStudents(void){

	// pointer to loop in linked list
	struct node *current = NULL;

	if(head==NULL){
		printf("The List is empty \n");
		printf("***************************************************************\n");
		return;
	}
	else{
	current=head;
	while(current!=NULL){
		printf("ID:	%d \n",current->data.id);
		printf("Name:	%s \n",current->data.name);
		printf("Age:	%d \n",current->data.age);
		printf("GPA:	%.2f \n",current->data.gpa);
		printf("***************************************************************\n");
		current=current->next;
	}
	}
}


void searchStudentByID(int id){
	// pointer to loop in linked list
	struct node *current = NULL;

	current=head;
	while(current!=NULL){
		if(current->data.id==id){
			printf("ID:	%d \n",current->data.id);
			printf("Name:	%s \n",current->data.name);
			printf("Age:	%d \n",current->data.age);
			printf("GPA:	%.2f \n",current->data.gpa);
			printf("***************************************************************\n");

		return;
		}
		else
		current=current->next;
	}
	printf("Student is not found \n");
	printf("***************************************************************\n");

}


void updateStudent(int id){

	// pointer to loop in linked list
	struct node *current = NULL;

	current=head;
	while(current!=NULL){
		if(current->data.id==id){
			printf("Updated Student Name:	");
			scanf("%s",current->data.name);
			printf("Updated Student Age:	");
			scanf("%d",&current->data.age);
			printf("Updated Student GPA:	");
			scanf("%f",&current->data.gpa);
			printf("Student updated successfully\n");
			printf("***************************************************************\n");
		return;
		}
		else
		current=current->next;
	}
	printf("Student is not found \n");
	printf("***************************************************************\n");


}


float calculateAverageGPA(void){
	int count=0;			/*Number of students*/
	float sum=0.0;			/*Sum of GPAs*/
	float avg;				/*Average of all students GPA*/

	if(head==NULL)
		return 0.0 ;

	// pointer to loop in linked list
		struct node *current = NULL;

		current=head;
		while(current!=NULL){
			count++;
			sum+=current->data.gpa;
			current=current->next;
		}
	avg=sum/count;
	return avg;

}

void searchHighestGPA(void){

	float highest_gpa=0.0;

	// pointer to loop in linked list
		struct node *current = NULL;

	// pointer to save the address of the student with highest GPA
		struct node *highest = NULL;

		if(head==NULL){
			printf("The list is empty ! \n");
			printf("***************************************************************\n");
			return;
		}
		current=head;
		while(current!=NULL){
			if(current->data.gpa>highest_gpa){
				highest_gpa=current->data.gpa;
				highest=current;
			}
			else
			current=current->next;
		}

		printf("ID:	%d \n",highest->data.id);
		printf("Name:	%s \n",highest->data.name);
		printf("Age:	%d \n",highest->data.age);
		printf("GPA:	%.2f \n",highest->data.gpa);
		printf("***************************************************************\n");

}


void deleteStudent(int id){

	struct node *current = NULL;
	struct node *prev = NULL;

	// pointer to point to the node that will be deleted
	struct node * delete_node = NULL;

	//check if the linked list is empty
	if(head==NULL)
	{
		printf("The List is empty \n");
		printf("***************************************************************\n");
		return;
	}

	//check the first node in the linked list
	if(head->data.id == id)
	{
		delete_node = head;
		// move head to next node
		head = head->next;
		free(delete_node);
		printf("Student deleted successfully \n");
		printf("***************************************************************\n");
		return;
	}

	//check the rest of nodes in the list
	current = head->next;
	prev = head;
	while(current != NULL)
	{
		if(current->data.id == id)
		{
			//element found
			delete_node = current;
			prev->next = current->next;
			free(delete_node);
			printf("Student deleted successfully \n");
			printf("***************************************************************\n");
			return;
		}
		prev = current;
		current = current->next;
	}

	//in case the student is not found in the list
	if(delete_node == NULL)
	{
		printf("Student is not found in the List \n");
		printf("***************************************************************\n");

	}

}







