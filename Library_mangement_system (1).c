#include<stdio.h>
#include<conio.h>
#include<string.h>
struct library{
	int bookid;
	char name[30];
	char author_name[20];
}book;
FILE *fp,*p,*f;
int main()
{
	login(); 
}
login()
{
	char pword[]="abc";
	char password[10];
	printf("\n Username:ABC");
	printf("\n Password:");
	gets(password);
	if(strcmp(password,pword)==0)
	{
		printf("\nCorrect Password");
		printf("\nPress Any key For Menu.................");
		getch();
		system("cls");
		menu();
	}
	else
	{
		printf("\nPassword is Incorrect");
		getch();
		system("cls");
		printf("\n Re-enter the Password");
		printf("\n\n");
		login();
	}
	
}
menu()
{
	int choice;
	printf("\n1.Add New Book");
    printf("\n2.ViewBooks");
    printf("\n3.SearchBooks");
    printf("\n4.DeleteBook");
	printf("\n5.Exit");
    printf("\nEnter Your Choice:");
	scanf("%d",&choice);
	switch(choice)
	    {
	    	case 1:
	    		addbook();
	    		break;
	    	case 2:
	    		viewbooks();
	    		break;
	    	case 3:
	    		searchbooks();
	    		break;
	    	case 4:
	    		deletebooks();
	    		break;
	    	default:
	    		printf("\nInvalid Choice");
		}
	
}
addbook()
{
	
	fp=fopen("myfile1.txt","a");
	printf("\n\nAdd Book Details");
    printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");
    fflush(stdin);
    printf("\nEnter the Book Id No:");
    scanf("%d",&book.bookid);
    fflush(stdin);
    printf("Enter the Book Name:");
    gets(book.name);
    printf("Enter the Author Name:");
	fflush(stdin);
	gets(book.author_name);
	fwrite(&book,sizeof(book),1,fp);
	fclose(fp);
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\nBook Added Successfully\n\n");
	getch();
	system("cls");	
	menu();
}
viewbooks()
{
	p=fopen("myfile1.txt","r");
	printf("\n\n");
	printf("------------------------------------------------------------------Books Present in Library------------------------------------------------------------------");
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");

	while(fread(&book,sizeof(book),1,p)>0)
	{ 
		printf("\nBook Id-%d",book.bookid);
        printf("\nBook Name-%s",book.name);
	    printf("\nAuthor Name-%s",book.author_name);
	    printf("\n");
	}
	fclose(p); 
	printf("\n\n"); 
	getch();
	system("cls");      
	menu();
}
searchbooks()
{
	int bID,choice,found=0;
	char Bookname[20];
	
	
	printf("\n1.Search By BookID-   Type 1");
	printf("\n2.Search By BookName-   Type 2");

	fflush(stdin);
	printf("\n\nEnter Your Choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nEnter Book Id you want to search:");
	        scanf("%d",&bID);
	        p=fopen("myfile1.txt","r");
	        while(fread(&book,sizeof(book),1,p)>0)
            	{
		            if(book.bookid==bID)
		               {
		                	printf("\nBook Id-%d",book.bookid);
                            printf("\nBook Name-%s",book.name);
	                        printf("\nAuthor Name-%s",book.author_name);
	                        printf("\n");
							found=1;	
		               }
	           }
	        if(found==0)
	        {
	        	printf("\nBook is Not Present in Library");
			}
           	fclose(p);
	        break;
	    case 2:
	    	fflush(stdin);
	    	printf("\nEnter Book Name you want to search:");
        	gets(Bookname);
        	p=fopen("myfile1.txt","r+");
	        while(fread(&book,sizeof(book),1,p)>0)
            	{
		            if(strcmp(Bookname,book.name)==0)
		               {
		                	printf("\nBook Id-%d",book.bookid);
                            printf("\nBook Name-%s",book.name);
	                        printf("\nAuthor Name-%s",book.author_name);
	                        printf("\n");	
	                        found=1;
		               }
	           }
	        if(found==0)
	        {
	        	printf("\nBook is Not Present in Library");
			}
           	fclose(p);
            break;
	}
	getch();
	system("cls");
	menu();
	
}
deletebooks()
{
	int bID,choice,found=0;
	printf("\nEnter Book Id you want to Delete:");
    scanf("%d",&bID);
	p=fopen("myfile1.txt","r");
	
	while(fread(&book,sizeof(book),1,p)>0)
    {
		if(book.bookid==bID)
		   {
		   	    printf("\nBook Id-%d",book.bookid);
                printf("\nBook Name-%s",book.name);
	            printf("\nAuthor Name-%s",book.author_name);
		   	    
		        found=1;	
		   }
		            
					
	}
	if(found==0)
	{
	    printf("\nBook Record Not Found");
	}
	rewind(p);
	f=fopen("tempfile1.txt","w+");
	while(fread(&book,sizeof(book),1,p)>0)
	{
		if(book.bookid!=bID)
		   fwrite(&book,sizeof(book),1,f);
	}
	fclose(p);
	fclose(f);
	remove("myfile1.txt");
	rename("tempfile1.txt","myfile1.txt");
	if(found==1)
	{
	   	printf("\n\nThisBook has been Deleted");	
	}

	
	getch();
	system("cls");
	menu();
	
}



















