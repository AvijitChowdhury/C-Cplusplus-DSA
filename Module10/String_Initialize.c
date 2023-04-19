#include<stdio.h>
#include<conio.h>
int main(){
    //char a[5]={'A','v','i','j','i','t'};
    char a[7]="Avijit\0";
    char b[7]="Avijit";//no guranty for adding null
    char c[]="Avijit";//adding null automatically
    // for(int i=0 ;i<5;i++){
    //     printf("%c",a[i]);
    // }
    printf("%s\n",a);
    printf("%s\n",b);
    printf("%s\n",c);

return 0;
}