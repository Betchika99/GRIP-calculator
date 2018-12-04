#include "json_parser.hpp"

user json_to_user_struct(json_t *input_JSON){
    json_t *email = json_object_get(input_JSON, "username");
    //проверка на валидность

    json_t *password = json_object_get(input_JSON, "password");

    //проверка на валидность
    user new_user = user("hello","world");
    return new_user;
}

all_params json_to_params_struct(json_t *requestJSON){
  json_t *input = json_object_get(requestJSON, "input_params");
  json_t *output = json_object_get(requestJSON, "input_params");


  all_params params_set;
  if(!json_is_integer(json_object_get(input, "background_id"))) fprintf(stderr, "ERROR: background_id is not an integer\n");
  if(!json_is_integer(json_object_get(input, "model_id"))) fprintf(stderr, "ERROR: model_id is not an integer\n");
  if(!json_is_integer(json_object_get(input, "format_id"))) fprintf(stderr, "ERROR: format_id is not an integer\n");
  if(!json_is_real(json_object_get(input, "crop_factor"))) fprintf(stderr, "ERROR: crop_factor is not a double\n");
  if(!json_is_real(json_object_get(input, "destination_to_model"))) fprintf(stderr, "ERROR: destination_to_model is not a double\n");
  if(!json_is_real(json_object_get(input, "focus_destination"))) fprintf(stderr, "ERROR: focus_destination is not a double\n");
  if(!json_is_real(json_object_get(input, "destination_to_background"))) fprintf(stderr, "ERROR: destination_to_background is not a double\n");
  if(!json_is_real(json_object_get(input, "aperture"))) fprintf(stderr, "ERROR: aperture is not a double\n");
  if(!json_is_real(json_object_get(input, "depth"))) fprintf(stderr, "ERROR: depth is not a double\n");
  if(!json_is_real(json_object_get(input, "front_GRIP"))) fprintf(stderr, "ERROR: front_GRIP is not a double\n");
  if(!json_is_real(json_object_get(input, "back_GRIP"))) fprintf(stderr, "ERROR: back_GRIP is not a double\n");
  if(!json_is_real(json_object_get(input, "hyperfocal_distance"))) fprintf(stderr, "ERROR: hyperfocal_distance is not a double\n");

  params_set.background_id = json_integer_value(json_object_get(input, "background_id"));
  params_set.model_id = json_integer_value(json_object_get(input, "model_id"));
  params_set.format_id = json_integer_value(json_object_get(input, "format_id"));
  params_set.crop_factor = json_real_value(json_object_get(input, "crop_factor"));
  params_set.destination_to_model = json_real_value(json_object_get(input, "destination_to_model"));
  params_set.focus_destination = json_real_value(json_object_get(input, "focus_destination"));
  params_set.destination_to_background = json_real_value(json_object_get(input, "destination_to_background"));
  params_set.aperture = json_real_value(json_object_get(input, "aperture"));
  params_set.depth = json_real_value(json_object_get(output, "depth"));
  params_set.front_GRIP = json_real_value(json_object_get(output, "front_GRIP"));
  params_set.back_GRIP = json_real_value(json_object_get(output, "back_GRIP"));
  params_set.hyperfocal_distance = json_real_value(json_object_get(output, "hyperfocal_distance"));

  return params_set;
}
