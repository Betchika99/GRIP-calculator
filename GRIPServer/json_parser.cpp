#include "json_parser.h"

user json_to_user_struct(json_t *input_JSON){
    json_t *email = json_object_get(input_JSON, "username");
    //проверка на валидность

    json_t *password = json_object_get(input_JSON, "username");

    //проверка на валидность
}

all_params json_to_params_struct(json_t *input_JSON){

}
