#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 351
#define FILE_NAME_LENGTH

typedef struct Job{
    int code;
    char name[MAX_LENGTH];
}Job;

/*
readElements:
Parameters: name of the file and an adress where u want 
to hold the number of elements
Return: return a vector with the jobs from the specified file
in file: elements must be place on 2 columns "code" "Job"
*/
Job* readElements(char fileName[FILE_NAME_LENGTH], int *numberOfElements) {
    FILE *f = fopen(fileName,"r");
    
    //Check if we can open the file
    if(f==NULL) {
        printf("ERROR! File with name %s not found",fileName);
        exit(EXIT_FAILURE);   
    }
    
    Job *vector=NULL;
    char nameBuffer[MAX_LENGTH],letter;
    int codeBuffer;
    int flag=1;
    int numberOfLetters;
    *numberOfElements = 0;

    //Skip the first two word "cod denumire"
    fscanf(f,"%s",nameBuffer);
    fscanf(f,"%s",nameBuffer);
    
    while(flag) {
        numberOfLetters = 0;
        (*numberOfElements)++;
        vector = (Job*)realloc(vector, *numberOfElements * sizeof(Job));
        
        //Check if we can add one more element to vector
        if(vector==NULL) {
            printf("ERROR! Not enough memory to store file elements.");
            exit(EXIT_FAILURE);
        }

        //Read the code for a job
        fscanf(f,"%d",&vector[*numberOfElements-1].code);

        //Read the name for a job
        fgetc(f);
        do {
            letter = fgetc(f);
            if(letter == EOF) {
                flag = 0;
            }
            vector[*numberOfElements-1].name[numberOfLetters] = letter;
            numberOfLetters++;
        }while(letter != '\n' && letter != EOF);
        vector[*numberOfElements-1].name[numberOfLetters-1] = '\0';
    }
    fclose(f);
    return vector;
}

//search
int ameliorated_binary_search(int x, Job *vector, int nrElem) {
    int left=0;
    int right=nrElem;
    int med;
    int counter=0;

    while(left<right) {
        med=(left+right)/2;
        counter++;
        if(vector[med].code > x) {
            left = med + 1;
        } else {
            right = med;
        }
    }
    if(right>nrElem) {
        return -1;
    }
    if(right<=x) {
        if(vector[left].code==x) {
            return left;
        }
    }
    return -1;
}

void printSameName(Job *vector, int n, char job_name[MAX_LENGTH]) {
    int i,l;
    l = strlen(job_name);
    for(i=0; i<n; i++) {
        if(strncmp(vector[i].name,job_name,l)==0) {
            printf("%s\n",vector[i].name);
        }
    }
}

int main() {
    int nrElemente,i;

    Job *vector = readElements("COR_Descrescator.txt",&nrElemente);
    
    //Afisare folosita pentru a vedea daca citirea e corecta
    FILE *scrie = fopen("afisare.txt","w");
    for(i=0;i<nrElemente;i++) {
        fprintf(scrie,"%d    %d   %s\n",i,vector[i].code,vector[i].name);
    }
    fclose(scrie);

    int searchCode,x;
    char searchName[MAX_LENGTH];

    //Get the wanted code
    //printf("Search code: "); ELIM LINE FOR ONLINE TESTING
    scanf("%d",&searchCode);
    
    //Search for code
    x = ameliorated_binary_search(searchCode,vector,nrElemente);
    if(x == -1) {
        printf("COD INEXISTENT\n");
    } else {
        printf("%s\n",vector[x].name);
    }

    //Get the wanted name
    //printf("Search name: "); ELIM LINE FOR ONLINE TESTING
    scanf("%s",searchName);
    
    //Search for name
    printSameName(vector,nrElemente,searchName);

    return 0;
}