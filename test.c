#include "clinput2.h"

int main(){

    CliInterface interface=newCliInterface();
    int k=CliInterface_ask_int(&interface,"Enter integer");
    printf("Entered integer is: %d\n",k);
}