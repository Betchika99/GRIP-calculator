#include "json_parser.hpp"

QStringList json_to_models_names(json_t *input_JSON) {
    QStringList result;
    QString name;
    if (!json_is_string(json_object_get(input_JSON, "name"))) {
        fprintf(stderr, "ERROR: name is not a string\n");
        name = "DEFAULTNAME";
    } else {
        json_t *root = json_object_get(input_JSON, "name");
        for (size_t i = 0; i < json_array_size(root); i++) {
            json_t *data, *sha, *commit, *message;
            const char *message_text;
            data = json_array_get(root, i);
            if (!json_is_object(data)) {
                fprintf(stderr, "error: commit data %zu is not an object\n", i + 1);
                json_decref(root);
                return result;
            }
    }
}

std::string json_to_favourite_name(json_t *input_JSON){
  std::string name;
  if(!json_is_string(json_object_get(input_JSON, "name"))){
    fprintf(stderr, "ERROR: name is not a string\n");
    name = "DEFAULTNAME";
  } else {
    name = std::string(json_string_value(json_object_get(input_JSON, "name")));
  }
  return name;
}

std::string json_to_model_name(json_t *input_JSON){
  std::string model_name;
  if(!json_is_string(json_object_get(input_JSON, "model_name"))){
    fprintf(stderr, "ERROR: model_name is not a string\n");
    model_name = "DEFAULTNAME";
  } else {
    model_name = std::string(json_string_value(json_object_get(input_JSON, "model_name")));
  }
  return model_name;
}

std::string json_to_background_name(json_t *input_JSON){
  std::string background_name;
  if(!json_is_string(json_object_get(input_JSON, "background_name"))){
    fprintf(stderr, "ERROR: background_name is not a string\n");
    background_name = "DEFAULTNAME";
  } else {
    background_name = std::string(json_string_value(json_object_get(input_JSON, "background_name")));
  }
  return background_name;
}

std::string json_to_strategy_name(json_t *input_JSON){
  std::string strategy_name;
  if(!json_is_string(json_object_get(input_JSON, "strategy_name"))){
    fprintf(stderr, "ERROR: strategy_name is not a string\n");
    strategy_name = "DEFAULTNAME";
  } else {
    strategy_name = std::string(json_string_value(json_object_get(input_JSON, "strategy_name")));
  }
  return strategy_name;
}

user json_to_user_struct(json_t *input_JSON){

  if(!json_is_string(json_object_get(input_JSON, "email"))) fprintf(stderr, "ERROR: email is not a string\n");
  if(!json_is_string(json_object_get(input_JSON, "password"))) fprintf(stderr, "ERROR: password is not a string\n");

  json_t *email = json_object_get(input_JSON, "email");
  json_t *password = json_object_get(input_JSON, "password");


  user new_user = user(std::string(json_string_value(json_object_get(input_JSON, "email"))),std::string(json_string_value(json_object_get(input_JSON, "password"))));
  return new_user;
}

all_params json_to_params_struct(json_t *requestJSON){
  json_t *input = json_object_get(requestJSON, "input_params");

  std::string strategy_name;

  if(!json_is_string(json_object_get(input, "strategy_name"))){
    fprintf(stderr, "ERROR: strategy_name is not a string\n");
    strategy_name = "Portrait";
  } else {
    strategy_name = std::string(json_string_value(json_object_get(input, "strategy_name")));
  }

  all_params params_set(strategy_name);

  if(!json_is_string(json_object_get(input, "background_name"))) fprintf(stderr, "ERROR: background_name is not a string\n");
  if(!json_is_string(json_object_get(input, "model_name"))) fprintf(stderr, "ERROR: model_name is not a string\n");
  if(!json_is_real(json_object_get(input, "crop_factor"))) fprintf(stderr, "ERROR: crop_factor is not a double\n");
  if(!json_is_real(json_object_get(input, "destination_to_model"))) fprintf(stderr, "ERROR: destination_to_model is not a double\n");
  if(!json_is_real(json_object_get(input, "focus_destination"))) fprintf(stderr, "ERROR: focus_destination is not a double\n");
  if(!json_is_real(json_object_get(input, "destination_to_background"))) fprintf(stderr, "ERROR: destination_to_background is not a double\n");
  if(!json_is_real(json_object_get(input, "aperture"))) fprintf(stderr, "ERROR: aperture is not a double\n");


  params_set.background_name = std::string(json_string_value(json_object_get(input, "background_name")));
  params_set.model_name = std::string(json_string_value(json_object_get(input, "model_name")));
  params_set.crop_factor = json_real_value(json_object_get(input, "crop_factor"));
  params_set.destination_to_model = json_real_value(json_object_get(input, "destination_to_model"));
  params_set.focus_destination = json_real_value(json_object_get(input, "focus_destination"));
  params_set.destination_to_background = json_real_value(json_object_get(input, "destination_to_background"));
  params_set.aperture = json_real_value(json_object_get(input, "aperture"));

  return params_set;
}
