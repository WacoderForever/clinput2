typedef struct CliInterface{

    //colors

    char *prompt_color;
    char *response_color;
    char *normal_color;
    char *error_color;
    char *reset_color;

    //messsages
    char *empty_response;
    char *no_int_message;

    //methods
    char *(*ask_string)(struct CliInterface *self,char *prompt);
    long (*ask_int)(struct CliInterface *self,char *prompt);

}CliInterface;

//constructor

CliInterface newCliInterface();

char *CliInterface_ask_string(struct CliInterface *self,char *prompt);
long CliInterface_ask_int(struct CliInterface *self,char *prompt);