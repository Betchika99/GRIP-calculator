#ifndef JSON_PARSER_H
#define JSON_PARSER_H
#include <jansson.h>
#include <string>
#include <QStringList>

struct all_params{
    std::string strategy_name;
    std::string background_name;
    std::string model_name;
    double crop_factor;
    double destination_to_model;
    double focus_destination;
    double destination_to_background;
    double aperture;


    all_params(std::string name_of_strategy)
    {
       if (name_of_strategy == "Portrait"){
          strategy_name = name_of_strategy;
          background_name = "Background1Name";
          model_name = "Model1Name";
          crop_factor = 1.0;
          destination_to_model = 1.0;
          focus_destination = 24.0;
          destination_to_background = 500.0;
          aperture = 8.0;
       } else if (name_of_strategy == "Macro"){
         strategy_name = name_of_strategy;
         background_name = "Background1Name";
         model_name = "Model1Name";
         crop_factor = 1.0;
         destination_to_model = 1.0;
         focus_destination = 24.0;
         destination_to_background = 500.0;
         aperture = 8.0;
       } else if (name_of_strategy == "CloseUp"){
         strategy_name = name_of_strategy;
         background_name = "Background1Name";
         model_name = "Model1Name";
         crop_factor = 1.0;
         destination_to_model = 1.0;
         focus_destination = 24.0;
         destination_to_background = 500.0;
         aperture = 8.0;
       } else if (name_of_strategy == "Landscape"){
         strategy_name = name_of_strategy;
         background_name = "Background1Name";
         model_name = "Model1Name";
         crop_factor = 1.0;
         destination_to_model = 1.0;
         focus_destination = 24.0;
         destination_to_background = 500.0;
         aperture = 8.0;
       } else {
         strategy_name = "Portrait";
         background_name = "Background1Name";
         model_name = "Model1Name";
         crop_factor = 1.0;
         destination_to_model = 1.0;
         focus_destination = 24.0;
         destination_to_background = 500.0;
         aperture = 8.0;
       }
    }
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

QStringList json_to_models_names(json_t *input_JSON);

std::string json_to_favourite_name(json_t *input_JSON);

std::string json_to_model_name(json_t *input_JSON);

std::string json_to_background_name(json_t *input_JSON);

std::string json_to_strategy_name(json_t *input_JSON);

user json_to_user_struct(json_t *input_JSON);

all_params json_to_params_struct(json_t *input_JSON);



#endif // JSON_PARSER_H
