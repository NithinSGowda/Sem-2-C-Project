#include<stdio.h>
#include<time.h>
#include<stdlib.h>
FILE *f,*ft;
char t[50],head[50],para[50],temp[40],c[10];


void heading(FILE *f)
{
    char txt[50];
    fflush(stdin);
    printf("Enter the Heading of your website : ");
    scanf("%[^\n]",txt);
    fflush(stdin);
    fprintf(f,"<html>\n<head>\n<h1><center>%s</h1></center></head>",txt);
}
void title(FILE *f)
{
    char txt[50];
    printf("\nEnter the Title : ");
    scanf("%[^\n]",txt);
    fflush(stdin);
    fprintf(f,"<title>\n%s</title>\n",txt);
}
void bgimage(FILE *f)
{
    char txt[50],c,path[500];
    printf("Do you need a background image[y/n] : ");
    c=getchar();
    fflush(stdin);
    if(c=='y')
    {
        printf("Enter the path of background image : ");
        fflush(stdin);
        scanf("%s",path);
        fflush(stdin);
        fprintf(f,"<body background=%s opacity=50>\n",path);
    }
    else
    {
    printf("Do you need a background color[y/n] : ");
    c=getchar();
    fflush(stdin);
    if(c=='y')
    {
        fflush(stdin);
        printf("\nEnter the color of your website : ");
        scanf("%s",txt);
        fflush(stdin);
        fprintf(f,"<body bgcolor=%s>\n",txt);
    }
    else fprintf(f,"<body>\n");
    }
}
void end(FILE *f)
{
    fprintf(f,"</body></html>");
}
void post(FILE *f,int i)
{
    char txt[500],c,link[500];
    fflush(stdin);
    printf("\nEnter your post %d : ",i);
    scanf("%[^\n]",txt);
    fflush(stdin);

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);
    printf("Do you want to insert a link[y/n] : ");
    c=getchar();
    if(c=='y')
    {
        fflush(stdin);
        printf("Enter the link : ");
        scanf("%s",link);
        fprintf(f,"<p><h3><a href=%s>%s</a></h3></p><p>Posted on %s</p><hr>\n",link,txt,s);
        fflush(stdin);
    }
    else
    fprintf(f,"<p><h3>%s</h3></p><p>Posted on %s</p><hr>\n",txt,s);
    fflush(stdin);

    printf("\nDo you add one more post[y/n] : ");
    c=getchar();
    if(c=='y')
        {
            i++;
            post(f,i);
        }
    end(f);
    fclose(f);
    printf("\n\nYour website can be accsesed in Chrome, type \"file:///C:/Users/user/Desktop/Code Blocks/MyWebsite.html\"\n",t);
    exit(0);
}

void new()
{
    ft=fopen("MyWebsite.html","w");
    fclose(ft);
    f=fopen("MyWebsite.html","a");
    heading(f);
    title(f);
    bgimage(f);
    post(f,1);
    end(f);
}

void updater(FILE *f)
{
    fseek(f,14,2);
    post(f,1);
    end(f);

}

int main()
{
    int n;
    char file[50];
    FILE *fu;
    printf("\t\t\t\tWEBSITE BUILDER\n\n 1)Build a new website\n 2)Update an existing website\n\nEnter your choice :  ");
    scanf("%d",&n);
    if(n==1)
        new();
    else
        {
            printf("Enter your file name : ");
            scanf("%s",file);
            fu=fopen(file,"a");
            updater(fu);
        }
    fclose(fu);
}
