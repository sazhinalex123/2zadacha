#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <limits.h>


int search(const char *input_file, char *arr){

    char str[514];
    int k=0;
    int t=0;
    int j=0;
    int m=0;
    int num=INT_MAX;
    FILE* input;

    input = fopen(input_file, "r");
    if(!input){
       return -1;
    }
    else{
        if (fgets(str, 514, input)==NULL){
            printf("No such number\n");
            fclose(input);
            return -1;
        }
        else{
            rewind(input);
            str[0]='\0';
            while(fgets(arr, 514, input)!=NULL){
                for (int i=0; i<514; i++){
                    if (arr[i]=='\n'){
                        arr[i]='\0';
                    }
                }
                while(arr[j]!='\0'){
                    if (arr[j] == '"'){
                        m=j;
                        t++;
                        j++;
                        if ((t%2) != 0){
                            while(arr[j] != '"'){
                                if(isdigit(arr[j])!=0 || arr[m+1]=='-'){
                                    str[k]=arr[j];
                                    k++;
                                    j++;
                                }
                                else{
                                    j++;
                                }
                            }

                            str[k]='\0';
                            k=0;
                            if(str[0]!='\0'){
                                    if (atoi(str) < num){
                                    num = atoi(str);
                                    }
                            }
                            str[0]='\0';
                        }
                        if ((t%2)==0){
                            j++;
                        }
                    }
                    else{
                        j++;
                    }
                }
                arr[0]='\0';
                j=0;
            }
            fclose(input);
            return num;
        }
    }
}


int autotest (void){
    int i;
    char arr[512];
    i=search("test.txt", arr);
    if (i==1){
        return 1;
    }
    else{
        return -1;
    }
}



int main(void){
    int res=0;
    char arr[512];
    FILE* output;
    output=fopen("data.txt","w");
    res=autotest();
    if (res==1){
        printf("AutoTest  passed\n");
    }
    else{
        printf("AutoTest failed\n");
    }
    res=search("text.txt", arr);
    if(res==-1){
        return -1;
    }
    else{
        printf("%d\n",res);
        fprintf(output,"%d\n",res);
        return 0;
    }
    fclose(output);
}
