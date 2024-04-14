CliInterface newCliInterface(){

    CliInterface self;

    self.prompt_color= CLI_MAGENTA;
    self.response_color=CLI_BLUE;
    self.normal_color=CLI_WHITE;
    self.error_color=CLI_RED;
    self.reset_color=RESET;

    self.empty_response="You have not entered a response";
    self.no_int_message="No integer entered";

    //methods

    self.ask_string=CliInterface_ask_string;
    self.ask_int=CliInterface_ask_int;

    return self;
}

char *CliInterface_ask_string(struct CliInterface *self,char *prompt){

    while(true){
        //prompt user
        if(prompt[strlen(prompt)-1] != '\n'){

            printf("%s%s:",self->prompt_color,prompt);
        }
        else{

            printf("%s%s:",self->prompt_color,prompt);
        }

        fflush(stdin);
        printf("%s",self->response_color);

        //enter response
        int size=1;
        char *text=(char*)calloc(size,sizeof(char));

        if(text==NULL){

            perror("Text not assigned memeory");
            free(text);
            exit(1);
        }

        char ch;
        ch=getchar();
        int i=0;

        while(ch!='\n'){
            size++;
            char *new_text=(char*)realloc(text,size*sizeof(char));

            if(new_text == NULL){

                perror("New not allocated memory");
                free(text);
                text=NULL;
                exit(1);
            }
            text=new_text; //updating the old pointer
            text[i]=ch;
            i++;
            ch=' ';
            ch=getchar();

        }

        text[size-1]='\0';

        if(text[0]=='\0'){

            printf("%s %s\n",self->error_color,self->empty_response);
            
        }
        
        printf("%s",self->reset_color);
        return text;
    }   
}

long CliInterface_ask_int(struct CliInterface *self,char *prompt){

    long ans;

    while(true){
        //prompt user
        if(prompt[strlen(prompt)-1] != '\n'){

            printf("%s%s:",self->prompt_color,prompt);

        }

        else{

            printf("%s%s:",self->prompt_color,prompt);
        }

        fflush(stdin);
        printf("%s",self->response_color);
        int size=1;
        int i=0;
        char *text=(char*)calloc(size,sizeof(char));
        char ch;
        ch=getchar();

        while(ch != '\n'){
            
            size++;
            char *new_text=(char*)realloc(text,size*sizeof(char));

            if(new_text==NULL){

                free(text);
                text=NULL;
                perror("New text not allocated memory");
                exit(1);
            }

            text=new_text; //updating text;
            text[i]=ch;
            i++;
            ch=' ';
            ch=getchar();
        }
        char *ptr;
        text[size-1]='\0';
        ans=strtol(text,&ptr,10);
        printf("%s",self->reset_color);

        if(!strcmp(text,ptr)){

            printf("%s%s\n",self->error_color,self->no_int_message);
            printf("%s",self->reset_color);
            free(text);
            text=NULL;
            exit(1);
        }

        free(text);
        text=NULL;
        return ans;
    }
}