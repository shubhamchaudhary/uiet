#include<stdio.h>
void print();
int main(){
  print();
  return 0;
}
void print(){
    char str[20]="hello world\0";
    int i=0;
    while(str[i]!='\0'){
        printf("%c",str[i]);
        i++;
        str[i]=str[i-1];
        getchar();
    }
}
