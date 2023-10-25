#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//structure for election schedule
struct election
{
	int date;
	char r[50];
};

//structure for candidate list
struct candidate_list
{
	int sn;
	char name[14];
	char party[14];
	char candidacy[14];
};

//structure for voter list
struct voter_list
{
	int sn;
	char fname[10],lname[15];
	char dob[15];
	char address[15];
	char pass[15];
};

//structure for votecount
struct vote_count
{
	int sn;
	char voter_fname[10];
	char voter_lname[15];
	char candidate[15];
	char party[10];
	char candidacy[15];
};

//functions declarations
void election_schedule();
void show_schedule();
void candidate_list();
void add_candidate();
void update_candidate();
void delete_candidate();
void show_candidate();
void add_voter();
void modify_voter();
void update_voter();
void delete_voter();
void change_pass();
void search_voter();
void cast_vote();
void result();
//main function
void main()
{
	int a;
	while(1)
	{
	system("CLS");
	printf("\t\t\tVOTING SYSTEM\t\t\n\n");
	printf("\nSelect the task to do:\n\n");
	printf("1.  Create the election schedule(admin only)\n");
	printf("2.  Modify candidate list(admin only)\n");
	printf("3.  Register as voter\n");
	printf("4.  Change voter details\n");
	printf("5.  Search for voter details\n");
	printf("6.  Cast vote\n");
	printf("7.  Show election schedule\n");
	printf("8.  Show candidate list\n");
	printf("9.  Show Voting Result\n");
	printf("10. Exit");
	printf("\nEnter Your choice\t");
	scanf("%d",&a);
	printf("\n");
	switch(a)
	{
		case 1:
			election_schedule();     //function calling
			break;

		case 2:
            candidate_list();
			break;

		case 3:
			add_voter();
			break;

		case 4:
			modify_voter();
			break;

		case 5:
            search_voter();
			break;

		case 6:
        	cast_vote();
			break;

        case 7:
			show_schedule();
            break;

        case 8:
			show_candidate();
        	break;

		case 9:
			result();
			break;
			
		case 10:
			break;

		default:
		printf("Invalid input\n");
	}
	if(a==10)
	{
		break;
	}
    }
}
void election_schedule()
{
	struct election row[77];
	system("CLS");
	int v,u;
	char a[50],b[50],c[50]="ADMIN",d[50]="abc";
	retry:
	printf("Enter Admin name \t");
	scanf("%s",a);
	printf("Enter Admin password \t");
	scanf("%s",b);
	v=strcmp(strupr(a),c);
	u=strcmp(b,d);
	if(v==0 && u==0)
	{
		printf("\nAdmin Verified successfully!\n");
		FILE *f;
		int a,n=0,c;
		f=fopen("schedule.txt","w");
		fprintf(f, " ----- -------------------- -------------------------- \n");
		fprintf(f,"|%-5s|%-20s|%-26s|\n","S.N.","Constituency","Date of election(yyyymmdd)");
		fprintf(f, " ----- -------------------- -------------------------- \n");
	    printf("Enter the data for election schedule\n");
		while(1)
		{
			printf("\nEnter Constituency:\t\t\t");
			scanf("%s",&row[n].r);
			printf("Enter Date of election in B.S.(yyyymmdd):\t");
			scanf("%ld",&row[n].date);
			fprintf(f,"|%-5d|%-20s|%-26ld|\n",n+1,row[n].r,row[n].date);
			printf("\nEnter 1 to add another Constituency or 0 to stop\t");
			scanf("%d",&c);
			if(c==0)
			{
				break;
			}
			n=n+1;
			a=n;
		}
		fprintf(f, " ----- -------------------- -------------------------- \n");
		fclose(f);
		system("CLS");
		printf("The entered data is stored in txt file as shown below\n\n");
		char row[100];
	    f=fopen("schedule.txt","r");
	    while(fgets(row,sizeof(row),f))
	    {
		printf("%s",row);
	    }
	    fclose(f);
	    }
	    else
	    {
		printf("Incorrect username or password\nPlease try again\n\n");
		goto retry;
	    }
	    getch();
}
void show_schedule()
{
	system("CLS");
	char row[100];
	FILE *f;
	f=fopen("schedule.txt","r");
	while(fgets(row,sizeof(row),f))
	{
		printf("%s",row);
	}
	fclose(f);
	getch();
}
void candidate_list()
{
	struct candidate_list candidate[1000];
		system("CLS");
	int v,u;
	char a[50],b[50],c[50]="ADMIN",d[50]="abc";
	try_again:
	printf("Enter Admin name \t");
	scanf("%s",a);  // gets(a); can also be used
	printf("Enter Admin password \t");
	scanf("%s",b);
	v=strcmp(strupr(a),c);
	u=strcmp(b,d);
	if(v==0 && u==0)
	{
		printf("\nAdmin Verified successfully!\n");
		int c;
		while(1)
		{
		system("CLS");
		printf("Select which task to do:\n\n");
		printf("1. Add a candidate\n");
		printf("2. Update a candidate\n");
		printf("3. Delete a candidate\n");
		printf("4. Show existing candidate\n");
		printf("5. Exit\n");
		printf("\nEnter your choice\t");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				add_candidate();         //function calling
				break;

			case 2:
				update_candidate();
				break;

			case 3:
				delete_candidate();
				break;

			case 4:
				show_candidate();
				break;

			case 5:
				break;

			default:
		    printf("Invalid input\n");
		}
		if(c==5)
		{
			break;
		}
	    }
	}
	else
	{
		printf("\nIncorrect username or password\nPlease try again\n\n");
		goto try_again;
	}
}
void add_candidate()
{
	struct candidate_list candidate[1000];
	system("CLS");
    FILE *fc;
    int p,G=0,n=0,lnum=0;
    char line[100];
    again:
    fc=fopen("candidatelist.txt","r");
	if(fc == NULL)
	{
	fc=fopen("candidatelist.txt","w");
	fprintf(fc,"---- -------------- -------------- -------------- \n");
	fprintf(fc,"%-4s|%-14s|%-14s|%-14s|\n","S.N.","Name of","Political","Candidacy");
	fprintf(fc,"%-4s|%-14s|%-14s|%-14s|\n","    ","Candidate","party","From");
	fprintf(fc,"---- -------------- -------------- -------------- \n");
	fclose(fc);
	goto again;
    }
    while(fgets(line, sizeof(line),fc))
    {
    lnum++;
    }
    fclose(fc);
    G=lnum-4;
    fc=fopen("candidatelist.txt","a");
    while(1)
    {
        printf("\nEnter name of candidate:\t\t");
		scanf("%s",candidate[G].name);
		printf("Enter political party:\t\t");
		scanf("%s",candidate[G].party);
	    printf("Enter candidacy from:\t\t");
		scanf("%s",candidate[G].candidacy);
		fprintf(fc,"%-5d%-15s%-15s%-15s\n",G+1,candidate[G].name,candidate[G].party,candidate[G].candidacy);
		G=G+1;
        printf("\nEnter 1 to add another candidate or 0 to stop\t");
        scanf("%d",&p);
        if(p==0)
        {
        	break;
		}
	}
	fclose(fc);
	printf("\n\nData added successfully\n\n");
    getch();
}
void update_candidate()
{
	struct candidate_list candidate[1000];
	system("CLS");
	int sn,x=1,lnum=1;
	char line[100];
	FILE *fc;
	fc=fopen("candidatelist.txt","r");
	while(fgets(line, sizeof(line),fc))
    {
    	printf("%s",line);
        x++;
    }
    fclose(fc);
    printf("\n\nEnter S.N. of candidate to be updated\t");
    scanf("%d",&sn);
    printf("\nEnter name of candidate:\t");
    scanf("%s",candidate[sn].name);
    printf("\nEnter political party:\t");
    scanf("%s",candidate[sn].party);
    printf("\nEnter candidacy from:\t");
    scanf("%s",candidate[sn].candidacy);
    FILE *ft;
    int num,G=0;
    char c1,c2;
    fc=fopen("candidatelist.txt","r");
    ft=fopen("temp.txt","w");
    while(fgets(line,sizeof(line),fc))
    {
    if(lnum==sn+4)
    {
    fprintf(ft,"%-5d%-15s%-15s%-15s\n",sn,candidate[sn].name,candidate[sn].party,candidate[sn].candidacy);
    printf("\nCandidate updated successfully");
	}
	else
	{
		fputs(line,ft);
	}
	lnum++;
    }
    fclose(fc);
    fclose(ft);
    remove("candidatelist.txt");
    rename("temp.txt","candidatelist.txt");
    getch();
}
void delete_candidate()
{
	struct candidate_list candidate[1000];
	system("CLS");
	int sn,x=1,lnum=1,num,G=1;
	char line[100],ch;
	FILE *fc,*ft;
	fc=fopen("candidatelist.txt","r");
	while(fgets(line, sizeof(line),fc))
    {
    	printf("%s",line);
        x++;
    }
    fclose(fc);
    printf("\n\nEnter S.N. of candidate to be deleted\t");
    scanf("%d",&sn);
    sn=sn+4;
    fc=fopen("candidatelist.txt","r");
    ft=fopen("temp.txt","w");
    while(lnum<x)
    {
    if(lnum<5)
    {
    fgets(line,sizeof(line),fc);
		fputs(line,ft);
	}
	else if(lnum==sn)
	{
		fgets(line,sizeof(line),fc);
		lnum++;
		continue;
	}
	else
	{
		fgets(line,sizeof(line),fc);
		memmove(line,line+4,strlen(line)-4+1);
		fprintf(ft,"%-4d%s",G,line);
		G++;
	}
	lnum++;
    }
    fclose(fc);
    fclose(ft);
    remove("candidatelist.txt");
    rename("temp.txt","candidatelist.txt");
    printf("\nCandidate deleted successfully");
    getch();
}
void show_candidate()
{
	struct candidate_list candidate[1000];
	system("CLS");
	FILE *fc;
	int lnum=1;
	char line[100];
	again:
	fc=fopen("candidatelist.txt","r");
	if(fc == NULL)
	{
	fc=fopen("candidatelist.txt","w");
	fprintf(fc,"---- -------------- -------------- -------------- \n");
	fprintf(fc,"%-4s|%-14s|%-14s|%-14s|\n","S.N.","Name of","Political","Candidacy");
	fprintf(fc,"%-4s|%-14s|%-14s|%-14s|\n","    ","Candidate","party","From");
	fprintf(fc,"---- -------------- -------------- -------------- \n");
	fclose(fc);
	goto again;
    }
	while(fgets(line, sizeof(line),fc))
    {
    	printf("%s",line);
        lnum++;
    }
    fclose(fc);
    getch();
 }
 void add_voter()
{
	struct voter_list voter[1000];
 	system("CLS");
 	int snum,a=0,age,y,m,d;
 	char ms[4],ds[4],s[2]="/",vo[100];
 	FILE *fv;
 	voter:
 	fv=fopen("voterlist.txt","r");
 	if(fv==NULL)
 	{
 		fv=fopen("voterlist.txt","w");
 		fprintf(fv," ----------- ------------------------ -------------- -------------- -----------\n");
 		fprintf(fv,"|%-11s|%10s %-14s|%-14s|%-14s|%-11s|\n","Voter SNO","Name of","Voter","Date of Birth","Address","Password");
 		fprintf(fv," ----------- ------------------------ -------------- -------------- -----------\n");
 		fclose(fv);
 		goto voter;
	}
	srand(time(0));
	snum=(rand()%1000)+1;
	fv=fopen("voterlist.txt","a");
	printf("Enter your Date Of Birth in B.S.\n");
	year:
	printf("Enter year of birth:\t\t");
	scanf("%d",&y);
	if(y>=1900 && y<=9999)
	{
	}
	else
	{
		
        printf("Year is invalid.\n");
		goto year;
	}
	month:
	printf("Enter month of birth:\t\t");
	scanf("%d",&m);
	if(m>=1 && m<=12)
	{	
	}
	else
	{
		printf("month is invalid.\n");
		goto month;
	}
	day:
	printf("Enter day of birth:\t\t");
    scanf("%d",&d);
    if((d>=1 && d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12))
	{
	}
    else if((d>=1 && d<=30) && (m==4 || m==6 || m==9 || m==11))
    {
	}
    else if((d>=1 && d<=28) && (m==2))
    {
	}
    else if(d==29 && m==2 && (y%400==0 ||(y%4==0 && y%100!=0)))
    {
	}
    else
    {
    printf("Day is invalid.\n");
    goto day;
    }
    age=2079-y;
	if(age>18)
	{
    sprintf(voter[a].dob,"%d",y);
    sprintf(ms,"%d",m);
    sprintf(ds,"%d",d);
    strcat(voter[a].dob,s);
    strcat(voter[a].dob,ms);
    strcat(voter[a].dob,s);
    strcat(voter[a].dob,ds);
	printf("Enter first name:\t\t");
	scanf("%s",voter[a].fname);
	printf("Enter last name:\t\t");
	scanf("%s",voter[a].lname);
	printf("Enter address:\t\t");
	scanf("%s",voter[a].address);
	printf("Create password:\t\t");
	scanf("%s",voter[a].pass);
	fprintf(fv,"%12d%10s %-15s%-15s%-15s%-11s\n",snum,voter[a].fname,voter[a].lname,voter[a].dob,voter[a].address,voter[a].pass);
	printf("\n\nYour Voter SNO is:\t%d\n(Do remember for casting vote or to make changes to your registration)\n",snum);
	a++;
    }
    else
    {
    	printf("You are ineligible to vote!\n");
	}
    fclose(fv);
    printf("\nVoter Registered Successfully");
    getch();
 }
 void modify_voter()
{
	struct voter_list voter[1000];
 	system("CLS");
    int c;
    while(1)
    {
    system("CLS");
	printf("\nSelect the task to do:\n\n");
	printf("1.  Update voter details\n");
	printf("2.  Delete registered voter\n");
	printf("3.  Change voter password\n");
	printf("4.  Exit\n");
    printf("Enter your choice\t");
    scanf("%d",&c);
    switch(c)
    {
    	case 1:
    		update_voter();
    		break;

    	case 2:
    		delete_voter();
    		break;

    	case 3:
    		change_pass();
    		break;

    	case 4:
    		break;

    	default:
		printf("Invalid input\n");

	}
	if(c==4)
	{
		break;
	}
    }
 }
void update_voter()
{
	struct voter_list voter[1000];
	int sn,c=0,lno=1,lcount=0,g=0,y,m,d;
	char pass[15],line[150],ms[2],ds[2],s[2]="/";
	system("CLS");
	printf("Enter your Voter SNO:\t");
	scanf("%d",&sn);
	printf("Enter your password:\t");
	scanf("%s",pass);
	FILE *fv,*ft;
	fv=fopen("voterlist.txt","r");
	while(fgets(line,sizeof(line),fv))
	{
		lcount++;
	}
	fclose(fv);
	fv=fopen("voterlist.txt","r");
	ft=fopen("temp.txt","w");
	while(lno<=lcount)
	{
		if(lno<4)
		{
			fgets(line,sizeof(line),fv);
			fprintf(ft,"%s",line);
		}
		else
		{
			fscanf(fv,"%d%s%s%s%s%s",&voter[g].sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
			if(sn==voter[g].sn && strcmp(pass,voter[g].pass)==0)
			{
				printf("\nEnter new details\n\n");
				printf("Enter your Date Of Birth in B.S.\n");
              	printf("Enter year of birth:\t\t");
	            scanf("%d",&y);
	            printf("Enter month of birth:\t\t");
	            scanf("%d",&m);
	            printf("Enter day of birth:\t\t");
                scanf("%d",&d);
                sprintf(voter[g].dob,"%d",y);
                sprintf(ms,"%d",m);
                sprintf(ds,"%d",d);
                strcat(voter[g].dob,s);
                strcat(voter[g].dob,ms);
                strcat(voter[g].dob,s);
                strcat(voter[g].dob,ds);
	            printf("Enter first name:\t\t");
	            scanf("%s",voter[g].fname);
	            printf("Enter last name:\t\t");
	            scanf("%s",voter[g].lname);
	            printf("Enter address:\t\t");
	            scanf("%s",voter[g].address);
	            fprintf(ft,"%12d%10s %-15s%-15s%-15s%-11s\n",sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
	            c=c+1;
			}
			else
			{
			    fprintf(ft,"%12d%10s %-15s%-15s%-15s%-11s\n",voter[g].sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
			}
			g++;
		}
		lno++;
	}
	fclose(fv);
	fclose(ft);
	if(c==1)
	{
		printf("\nYour details are updated successfully\n");
	}
	else
	{
		printf("\nVoter not found enter correct SNO and password");
	}
	remove("voterlist.txt");
	rename("temp.txt","voterlist.txt");
	getch();
}
void delete_voter()
{
	struct voter_list voter[1000];
	int sn,c=0,lno=1,lcount=0,g=0;
	char pass[15],line[150];
	system("CLS");
	printf("Enter your Voter SNO:\t");
	scanf("%d",&sn);
	printf("Enter your password:\t");
	scanf("%s",pass);
	FILE *fv,*ft;
	fv=fopen("voterlist.txt","r");
	while(fgets(line,sizeof(line),fv))
	{
		lcount++;
	}
	fclose(fv);
	fv=fopen("voterlist.txt","r");
	ft=fopen("temp.txt","w");
	while(lno<=lcount)
	{
		if(lno<4)
		{
			fgets(line,sizeof(line),fv);
			fprintf(ft,"%s",line);
		}
		else
		{
			fscanf(fv,"%d%s%s%s%s%s",&voter[g].sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
			if(sn==voter[g].sn && strcmp(pass,voter[g].pass)==0)
			{
				g++;
				c=c+1;
			}
			else
			{
			    fprintf(ft,"%12d%10s %-15s%-15s%-15s%-11s\n",voter[g].sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
			}
			g++;
		}
		lno++;
	}
	fclose(fv);
	fclose(ft);
	if(c==1)
	{
		printf("\nYour registration is successfully removed\n");
	}
	else
	{
		printf("\nVoter not found enter correct SNO and password");
	}
	remove("voterlist.txt");
	rename("temp.txt","voterlist.txt");
	getch();
}
void change_pass()
{
	struct voter_list voter[1000];
	int sn,c=0,lno=1,lcount=0,g=0;
	char pass[15],line[150];
	system("CLS");
	printf("Enter your Voter SNO:\t");
	scanf("%d",&sn);
	printf("Enter your password:\t");
	scanf("%s",pass);
	FILE *fv,*ft;
	fv=fopen("voterlist.txt","r");
	while(fgets(line,sizeof(line),fv))
	{
		lcount++;
	}
	fclose(fv);
	fv=fopen("voterlist.txt","r");
	ft=fopen("temp.txt","w");
	while(lno<=lcount)
	{
		if(lno<4)
		{
			fgets(line,sizeof(line),fv);
			fprintf(ft,"%s",line);
		}
		else
		{
			fscanf(fv,"%d%s%s%s%s%s",&voter[g].sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
			if(sn==voter[g].sn && strcmp(pass,voter[g].pass)==0)
			{
				printf("Create new password:");
				scanf("%s",voter[g].pass);
	            fprintf(ft,"%12d%10s %-15s%-15s%-15s%-11s\n",sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
	            c=c+1;
			}
			else
			{
			    fprintf(ft,"%12d%10s %-15s%-15s%-15s%-11s\n",voter[g].sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
			}
			g++;
		}
		lno++;
	}
	if(c==1)
	{
		printf("\nPass changed successfully\n");
	}
	else
	{
		printf("\nVoter not found enter correct SNO and password");
	}
	fclose(fv);
	fclose(ft);
	remove("voterlist.txt");
	rename("temp.txt","voterlist.txt");
	getch();
}
void search_voter()
{
	struct voter_list voter[1000];
    system("CLS");
	int sn,lno=1,lcount=0,g=0,x=0;
	char line[150];
	printf("Enter your Voter SNO:\t");
	scanf("%d",&sn);
	FILE *fv;
	fv=fopen("voterlist.txt","r");
	while(fgets(line,sizeof(line),fv))
	{
		lcount++;
	}
	fclose(fv);
	fv=fopen("voterlist.txt","r");
	while(lno<=lcount)
	{
		if(lno<4)
		{
			fgets(line,sizeof(line),fv);
		}
		else
		{
			fscanf(fv,"%d%s%s%s%s%s",&voter[g].sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
			if(sn==voter[g].sn)
			{
			    printf("\n\nVoter SNO:\t\t\t%d\n",voter[g].sn);
			    printf("Voter Name:\t\t%10s %-14s\n",voter[g].fname,voter[g].lname);
			    printf("Voter Date of birth:\t\t%s\n",voter[g].dob);
			    printf("Voter address:\t\t\t%s\n",voter[g].address);
			    x=x+1;
			    break;
			}
			g++;
		}
		lno++;
	}
	fclose(fv);
	if(x!=1)
	{
		printf("\nVoter Not Found\n");
	}
    getch();
}
void cast_vote()
{
	struct candidate_list candidate[1000];
	struct voter_list voter[1000];
	struct vote_count count[100];
	system("CLS");
	int sno,sn,lno,i,lc,c,lcount,g,a,x,check;
	char pass[15],line[150];
	FILE *fv,*ft,*fc,*fvc;
	retry:
	lno=1,lc=0,c=1,lcount=0,g=0,a=0,x=0;
	printf("Enter your Voter SNO:\t");
	scanf("%d",&sno);
	printf("Enter your password:\t");
	scanf("%s",pass);
	fv=fopen("voterlist.txt","r");
	while(fgets(line,sizeof(line),fv))
	{
		lcount++;
	}
	fclose(fv);
	fv=fopen("voterlist.txt","r");
	ft=fopen("temp.txt","w");
	while(lno<=lcount)
	{
		if(lno<4)
		{
			fgets(line,sizeof(line),fv);
			fprintf(ft,"%s",line);
		}
		else
		{
			fscanf(fv,"%d%s%s%s%s%s",&voter[g].sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
			if(sno==voter[g].sn && strcmp(pass,voter[g].pass)==0)
			{
				system("CLS");
				printf("Candidates in this election are:\n\n");
				fc=fopen("candidatelist.txt","r");
				while(fgets(line,sizeof(line),fc))
				{
					lc++;
				}
				fclose(fc);
				fc=fopen("candidatelist.txt","r");
				while(c<=lc)
				{
					if(c<5)
					{
						fgets(line,sizeof(line),fc);
						printf("%s",line);
					}
					else
					{
						fscanf(fc,"%d%s%s%s",&candidate[a].sn,candidate[a].name,candidate[a].party,candidate[a].candidacy);
							printf("%-5d%-15s%-15s%-15s\n",candidate[a].sn,candidate[a].name,candidate[a].party,candidate[a].candidacy);
						a++;
					}
					c++;
				}
				fclose(fc);
				printf("\n\nEnter S.N. of the candidate you want to vote:\t");
				scanf("%d",&sn);
				fvc=fopen("votecount.txt","r");
				if(fvc==NULL)
				{
				fclose(fvc);
				fvc=fopen("votecount.txt","w");
				fprintf(fvc,"VOTING DETAILS:\n");
				fprintf(fvc," -------------------------- --------------- ---------- ---------------\n");
				fprintf(fvc,"|%10s %-15s|%-15s|%-10s|%-15s|\n","Voter","name","Cadidate voted","Party","Candidacy From");
				fprintf(fvc," -------------------------- --------------- ---------- ---------------\n");
				fclose(fvc);
				goto conti;
				}
			    fclose(fvc);
				conti:
				fvc=fopen("votecount.txt","a");
				for(i=0;i<=a;i++)
				{
					if(candidate[i].sn==sn)
					{
						fprintf(fvc,"%12s %-15s%-16s%-11s%-16s\n",voter[g].fname,voter[g].lname,candidate[i].name,candidate[i].party,candidate[i].candidacy);
					}
				}
				fclose(fvc);
				x=x+1;
			}
			else
			{
			    fprintf(ft,"%12d%10s %-15s%-15s%-15s%-11s\n",voter[g].sn,voter[g].fname,voter[g].lname,voter[g].dob,voter[g].address,voter[g].pass);
			}
			g++;
		}
		lno++;
	}
	fclose(fv);
	fclose(ft);
	if(x==1)
	{
        printf("Candidate Voted successfully\n\n");
        printf("Your registration is now removed as voting is done");
	}
	else
	{
		printf("\nVoter not found enter correct SNO and password\n\n");
		goto retry;
	}
	remove("voterlist.txt");
	rename("temp.txt","voterlist.txt");
	getch();
}
void result()
{
	struct candidate_list candidate[1000];
	struct vote_count count[100];
	system("CLS");
	int i,j,c=0,a=0,lc=1,lnum,lcount,g,win;
	char line[100],row[100],winner[15];
	FILE *fc,*fvc;
	fc=fopen("candidatelist.txt","r");
	while(fgets(line,sizeof(line),fc))
	{
	    c++;	//reads number of lines in this file
	}
	fclose(fc);
	c=c-4;      //delete number of heading lines to indicate number of candidates
	int votecount[c];
	c=c+4;
	fc=fopen("candidatelist.txt","r");
	while(lc<=c)
	{
		if(lc<5)
		{
			fgets(line,sizeof(line),fc);
		}
		else
		{
			votecount[a]=0;
			fscanf(fc,"%d%s%s%s",&candidate[a].sn,candidate[a].name,candidate[a].party,candidate[a].candidacy);
			fvc=fopen("votecount.txt","r");
			lnum=0;
	        while(fgets(row,sizeof(row),fvc))
	        {
	            lnum++;	//reads number of lines in this file
	        }
	        fclose(fvc);
			fvc=fopen("votecount.txt","r");
			lcount=1;
			g=0;
			while(lcount<=lnum)
			{
				if(lcount<5)
				{
					fgets(row,sizeof(row),fvc);
				}
				else
				{
					fscanf(fvc,"%s%s%s%s%s",count[g].voter_fname,count[g].voter_lname,count[g].candidate,count[g].party,count[g].candidacy);
					if(strcmp(candidate[a].name,count[g].candidate)==0 && strcmp(candidate[a].candidacy,count[g].candidacy)==0)
					{
						votecount[a]=votecount[a]+1;
					}
					g++;
				}
				lcount++;
			}
			fclose(fvc);
			a++;
		}
		lc++;
	}
	fclose(fc);
	printf("Voting result\n\n");
	printf(" --------------- --------------- \n");
	printf("|%-15s|%-15s|\n","Candidate","No. of votes");
	printf(" --------------- --------------- \n");
	for(i=0;i<a;i++)
	{
			printf("|%-15s|%-15d|\n",candidate[i].name,votecount[i]);
	}
	printf(" --------------- --------------- \n\n");
	for(i=0;i<a;i++)
	{
		for(j=i+1;j<a;j++)
		{
		if(votecount[i]<votecount[j])
		{
			win=votecount[i];
			votecount[i]=votecount[j];
			votecount[j]=win;
			sprintf(winner,"%s",candidate[i].name);
			sprintf(candidate[i].name,"%s",candidate[j].name);
			sprintf(candidate[j].name,"%s",winner);
		}
	    }
	}
	win=votecount[0];
	sprintf(winner,"%s",candidate[0].name);
	printf("\n\n%s has won the election with %d votes",winner,win);
	getch();
}
