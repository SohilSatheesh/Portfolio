
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Structure to store user details

struct user_data{
	char username[20];
	char password[20];
	char website[20];
	int flag;
};

// Function to generate random password

void generate_password(int length, char *password){
	int i;
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@#!$%&*";	
	for(i = 0; i<length;++i){
		int random = rand() % 62;
		password[i] = a[random];
	}
	password[i] = '\0';
}

// Function to check user details while login

int check_user_details(struct user_data data[], int count, char *username, char *password){
	int i;
	for(i=0;i<count;i++){
		if(data[i].flag == 1){
			if(strcmp(data[i].username, username) == 0 
				&& strcmp(data[i].password, password) == 0){
				return 1;
			}
		}
	}
	return 0;
}

// Function to retrieve user's password

void retrieve_password(struct user_data data[], int count, char *username, char *website){
	int i;
	for(i=0;i<count;i++){
		if(data[i].flag == 1){
			if(strcmp(data[i].username, username) == 0 
				&& strcmp(data[i].website, website) == 0){
				printf("Your password is %s", data[i].password);
				return;
			}
		}
	}
	printf("No such record found!");
} 

int main(){
	// Initialising variable 
	
	struct user_data data[20];
	int i, count, flag;
	int choice;
	char username[20], password[20], website[20];
	
	// Setting the flag to 0
	
	for(i=0;i<20;i++){
		data[i].flag = 0;
	}
	
	// Seeding the random generator
	
	srand(time(NULL));
	
	// Specifying number of records
	
	printf("Enter the number of records: ");
	scanf("%d", &count);
	
	// Taking input from user
	
	for(i=0;i<count;i++){
		printf("Enter username: ");
		scanf("%s", username);
		strcpy(data[i].username, username);
		printf("Enter website: ");
		scanf("%s", website);
		strcpy(data[i].website, website);
		generate_password(10, password);
		strcpy(data[i].password, password);
		data[i].flag = 1;
		printf("Generated Password: %s\n\n", data[i].password);
		
	}
	
	do{
		// Displaying menu
		
		printf("-----Password Manager-----\n");
		printf("1. Login\n2. Retrieve Password\n3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			// Login 
			
			case 1:
				printf("Enter username: ");
				scanf("%s", username);
				printf("Enter password: ");
				scanf("%s", password);
				
				flag = check_user_details(data, count, username, password);
				if(flag == 1){
					printf("Logged in successfully!\n");
				}
				else{
					printf("Invalid username or password!\n");
				}
				break;
				
			// Retrieve Password
			
			case 2: 
				printf("Enter your username: ");
				scanf("%s", username);
				printf("Enter the website: ");
				scanf("%s", website);
				
				retrieve_password(data, count, username, website);
				
				break;
				
			// Exit 
			
			case 3:
				exit(0);
				
			default:
				printf("Enter valid choice!\n");
		}
		
	}while(choice != 3);
	
	return 0;
}
