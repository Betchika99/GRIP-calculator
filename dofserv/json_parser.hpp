
#ifndef JSON_PARSER_H
#define JSON_PARSER_H
#include <jansson.h>
#include <string>

struct all_params{
    std::string email;
    int background_id;
    int model_id;
    int format_id;
    double crop_factor;
    double destination_to_model;
    double focus_destination;
    double destination_to_background;
    double aperture;

    double depth;
    double front_GRIP;
    double back_GRIP;
    double hyperfocal_distance;


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
    std::string email;
    std::string password;
    user(std::string mail, std::string pass)
    {
        email = mail;
        password = pass;
    }
};



user json_to_user_struct(json_t *input_JSON);

all_params json_to_params_struct(json_t *input_JSON);



#endif // JSON_PARSER_H
