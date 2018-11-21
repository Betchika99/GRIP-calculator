#ifndef JSON_PARSER_H
#define JSON_PARSER_H
#include <jansson.h>
#include <string.h>

struct all_params{
    char* email;
    int background_id;
    int model_id;
    int format_id;
    float crop_factor;
    float destination_to_model;
    float focus_destination;
    float destination_to_background;
    float aperture;

    float depth;
    float front_GRIP;
    float back_GRIP;
    float hyperfocal_distance;



    all_params():
        background_id(1),
        model_id(1),
        format_id(1),
        crop_factor(1.0),
        destination_to_model(1.0),
        focus_destination(24.0),
        destination_to_background(500.0),
        aperture(8.0),
        depth(0.0),  //временные данные
        front_GRIP(0.5), //временные данные
        back_GRIP(0.5), //временные данные
        hyperfocal_distance(2400) //временные данные
    {}
};

struct user{
    char* email;
    char* password;
    user(char* mail, size_t email_size, char* pass, size_t password_size)
    {
        email = new char[email_size];
        strcpy(email, mail);
        password = new char[password_size];
        strcpy(password, pass);
    }
};



user json_to_user_struct(json_t *input_JSON);

all_params json_to_params_struct(json_t *input_JSON);



#endif // JSON_PARSER_H
