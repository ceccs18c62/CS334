#include<stdio.h>
#include<string.h>

void main(){
    int n,s,key,i,f=0;
    char name[50],sub[50],ch,word[50],roll[10];
    FILE *fptr;
    fptr=fopen("record.txt","w");
    if (fptr==NULL)
    {
        printf("this file is empty\n");
    }
    printf("enter the no. of student\n");
    scanf("%d",&n);
    fprintf(fptr,"%s\t%s\t%s\n","Name","Rollno","subject");
    for(i=0;i<n;i++)
    {
        printf("Enter the name of %d student\n",i+1);
        scanf("%s",name);

        printf("Enter the roll no.\n");
        scanf("%s",roll);

        printf("Enter the subject\n");
        scanf("%s",sub);

        fprintf(fptr,"%s\t%s\t%s\n",name,roll,sub);
    }
    fclose(fptr);
    
    
    while (f==0)
    {   
        printf("Selct 1-display 2-search\n");
        scanf("%d",&s);
        if(s==1){
            fptr=fopen("record.txt","r");
            while ((ch=fgetc(fptr))!=EOF)
            {
                printf("%c",ch);
            }
            fclose(fptr);
        }
        
        else if(s==2){
        printf("Enter the roll no. of the student\n");
            scanf("%d",&key);
            fptr=fopen("record.txt","r");
            if (fptr==NULL)
            {
                printf("cannot open\n");
                
            }
            else
            {
                fscanf(fptr,"%s%s%s",name,roll,sub);  
                while (fscanf(fptr, "%s%s%s", name,roll,sub) != EOF)
                {
                if(key==atoi(roll))
                {
                    printf("%s\t%s\t%s\n",name,roll,sub);
                }
                } 
            }
            fclose(fptr);
        }
        else
            {
                printf("invalid");
            }
        printf("1-exit,0-continue\n");
        scanf("%d",&f);
    }  
}