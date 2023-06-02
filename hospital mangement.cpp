#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
//*******prototype function*******
void add(int [],char[][20],int[],char[][20],char[][20],char[][20],int [20]);
void print(int [],char[][20],int[],char[][20],char[][20],char[][20],int [20]);
void update(int [],char[][20],int[],char[][20],char[][20],char[][20],int [20]);
void deleting(int [],char[][20],int[],char[][20],char[][20],char[][20],int [20]);
void search(int [],char[][20],int[],char[][20],char[][20],char[][20],int [20]);
void login();
void main_menu();
int size=0;
//**********main function*********
int main(){
	printf("\t\t\t***Welcome To palestine Hospital Management system***\n\n\n\n");
	login();
}
//**********login function********
void login(){
char username[20];    
char password[20];
printf("Please enter your user name:\t");
scanf("%s",username);
printf("\nPlease enter your password:\t");
scanf("%s",password);
if(strcmp("hima",username)==0&&strcmp("9912",password)==0)
main_menu();
else
printf("****login failed*****");
}
//**********main menu********
void main_menu(){
	int pat_id[100],n,pat_age[100],pat_contact_no[20];
	char pat_name[100][20],pat_problem[100][20],pat_prescribed_doctor[100][20],pat_address[100][20];
	do{
		system("cls");
		printf("\n1-Add patients");
		printf("\n2-Print patients");
		printf("\n3-Update patients");
		printf("\n4-Deleting patients");
		printf("\n5-Search patients");
		printf("\n6-Exit");
		printf("\nselect number[1...6]:");
		scanf("%d",&n);
		switch(n){
			case 1:add(pat_id,pat_name,pat_age,pat_problem,pat_prescribed_doctor,pat_address,pat_contact_no);
			break;
			case 2:print(pat_id,pat_name,pat_age,pat_problem,pat_prescribed_doctor,pat_address,pat_contact_no);
			break;
			case 3:update(pat_id,pat_name,pat_age,pat_problem,pat_prescribed_doctor,pat_address,pat_contact_no);
			break;
			case 4:deleting(pat_id,pat_name,pat_age,pat_problem,pat_prescribed_doctor,pat_address,pat_contact_no);
			break;
			case 5:search(pat_id,pat_name,pat_age,pat_problem,pat_prescribed_doctor,pat_address,pat_contact_no);
			break;
			case 6:exit(0);
			break;
			}
	}while(1);
}
//***********add elements in array**************
void add(int id[],char name[][20],int age[],char problem[][20],char prescribed_doctor[][20],char address[][20],int contact_no[20]){
	char m;
	do{
		system("cls");
		printf("\nEnter id[%d]=",size+1);
		scanf("%d",&id[size]);
		printf("\nEnter name patient[%d]=",size+1);
		scanf("%s",name[size]);
		printf("\nEnter age patient[%d]=",size+1);
		scanf("%d",&age[size]);
		printf("\nEnter problem patient[%d]=",size+1);
		scanf("%s",problem[size]);
		printf("\nEnter prescribed_doctor[%d]=",size+1);
		scanf("%s",prescribed_doctor[size]);
		printf("\nEnter address patient[%d]=",size+1);
		scanf("%s",address[size]);
		printf("\nEnter contact_no patient[%d]=",size+1);
		scanf("%d",&contact_no[size]);
		++size;
		fflush(stdin);
		printf("\n\nadd new patient[y/n]:");
		scanf("%c",&m);
	}
	while(m=='y'||m=='Y');
}
//***********print elements of array**************
void print(int id[],char name[][20],int age[],char problem[][20],char prescribed_doctor[][20],char address[][20],int contact_no[20]){
	int j;
	system ("cls");
	for(j=0;j<size;++j){
		printf("\nid patient[%d]=%d",j+1,id[j]);
		printf("\nname patient[%d]=%s",j+1,name[j]);
		printf("\nage patient[%d]=%d",j+1,age[j]);
		printf("\nproblem patient[%d]=%s",j+1,problem[j]);
		printf("\nprescribed_doctor[%d]=%s",j+1,prescribed_doctor[j]);
		printf("\naddress patient[%d]=%s",j+1,address[j]);
		printf("\ncontact_no patient[%d]=%d",j+1,contact_no[j]);
		printf("\n***************");
	}
	getch();
}
//*****************update elements of array*******
void update(int id[],char name[][20],int age[],char problem[][20],char prescribed_doctor[][20],char address[][20],int contact_no[20]){
	int k,no;
	system("cls");
	printf("Enter number to update:");
	scanf("%d",&no);
	for(k=0;k<size;++k){
	if(id[k]==no){
		printf("\nEnter new id:");
		scanf("%d",&id[k]);
		printf("\nEnter new name patient:");
		scanf("%s",&name[k]);
		printf("\nEnter new age patient:");
		scanf("%d",&age[k]);
		printf("\nEnter new problem patient:");
		scanf("%s",&problem[k]);
		printf("\nEnter new prescribed_doctor:");
		scanf("%s",&prescribed_doctor[k]);
		printf("\nEnter new address patient:");
		scanf("%s",&address[k]);
		printf("\nEnter new contact_no patient:");
		scanf("%d",&contact_no[k]);
		printf("\n<<<<<<updadting is done>>>>>>");
         break;
} 
	else if(id[k]!=no)
	{printf("\n*********number is not fuond to updating**********");
	break;}
}
	  getch();
}
//*******deleting elements of array*****
	void deleting(int id[],char name[][20],int age[],char problem[][20],char prescribed_doctor[][20],char address[][20],int contact_no[20]){
		int t,num,g,flag=0;
		system("cls");
		printf("Enter number to delet:");
		scanf("%d",&num);
		for(t=0;t<size;++t)
		if(id[t]==num){
			--size;
			flag=1;
			break;
		}
		for(g=t;g<size;++g){
			id[g]=id[g+1];
			strcpy(name[g],name[g+1]);
			age[g]=age[g+1];
			strcpy(problem[g],problem[g+1]);
			strcpy(prescribed_doctor[g],prescribed_doctor[g+1]);
			strcpy(address[g],address[g+1]);
		    contact_no[g]=contact_no[g+1];
		}
		if(flag==1)
		printf("\n<<<<deleting is done>>>>");
		else
		printf("\n<<<<<Not found number to delet>>>>>");
		getch();
}
//******************search elements of array***********************
void search(int id[],char name[][20],int age[],char problem[][20],char prescribed_doctor[][20],char address[][20],int contact_no[20])
{
	int i,nm,flag=0;
	system("cls");
	printf("Enter number to find:");
	scanf("%d",&nm);
	for(i=0;i<size;++i)
	if(id[i]==nm){
		flag=1;
		break;
	}
	if(flag==1){
	printf("\n%d is found",id[i]);
	printf("\n\nDetails of this id=%d",id[i]);
   	printf("\n name patient[%d]=%s",i+1,name[i]);
   	printf("\n id[%d]=%d",i+1,age[i]);
	printf("\n problem patient[%d]=%s",i+1,problem[i]);
	printf("\n prescribed_doctor[%d]=%s",i+1,prescribed_doctor[i]);
	printf("\n address patient[%d]=%s",i+1,address[i]);
	printf("\n contact_no patient[%d]=%d",i+1,contact_no[i]);		
	}
	else
	printf("\n %d is not found",nm);
	getch();
}
