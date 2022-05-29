//Bus Reservation System.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Bus[32]={};

//Function starts.
void write_data()
{
	int i;
	FILE *fptr;
	fptr=fopen("seat.txt","w");
	for(i=1;i<32;i++)
	{
		fprintf(fptr,"%d\n\t\n\t",Bus[i]);
	}
	fclose(fptr);
}
//Function end's.

//Function start's
void read_data()
{
	FILE *fptr;
	fptr=fopen("Record.txt","r");
	int i;
	for(i=1;i<32;i++)
	{
		fscanf(fptr,"%d\t",&Bus[i]);
	}
	fclose(fptr);
}
//Function end's.

void showBus()
{
	
}

//Reserve function start's.
struct user{
	char name[100];
	int number;
};
void book()
{
	struct user u;
	showBus();
	FILE *fptr;
	fptr=fopen("Reserves.txt","a");
	int i;
	read_data();
	for(i=1;i<32;i++)
	{
		printf("\t%d\t",Bus[i]);	
	}
	int choice;
	printf("\nEnter your seat number:");
	scanf("%d",&choice);
	if(Bus[choice-1]==0)
	{
		fflush(stdin);
		printf("\nEnter your name:");
		gets(u.name);
		printf("\nEnter your contact number:");
		scanf("%d",&u.number);
		Bus[choice-1]=1;
		write_data();
		fprintf(fptr,"%s %d %d\n",u.name,u.number,choice);
	}
	else
	{
		printf("Sorry this seat is already booked. Please select another seat n.o\n");
		book();
	}
	fclose(fptr);	
}
//Reserve function end's.

//View function start's.
void view()
{
char ch;
FILE *fptr;

fptr = fopen("Reserves.txt","r");
if(fptr == NULL)
{
	printf("File not found !");
	/*exit(1);*/
}
else
{
while( ( ch = fgetc(fptr) ) != EOF )
      printf("%c",ch);

}
fclose(fptr);
}
//View function end's.
//Search function start's.
void search()
{
	struct user u[32];
	FILE *fptr;
	fptr=fopen("Reserves.txt","r");
	int i=0,count=0;
	while(!feof(fptr))
	{
		fscanf(fptr,"%s %d\n",u[i].name,&u[i].number);
		i++;
		count++;	
	}
	int search;
	printf("\nEnter the phone n.o to be searched");
	scanf("%d",&search);
	for(i=0;i<count;i++)
	{
		if(u[i].number==search)
		{
			printf("%s %d\n",u[i].name,u[i].number);
		}
	}
}
//Search function end's.

//Cancel function start's.
void cancel()
{
	FILE *fptr;
	fptr=fopen("Reserves.txt","r");
	struct user u[32];
	int i=0,choice,count=0;
	while(!feof(fptr))
	{
		fscanf(fptr,"%s %d\n",u[i].name,&u[i].number);
		printf("%s %d\n",u[i].name,u[i].number);
		count++;
		i++;
	}
	fclose(fptr);
	printf("\nEnter the contact n.o of user you want to cancel:");
	scanf("%d",&choice);
	fptr=fopen("Reserves.txt","w");
	for(i=0;i<count;i++)
	{
		if(u[i].number==choice)
		{
			continue;
		}
		else
		{
			fprintf(fptr,"%s %d\n",u[i].name,u[i].number);
		}
	}
		fclose(fptr);
	printf("\nContact has been deleted.\n");
}
//Cancel function end's.

//Update function start's.
void update()
{
	FILE *fptr;
	fptr=fopen("Reserves.txt","r");
	struct user u[32],update;
	int count=0,i=0,choice;
	while(!feof(fptr))
	{
		fscanf(fptr,"%s %d\n",u[i].name,&u[i].number);
		printf("%s %d \n",u[i].name,u[i].number);
		count++;
		i++;
	}
	fclose(fptr);
	printf("\nEnter the number of user you want to update:\n");
	scanf("%d",&choice);
	printf("\nEnter the details of user again:");
	scanf(" %s %d",&update.name,&update.number);
	fptr=fopen("booking.txt","w");
	for(i=0;i<count;i++)
	{
		if(u[i].number==choice)
		{
			fprintf(fptr,"%s %d \n",update.name,update.number);
		}
		else
		{
			fprintf(fptr,"%s %d \n",u[i].name,u[i].number);}
		}
		fclose(fptr);
	printf("Successfull Updated\n");	
}
//Update function end's.

//Password function start's.
void password()
{
	char ch;
	int i=0,j;
	char pass[20];
	char read[20];
	FILE *fptr;
	fptr=fopen("password.txt","r");
	fscanf(fptr,"%s",read);
	fclose(fptr);
	printf("Please type code to access:-");
    pass[i]=getch();
	while(pass[i]!=13)
	{
		if(pass[i]==8)
		{
			system("cls");
			for(j=0;j<i-1;j++)
			{
				printf("*");
			}
			i--;
		}
		else
		{
			printf("*");
			i++;
			pass[i]=getch();
		}
	}
	pass[i]='\0';
	if(strcmp(read,pass)==0)
	{
		void main();
	}
	else
	{
		printf("\nIncorrect Password-Try again\n");
		password();
	}
}
//Password function end's

void main()
{
//Display of the option's to be entered through keyboard.
	password();
Option: 	printf("                 Bus Reservation System\n");
	printf(" \t\t--------------------------------------------------------------------\n");
	printf("\t\t**             1. Bus Installation:-                                 **\n");
	printf("\t\t**             2. Show details:-                                     **\n");
	printf("\t\t**             3. Search details:-                       	          |**\n");
	printf("\t\t**             4. Update:-                                                    |**\n");
	printf("\t\t**             5. Cancel:-                                                    |**\n");
	printf("\t\t**             6. Exit :-                                                     |**\n");
	printf("\t\t**----------------------------------------------------------------------------|**\n");
	printf("  Enter your choice: ");
//First display end's
//Switch start's
	int choice;
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				book();
				break;
			case 2:
				view();
				break;
			case 3:
				search();
				break;
			case 4:
				update();
				break;	
			case 5:
				cancel();
				break;
			case 6:
				printf("Thank you for visiting.");
				break;
			default:
				printf("\nInvalid Option");
				break;
		}
		char ch;
		printf("\nDo you like to use another option's?(y/n):");
		scanf(" %c",&ch);
		if(ch=='y')
		{
			system("cls");
			goto Option;
		}
//Switch end's.
}
