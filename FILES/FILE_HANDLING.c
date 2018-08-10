/*
 *DEVELOPER----AMAN DUBEY
 *DATE-------15/SEP/2017
 *
 *PROGRAM FOR FILE HANDLING FOR THE RECORD OF STUDENT AND GIVE OUTPUT IN AN FILE
 */
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 
 FILE *outp;																/*DECLARATION OF OUTPUT VARIABLE FOR FILE*/

	  struct class_record													/*DECLARATION OF STRUCTURE*/
	  {
		  int roll_no;
		  char name[20];
		  int sem;
		  int year;
		  char department[5];
		  struct class_record *next;
		  struct class_record *previous;
	  };
	  struct class_record *next=NULL;
	  struct class_record *previous=NULL;
	  struct class_record *start=NULL;
	  struct class_record *tail=NULL;
	  
	  int count=0;																					/*DECLARATION OF COUNT FOR SORTING THE DATA*/
	  int count_sort=0;
	  
	  void insert_data_at_beginning(struct class_record* ptr);										/****************************************************/
	  void insert_data_at_end(struct class_record* ptr);											/*DECLARATION OF FUNCTIONS FOR THE INSERTION OF DATA*/
	  void insert_data_after_num(struct class_record* ptr);											/****************************************************/
	  
	  
	  void delete_data_at_beginning();										/**************************************************/
	  void delete_data_at_end();											/*DECLARATION OF FUNCTION FOR THE DELETION OF DATA*/
	  void delete_data_at_num();											/**************************************************/
	  
	  
	  void display_data_at_beginning();										/**********************************************/
	  void display_data_at_end();											/*DECLARATION OF FUNCTION FOR DISPLAY OF DATA*/
	  void display_data_at_num();											/*********************************************/
	  
	  
	  void linear_search_in_list();											/*DECLARATION OF FUNCTION FOR LINEAR SEARCH*/
	  void sorting_of_data();												/*DECLARATION OF FUNCTION FOR SORTING ACCORDING TO ROLL NUMBER*/
	  
	  void display_in_file();												/*DECLARATION OF FUNCTION FOR INITIAL DISPLAY IN FILE*/
	  void enter_choice();													/*DECLARATION OF FUNCTION TO TAKE CHOICE FROM USER*/
	  void title_row();
	  void title_row_file();
	  
	  void choice_insert_data();
	  void choice_delete_data();
	  void choice_display_data();
	  struct class_record* enter_data();
	  void enter_data_in_files(struct class_record* ptr);
	  struct class_record* linear_search_for_delete_insert(int element);					/*DECLARATION OF FUNCTION FOR LINEAR SEARCH FOR DELETE AND INSERT*/
	  void display_data_on_prompt(struct class_record* x);									    /*DECLARATION OF FUNCTION FOR DISPLAY BY TAKIN ADDRESS*/
	  void display_all();																/*DECLARATION OF FUNCTION TO DISPLAY ALL DATA*/
	  void update_data_in_file();
	  void display_data_on_file(struct class_record* x);

	  
	  int main()																			/*MAIN FUNCTION*/
	  {
		  
		  
		  outp=fopen("E://program//CPP&C//FILES//output_file.out","a");
		  display_in_file();
		  
		  a:
		  enter_choice();
		  goto a;

		  return 0;
	  }
		  
		  
	  
	  
	  
	  void insert_data_at_beginning(struct class_record* ptr)										/*DEFINATION OF FUNCTIION TO INSERT AT BEGINNING*/
	  {
		  struct class_record* loc;
		  
		  if(start==NULL)
		  {
			  start=ptr;
			  tail=ptr;
		  }
		  else
		  {
			  start->previous=ptr;
			  ptr->next=start;
			  start=ptr;
		  }
		  
	  }
	  void insert_data_at_end(struct class_record* ptr)
	  {
		  struct class_record* loc;
		  
		  if(start==NULL)
		  {
			  start=ptr;
			  tail=ptr;
		  }
		else
		{
			tail->next=ptr;
			ptr->next=tail;
			tail=ptr;
		}
		  
		  
	  }
	  void insert_data_after_num(struct class_record* ptr)											
	  {
		  struct class_record *loc,*postptr;
		  int element;
		  printf("\nEnter the roll number after you want to insert data>>");
		  scanf("%d",&element);
		  loc=linear_search_for_delete_insert(element);
		  printf("%d",loc->roll_no);
		  if(loc==NULL)
			{
				printf("Roll_no not found"); 
				
				
			}
			else if(loc==tail)
			{
				insert_data_at_end(ptr);
			}
			else
			{
				postptr=loc->next;
				loc->next=ptr;
				ptr->previous=loc;
				ptr->next=postptr;
				postptr->previous=ptr;
				
			} 
	  }
	  
	  void delete_data_at_beginning()
	  {
		  struct class_record *loc,*ptr;
		  if(start==NULL)
		  {
			  printf("\nUNDERFLOW");
		  }
		  else if(start->next==NULL)
		  {
			loc=start;
			start=NULL;
			free(loc);
		  }
		  else
		  {
			loc=start;
			start=loc->next;
			ptr=start;
			ptr->previous=NULL;
			free(loc);
		  }
	  }
	  void delete_data_at_end()	
	  {
		  struct class_record *loc,*ptr;
		  if(start==NULL)
		  {
				printf("\nUNDERFLOW");
		  }
		  else if(start->next==NULL)
		  {
			loc=start;
			start=NULL;
			tail==NULL;
			free(loc);
		   }
		   else
		   {
				loc=tail;
				ptr=tail;
				loc=loc->previous;
				loc->next=NULL;
				tail=loc;
				free(ptr);
			}
	  }
	  void delete_data_at_num()									
	  {
		  int delete_roll;
		  struct class_record *loc,*ptr,*temp,*temp1;
		  
		    printf("\nEnter the data roll number to be deleted>>");
			scanf("%d",delete_roll);
			loc=linear_search_for_delete_insert(delete_roll);
			if(loc==NULL)
			{
				
			}
			else
			{
				if(loc==start)
				{
					start=NULL;
					tail==NULL;
					free(loc);
				}
				else
				{
					temp=loc;
					ptr=temp->previous;
					ptr->next=temp->next;
					temp1=loc->next;
					temp1->previous=ptr;
					free(temp);
				}
			}
	  }
	  
					
	  
	  void display_data_at_beginning()
	  {
		  struct class_record *loc;
	
		if(start==NULL)
		{
			printf("\nUNDERFLOW");
		}
		else 
		{
			loc=start;
			printf("\nThe data in the beginning is>>");
			title_row();
			display_data_on_prompt(loc);
			
		}
	  
	  }
	  
	  void display_data_at_end()
	  {
		 struct class_record *loc;
	
		if(start==NULL)
		{
			printf("\nUNDERFLOW");
		}
		else 
		{
			loc=tail;
			title_row(); 
			display_data_on_prompt(loc);
			
	    }
	  }
	  void display_data_at_num()											
	  {
		 int display_roll;
		 struct class_record *loc,*ptr;
		  
		    printf("\nEnter the data roll number to be display>>");
			scanf("%d",display_roll);
			loc=linear_search_for_delete_insert(display_roll);
			if(loc==NULL)
			{
				
			}
			else
			{
				ptr=loc;
				title_row();
				display_data_on_prompt(ptr);
			}
	  }
	  
	  void linear_search_in_list()											/*DEFINATION OF FUNCTION FOR LINEAR SEARCH*/
	  {
		  struct class_record *ptr,*loc;
		  int element;
		  int flag=0;
		  
		  printf("\nEnter roll number to be searched in the data>>\t");
		  scanf("%d",&element);
		  count=0;
		  if(start==NULL)
		  {
			  printf("\n**SORRY THERE IS NO DATA");
		  }
		  else if(start->next==NULL)
		  {
			  loc=start;
			  if(loc->roll_no==element)
			  {
				  printf("\nThe element is found at position>>>>%d%",count+1);
			  }
			  else
			  {
				  printf("\n**The roll number is not in the list");
			  }
		  }
		  else
		  {
			  loc=start;
			  while(loc->next!=NULL)
			  {
				 if(loc->roll_no==element)
				 {
					 break;flag=1;
				 }
				 count++;
				 loc=loc->next;
			  }
			  if(loc->roll_no==element)
			  {
				  flag=1;
			  }
			  if(flag==1)
			  {
				  printf("\nThe element is found at position>>>>%d%",count+1);
			  }
			  
			  else
			  {
				  printf("\n**This roll number is not in the list");
			  }
			  
		  }
	  }
	  

	  void sorting_of_data()												/*DEFINATION OF FUNCTION FOR SORTING ACCORDING TO ROLL NUMBER*/
	  {
		  struct class_record *loc,*preptr;
		  struct class_record *temp,*ptr;
		  if((start==NULL)||(start->next==NULL))
		  {
			  printf("\nUNDERFLOW");
		  }
		  else
		  {
			  for(int i=0;i<count_sort;i++)
			  {
				  loc=start;
				  while(loc->next!=NULL)
				  {
					  
					  if(loc->roll_no>loc->next->roll_no)
					  {
						  if(loc==start)
						  {
							  temp=loc;
							  ptr=loc->next->next;
							  start=loc->next;
							  start->next=temp;
							  temp->next=ptr;
						  }
						  else{
							  temp=loc;
							  ptr=loc->next->next;
							  loc->next=ptr;
							  loc->next->next=loc;
							  preptr->next=loc->next;
						  }
					  }
					  preptr=loc;
					  loc=loc->next;
				  }
			  }
		  }
	  }
/********************************************************************************************************************************************************/	  
	  void display_in_file()												/*DEFINATION OF FUNCTION FOR INITIAL DISPLAY IN FILE*/
	  {
		  printf("\n\t\t\t\t\t\t\tPROGRAM FOR FILE HANDLING OF STUDENT RECORD");
		  fprintf(outp,"\n\t\t\t\t\t\t\tPROGRAM FOR FILE HANDLING OF STUDENT RECORD");
		  printf("\n\t\t\t\t\t\t\t*******************************************");
		  fprintf(outp,"\n\t\t\t\t\t\t\t*******************************************");
		  printf("\n\t\t\t\t\t\t\t***********************DEVELOPER-AMAN DUBEY\n\n");
		  fprintf(outp,"\n\t\t\t\t\t\t\t***********************DEVELOPER-AMAN DUBEY\n\n");
		  printf("\n\t\t\t\t\t\t\t**  ** ** ******   ********");
		  printf("\n\t\t\t\t\t\t\t** **  ** ******   ********");
		  printf("\n\t\t\t\t\t\t\t***    ** ***         **");
		  printf("\n\t\t\t\t\t\t\t** **  ** ******      **");
		  printf("\n\t\t\t\t\t\t\t**  ** ** ******      **GROUP OF INSTITUTION");
		  if(outp == NULL)
		  {
		  fprintf(outp,"\n\t\t\t\t\t\t\t**  ** ** ******   ********");
		  fprintf(outp,"\n\t\t\t\t\t\t\t** **  ** ******   ********");
		  fprintf(outp,"\n\t\t\t\t\t\t\t***    ** ***         **");
		  fprintf(outp,"\n\t\t\t\t\t\t\t** **  ** ******      **");
		  fprintf(outp,"\n\t\t\t\t\t\t\t**  ** ** ******      **GROUP OF INSTITUTION");
		  
		  title_row_file();
		  }
	  
	  }
		  void title_row_file()
		  {
			  
		  fprintf(outp,"\n\n\n\t\t\tRoll number\t\t\tName\t\t\tSemester\t\t\tYear\t\t\tDepartment");
		  fprintf(outp,"\n\t\t\t============\t\t\t====\t\t\t========\t\t\t=====\t\t\t=========");

		  }
	  
/*********************************************************************************************************************************************************/
	  void enter_choice()													/*DEFINATION OF FUNCTION TO TAKE CHOICE FROM USER*/
	  {
		  int choice;
		  
	  printf("\n\n1>>Insert data\t\t\t2>>Delete data\t\t\t3>>Display data\t\t\t4>>>Search data\t\t\t5>>Sort data\t\t6>>Exit");
	  c:
	  
	  printf("\n\nEnter operation>>>>");
	  scanf("%d",&choice);
	   
	  switch(choice)
	  {
		  case 1	:	choice_insert_data();break;
		  case 2	:	choice_delete_data();break;
		  case 3	:	choice_display_data();break;
		  case 4	:	linear_search_in_list();break;
		  case 5	:	sorting_of_data();update_data_in_file();break;
		  case 6	:	fclose(outp);update_data_in_file();exit (0);
		  default	:	printf("\nWRONG OPERATION");goto c;
	  }
	  
	  }
	  
	  
	  void choice_insert_data()											/*FUNCTION TO TAKE CHOICE FOR TYPE OF INSERT*/
	  {
		int choice_insert;
		struct class_record *loc;
		++count_sort;
		
		c1:
		printf("\n\n1>Insert at beginning\n\n2>Insert at end\n\n3>Insert after Roll number\n>>>>");
		scanf("%d",&choice_insert);
		
		
		switch(choice_insert)
		{
			case 1	:	loc=enter_data();insert_data_at_beginning(loc);break;
			case 2	:	loc=enter_data();insert_data_at_end(loc);break;
			case 3	:	loc=enter_data();insert_data_after_num(loc);break;
			default	:	printf("\nWRONG OPERATION");goto c1;
		}
		
	  }
	  void choice_delete_data()											/*FUNCTION TO TAKE CHOICE FOR TYPE OF DELETE*/
	  {
		int choice_delete;
		--count_sort;
		c2:
		printf("\n\n\t\t\t\t1>delete at beginning\n\t\t\t\t2>delete at end\n\t\t\t\t3>delete after Roll number\n\t\t\t\t>>>>");
		scanf("%d",&choice_delete);
		switch(choice_delete)
		{
			case 1	:	delete_data_at_beginning();update_data_in_file();break;
			case 2	:	delete_data_at_end();update_data_in_file();break;
			case 3	:	delete_data_at_num();update_data_in_file();break;
			default	:	printf("\nWRONG OPERATION");goto c2;
		}
		  
	  }
	  void choice_display_data()										/*FUNCTION TO TAKE CHOICE FOR TYPE OF DISPLAY*/
	  {
		 int choice_display;
		c2:
		printf("\n\n\t\t\t\t\t\t\t\t1>display at beginning\n\t\t\t\t\t\t\t\t2>display at end\n\t\t\t\t\t\t\t\t3>display Roll number\n");
		printf("\t\t\t\t\t\t\t\t4>display all data\n");
		printf("\t\t\t\t\t\t\t\t>>>>");
		scanf("%d",&choice_display);
		
		switch(choice_display)
		{
			case 1	:	display_data_at_beginning();break;
			case 2	:	display_data_at_end();break;
			case 3	:	display_data_at_num();break;
			case 4	:	display_all();break;
			default	:	printf("\nWRONG OPERATION");goto c2;
		} 
	  }
	  
/********************************************************************************************************************************************************/	  
	  struct class_record* enter_data()
	  {
		  int i=0,j=0;
		  int roll;
		  char n[20];
		  int s;
		  int y;
		  char dept[5]; 
		  struct class_record *ptr;
		  
		  printf("\nEnter\nroll number\t>>");
		  scanf("%d",&roll);
		  printf("\nName\t\t>>");
		  scanf(" %[^\n]%*c",n);
		  printf("\nSemester\t>>");
		  scanf("%d",&s);
		  printf("\nYear\t\t>>");
		  scanf("%d",&y);
		  printf("\nDepartment\t>>");
		  scanf(" %[^\n]%*c",dept);
		  
		  ptr=(struct class_record*)malloc(sizeof(struct class_record));
		  ptr->roll_no=roll;
		  strcpy(ptr->name,n);
		  ptr->sem=s;
		  ptr->year=y;
		  strcpy(ptr->department,dept);
		  ptr->next=NULL;
		  ptr->previous=NULL; 
		  enter_data_in_files(ptr);
		  return ptr;
		  
	  }
	  void enter_data_in_files(struct class_record* ptr)
	  {
		  fprintf(outp,"\n\t\t\t\t%d",ptr->roll_no);
		  fprintf(outp,"\t\t\t%s",ptr->name);
		  fprintf(outp,"\t\t%d",ptr->sem);
		  fprintf(outp,"\t\t\t\t%d",ptr->year);
		  fprintf(outp,"\t\t\t%s",ptr->department); 
	  }
	  
	  struct class_record* linear_search_for_delete_insert(int element)					/*DEFINATION OF FUNCTION FOR LINEAR SEARCH FOR DELETE AND INSERT*/
	  {
		  struct class_record *ptr,*loc;
		  int flag=0;
		  
		  if(start==NULL)
		  {
			  printf("\n**SORRY THERE IS NO DATA");
			  return NULL;
			  
		  }
		  else if(start->next==NULL)
		  {
			  loc=start;
			  if(loc->roll_no==element)
			  {
				  return loc;
			  }
			  else
			  {
				  printf("\n**The roll number is not in the list");
				  return NULL;
			  }
		  }
		  else
		  {
			  loc=start;
			  while(loc->next!=NULL)
			  {
				 if(loc->roll_no==element)
				 {
					flag=1; break;
				 }
				 loc=loc->next;
			  }
			  if(flag==1)
			  {
				  return loc;
			  }
			  
			  else
			  {
				  
				  return NULL;
			  }
			  
		  }
	  }
	  
	  void display_data_on_prompt(struct class_record* x)						/*DECLARATION OF FUNCTION TO DISPLAY DATA ON PROMPT ONCE*/
	  {
		  printf("\n\t\t\t\t%d",x->roll_no);
		  printf("\t\t\t%s",x->name);
		  printf("\t\t%d",x->sem);
		  printf("\t\t\t%d",x->year);
		  printf("\t\t\t%s",x->department);
	  }
	  
	  void display_all()
	  {
		  struct class_record *loc;
		  if(start==NULL)
		  {
			  printf("\n**SORRY THERE IS NO DATA");
			  return ;
			  
		  }
		  else if(start->next==NULL) 
		  {
			  loc=start;
			  title_row();
			  display_data_on_prompt(loc);
		  }
		  else
		  {
			  loc=start;
			  title_row();
			  while(loc->next!=NULL)
			  {
				  display_data_on_prompt(loc);
				  loc=loc->next;
			  }
			  display_data_on_prompt(loc);
			  
		  }
	  }
	  void update_data_in_file()
	  {
		  struct class_record *loc;
		 if(start==NULL)
		  {
			  fprintf(outp,"\n**SORRY THERE IS NO DATA");
			  
			  
		  }
		  else if(start->next==NULL) 
		  {
			  fprintf(outp,"\n\n\t\t\t\t\t**************************UPDATED DATA IN LIST IS**************************\n");
			  loc=start;
			  title_row_file();
			  display_data_on_file(loc);
		  }
		  else
		  {
			  fprintf(outp,"\n\n\t\t\t\t\t**************************UPDATED DATA IN LIST IS**************************\n");
			  loc=start;
			  title_row_file();
			  while(loc->next!=NULL)
			  {
				  display_data_on_file(loc);
				  loc=loc->next;
			  }
			  display_data_on_file(loc);
			  
		  } 
	  }
	  void display_data_on_file(struct class_record* x)
	  {
		  fprintf(outp,"\n\t\t\t\t%d",x->roll_no);
		  fprintf(outp,"\t\t\t%s",x->name);
		  fprintf(outp,"\t\t%d",x->sem);
		  fprintf(outp,"\t\t\t%d",x->year);
		  fprintf(outp,"\t\t\t%s",x->department);
	  }
	  void title_row()
		  {
			  
		  printf("\n\n\n\t\t\tRoll number\t\t\tName\t\t\tSemester\t\t\tYear\t\t\tDepartment");
		  printf("\n\t\t\t============\t\t\t====\t\t\t========\t\t\t=====\t\t\t=========");

		  }