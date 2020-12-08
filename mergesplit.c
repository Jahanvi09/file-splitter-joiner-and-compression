#include <stdio.h>
  #include <string.h>
  #define MAX 256
  
  void split(){
   int i = 0, line = 0;
        FILE *fp1, *fp2, *fp3;
        char file1[MAX], file2[MAX], file3[MAX], str[MAX];

        /* get the name without file format(.txt) from user */
        printf("Enter your input file name:");
        scanf("%s", file1);

        /* form the output file names */
        sprintf(file2, "%s_part_%d.txt", file1, 1);
        sprintf(file3, "%s_part_%d.txt", file1, 2);
        strcat(file1, ".txt");

        /* open the input file in read mode */
        fp1 = fopen(file1, "r");

        /* error handling */
        if (!fp1) {
                printf("Unable to open input file in read mode!!\n");
                return 0;
        }

        /* open the output file in write mode */
        fp2 = fopen(file2, "w");

        /* error handling */
        if (!fp2) {
                printf("Unable to open output file in write mode\n");
                fclose(fp1);
                return 0;
        }

        /* open the output file in write mode */
        fp3 = fopen(file3, "w");

        /* error handling */
        if (!fp3) {
                printf("Unable to open output file2 in write mode\n");
                fclose(fp1);
                fclose(fp2);
                return 0;
        }

        /* calculate the number of lines in input file */
        while (!feof(fp1)) {
                fgets(str, MAX, fp1);
                if (!feof(fp1))
                        line++;
        }

        /* moving the file pointer to the start of file */
        rewind(fp1);

        /* writing first half of data to first output file */
        while (i < line/2) {
                fgets(str, MAX, fp1);
                if (!feof(fp1)) {
                        fputs(str, fp2);
                }
                i++;
        }

        /* writing second half to second output file */
        while (!feof(fp1)) {
                fgets(str, MAX, fp1);
                if (!feof(fp1)) {
                        fputs(str, fp3);
                }
        }

        /* close all opened files */
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);

        /* remove the input file */
        remove(file1);
  }
  
  
  void merge(){
  
  FILE *fold1, *fold2, *fnew;
	char ch, fname1[20], fname2[20], fname3[30];

	printf("\n\n Merge two files and write it in a new file :\n");
	printf("-------------------------------------------------\n"); 	
	
	printf(" Input the 1st file name : ");
	scanf("%s",fname1);
	printf(" Input the 2nd file name : ");
	scanf("%s",fname2);
	printf(" Input the new file name where to merge the above two files : ");
	scanf("%s",fname3);
	fold1=fopen(fname1, "r");
	fold2=fopen(fname2, "r");
	if(fold1==NULL || fold2==NULL)
	{
//		perror("Error Message ");
		printf(" File does not exist or error in opening...!!\n");
		
	}
	fnew=fopen(fname3, "w");
	if(fnew==NULL)
	{
//		perror("Error Message ");
		printf(" File does not exist or error in opening...!!\n");
		
	}
	while((ch=fgetc(fold1))!=EOF)
	{
		fputc(ch, fnew);
	}
	while((ch=fgetc(fold2))!=EOF)
	{
		fputc(ch, fnew);
	}
	printf(" The two files merged into %s file successfully..!!\n\n", fname3);
	fclose(fold1);
	fclose(fold2);
	fclose(fnew);
  
  }
  
  
  
  int main()
  {
  
  
  int choice;
   printf("\n 1. Press 1 for split");
        printf("\n 2. Press 2 for merge");
        printf("\n Enter your choice");
        /* Taking users input */
        scanf("%d", &choice);
        
        
        switch(choice)
        {
            case 1:
                split();
                break;
            case 2:
                merge();
                break;
            default:
                printf("you have passed a wrong key");
                printf("\n press any key to continue");
        }
        
        
        
    }    
        
        
        
 
