#include<bits/stdc++.h>
using namespace std;
int main()
{
		char c[40000];
		system("ls files >fname.txt");/*Assumed folder name is "files"  and saved all .txt files into a text file named fname.txt*/
		FILE *fp=fopen("fname.txt","r");/*open fname.txt and extracting data recursively one by one*/
	        while(fscanf(fp,"%s",c)!=EOF)
		    {
	        	FILE *fptr;
				char temp[500]="files/";/*for providing path of folder*/
				strcat(temp,c);
				fptr=fopen(temp,"r");
				if(fptr==NULL)
					cout<<"Sorry ..cannot open file."<<endl;
				else
					{
						int count=0;
						char ch[5000];
						while(fscanf(fptr,"%s",ch)!=EOF)
						{
							 count=0;
							 if(ch[0]=='+' && ch[1]=='9' && ch[2]=='1' && ch[3]=='-')/*comparing indian mobile number "+91-9..."*/
						    	{
									for(int i=4;i<=14;i++)/*checking valid 10 digit number*/
								 	{
								 		if(ch[4]=='0')
								 			break;
										if(int (ch[i])>=48 && int(ch[i])<=57)/*checking if ch[] contains digit or not by ASCII value*/
											count++;
									}
								if(count==10)
									cout<<ch<<endl;
								}
						}
					}
				fclose(fptr);
			}
			fclose(fp);
 	    return 0;
}
