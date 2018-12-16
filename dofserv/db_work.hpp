
#ifndef DB_WORK_H
#define DB_WORK_H
#include <jansson.h>
#include <string>
#include "json_parser.hpp"

bool db_sign_in(user current_user);

json_t *return_strategies();

json_t *return_models(std::string strategy_name);

json_t *return_backgrounds(std::string strategy_name);

json_t *return_favourites(user current_user);

std::string return_model_address(std::string model_name);

std::string return_background_address(std::string background_name);

all_params return_last_params(user current_user);

bool set_last_params(user current_user, all_params params);

json_t *return_favourites(user current_user);

bool set_favourite(user current_user, all_params params, std::string favourite);


bool delete_favourite_from_db(user current_user, std::string favourite_name);

#endif // DB_WORK_H
