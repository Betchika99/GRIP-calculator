#include "db_work.hpp"
#include <iostream>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/types.hpp>
#include <bsoncxx/types/value.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <jansson.h>

mongocxx::uri uri("mongodb://localhost:27017");
mongocxx::client client(uri);
mongocxx::database db = client["dofdb"];
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

bool db_sign_in(user current_user){


  mongocxx::collection coll = db["users"];


  bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result = coll.find_one(document{} << "email" << current_user.email << finalize);
  if(maybe_result) {
    bsoncxx::document::view view = maybe_result->view();
    bsoncxx::document::element pass_element = view["password"];
    std::string password = pass_element.get_utf8().value.to_string();

    if (current_user.password == password) {
      return true;
    } else {
      return false;
    }
  } else {
    auto builder = document{};
    bsoncxx::document::value doc_value = builder
      << "email" << current_user.email
      << "password" << current_user.password << finalize;
    bsoncxx::document::view view = doc_value.view();
    coll.insert_one(view);
    return true;
  }





}

json_t *return_strategies(){
  json_t *array  = json_array();

  mongocxx::collection coll = db["strategies"];

  mongocxx::cursor cursor = coll.find({});
  for(auto doc : cursor) {
    json_t *element = json_object();


    bsoncxx::document::element strategy_name_elem = doc["strategy_name"];
    json_object_set_new( element, "strategy_name", json_string( strategy_name_elem.get_utf8().value.to_string().c_str() ) );
    bsoncxx::document::element background_name_elem = doc["background_name_default"];
    json_object_set_new( element, "background_name_default", json_string( background_name_elem.get_utf8().value.to_string().c_str() ) );
    bsoncxx::document::element model_name_elem = doc["model_name_default"];
    json_object_set_new( element, "model_name_default", json_string( model_name_elem.get_utf8().value.to_string().c_str() ) );

    bsoncxx::document::element crop_factor_min_elem = doc["crop_factor_min"];
    json_object_set_new( element, "crop_factor_min", json_real( crop_factor_min_elem.get_double() ) );
    bsoncxx::document::element destination_to_model_min_elem = doc["destination_to_model_min"];
    json_object_set_new( element, "destination_to_model_min", json_real( destination_to_model_min_elem.get_double() ) );
    bsoncxx::document::element focus_destination_min_elem = doc["focus_destination_min"];
    json_object_set_new( element, "focus_destination_min", json_real( focus_destination_min_elem.get_double() ) );
    bsoncxx::document::element destination_to_background_min_elem = doc["destination_to_background_min"];
    json_object_set_new( element, "destination_to_background_min", json_real( destination_to_background_min_elem.get_double() ) );
    bsoncxx::document::element aperture_min_elem = doc["aperture_min"];
    json_object_set_new( element, "aperture_min", json_real( aperture_min_elem.get_double() ) );

    bsoncxx::document::element crop_factor_max_elem = doc["crop_factor_max"];
    json_object_set_new( element, "crop_factor_max", json_real( crop_factor_max_elem.get_double() ) );
    bsoncxx::document::element destination_to_model_max_elem = doc["destination_to_model_max"];
    json_object_set_new( element, "destination_to_model_max", json_real( destination_to_model_max_elem.get_double() ) );
    bsoncxx::document::element focus_destination_max_elem = doc["focus_destination_max"];
    json_object_set_new( element, "focus_destination_max", json_real( focus_destination_max_elem.get_double() ) );
    bsoncxx::document::element destination_to_background_max_elem = doc["destination_to_background_max"];
    json_object_set_new( element, "destination_to_background_max", json_real( destination_to_background_max_elem.get_double() ) );
    bsoncxx::document::element aperture_max_elem = doc["aperture_max"];
    json_object_set_new( element, "aperture_max", json_real( aperture_max_elem.get_double() ) );

    bsoncxx::document::element crop_factor_default_elem = doc["crop_factor_default"];
    json_object_set_new( element, "crop_factor_default", json_real( crop_factor_default_elem.get_double() ) );
    bsoncxx::document::element destination_to_model_default_elem = doc["destination_to_model_default"];
    json_object_set_new( element, "destination_to_model_default", json_real( destination_to_model_default_elem.get_double() ) );
    bsoncxx::document::element focus_destination_default_elem = doc["focus_destination_default"];
    json_object_set_new( element, "focus_destination_default", json_real( focus_destination_default_elem.get_double() ) );
    bsoncxx::document::element destination_to_background_default_elem = doc["destination_to_background_default"];
    json_object_set_new( element, "destination_to_background_default", json_real( destination_to_background_default_elem.get_double() ) );
    bsoncxx::document::element aperture_default_elem = doc["aperture_default"];
    json_object_set_new( element, "aperture_default", json_real( aperture_default_elem.get_double() ) );

    json_array_append_new(array, element );
  }
  return array;
}

json_t *return_models(std::string strategy_name){
  json_t *array  = json_array();
//    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};
    auto coll = conn["dofdb"]["models"];

    mongocxx::cursor cursor = coll.find(document{} << "strategy_name" << strategy_name << finalize);
  for(auto doc : cursor) {
    bsoncxx::document::element name_element = doc["name"];
    json_t *element = json_object();
    json_object_set_new( element, "model_name", json_string(name_element.get_utf8().value.to_string().c_str()));
    json_array_append_new(array, element);
  }
  return array;
}

json_t *return_backgrounds(std::string strategy_name){
  json_t *array  = json_array();

  mongocxx::collection coll = db["backgrounds"];

  mongocxx::cursor cursor = coll.find(document{} << "strategy_name" << strategy_name << finalize);
  for(auto doc : cursor) {
    bsoncxx::document::element name_element = doc["name"];
    json_t *element = json_object();
    json_object_set_new( element, "background_name", json_string(name_element.get_utf8().value.to_string().c_str()));
    json_array_append_new(array, element);
  }
  return array;
}

std::string return_model_address(std::string model_name){
  mongocxx::collection coll = db["models"];
  bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result = coll.find_one(document{} << "name" << model_name << finalize);
  if(maybe_result) {
    bsoncxx::document::view view = maybe_result->view();
    bsoncxx::document::element address = view["address"];
    return address.get_utf8().value.to_string();


  } else {
    return "DEFAULT";
  }

}

std::string return_background_address(std::string background_name){
  mongocxx::collection coll = db["backgrounds"];
  bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result = coll.find_one(document{} << "name" << background_name << finalize);
  if(maybe_result) {
    bsoncxx::document::view view = maybe_result->view();
    bsoncxx::document::element address = view["address"];
    return address.get_utf8().value.to_string();


  } else {
    return "DEFAULT";
  }
}

all_params return_last_params(user current_user){
  mongocxx::collection coll = db["users"];


  bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result = coll.find_one(document{} << "email" << current_user.email << finalize);
  if(maybe_result) {
    bsoncxx::document::view view = maybe_result->view();
    bsoncxx::document::element pass_element = view["password"];
    std::string password = pass_element.get_utf8().value.to_string();

    if (current_user.password == password) {
      bsoncxx::document::element strategy_name_elem = view["strategy_name"];
      all_params params(strategy_name_elem.get_utf8().value.to_string());

      bsoncxx::document::element background_name_elem = view["background_name"];
      params.background_name = background_name_elem.get_utf8().value.to_string();
      bsoncxx::document::element model_name_elem = view["model_name"];
      params.background_name = model_name_elem.get_utf8().value.to_string();
      bsoncxx::document::element crop_factor_elem = view["crop_factor"];
      params.background_name = crop_factor_elem.get_double();
      bsoncxx::document::element destination_to_model_elem = view["destination_to_model"];
      params.background_name = destination_to_model_elem.get_double();
      bsoncxx::document::element focus_destination_elem = view["focus_destination"];
      params.background_name = focus_destination_elem.get_double();
      bsoncxx::document::element destination_to_background_elem = view["destination_to_background"];
      params.background_name = destination_to_background_elem.get_double();
      bsoncxx::document::element aperture_elem = view["aperture"];
      params.background_name = aperture_elem.get_double();
      return params;

    } else {
      return all_params("Portrait");
    }
  } else {
    auto builder = document{};
    bsoncxx::document::value doc_value = builder
      << "email" << current_user.email
      << "password" << current_user.password
      << finalize;
    bsoncxx::document::view view = doc_value.view();
    coll.insert_one(view);
    return all_params("Portrait");
  }

}

bool set_last_params(user current_user, all_params params){
  mongocxx::collection coll = db["users"];


  bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result = coll.find_one(document{} << "email" << current_user.email << finalize);
  if(maybe_result) {
    bsoncxx::document::view view = maybe_result->view();
    bsoncxx::document::element pass_element = view["password"];
    std::string password = pass_element.get_utf8().value.to_string();

    if (current_user.password == password) {
      coll.update_one(document{} << "email" << current_user.email << finalize,
                      document{} << "$set" << open_document <<
                        "background_name" << params.background_name <<
                        "model_name" << params.model_name <<
                        "strategy_name" << params.strategy_name <<
                        "crop_factor" << params.crop_factor <<
                        "destination_to_model" << params.destination_to_model <<
                        "focus_destination" << params.focus_destination <<
                        "destination_to_background" << params.destination_to_background <<
                        "aperture" << params.aperture << close_document << finalize);
      return true;
    } else {
      return false;
    }
  } else {
    auto builder = document{};
    bsoncxx::document::value doc_value = builder
      << "email" << current_user.email
      << "password" << current_user.password <<
        "background_name" << params.background_name <<
        "model_name" << params.model_name <<
        "strategy_name" << params.strategy_name <<
        "crop_factor" << params.crop_factor <<
        "destination_to_model" << params.destination_to_model <<
        "focus_destination" << params.focus_destination <<
        "destination_to_background" << params.destination_to_background <<
        "aperture" << params.aperture  << finalize;
    bsoncxx::document::view view = doc_value.view();
    coll.insert_one(view);
    return true;
  }

}

json_t *return_favourites(user current_user){
  json_t *array  = json_array();

  mongocxx::collection coll = db["favourites"];

  mongocxx::cursor cursor = coll.find(document{} << "email" << current_user.email << finalize);
  for(auto doc : cursor) {
    json_t *element = json_object();


    bsoncxx::document::element strategy_name_elem = doc["strategy_name"];
    json_object_set_new( element, "strategy_name", json_string( strategy_name_elem.get_utf8().value.to_string().c_str() ) );
    bsoncxx::document::element background_name_elem = doc["background_name"];
    json_object_set_new( element, "background_name", json_string( background_name_elem.get_utf8().value.to_string().c_str() ) );
    bsoncxx::document::element model_name_elem = doc["model_name"];
    json_object_set_new( element, "model_name", json_string( model_name_elem.get_utf8().value.to_string().c_str() ) );
    bsoncxx::document::element crop_factor_elem = doc["crop_factor"];
    json_object_set_new( element, "crop_factor", json_real( crop_factor_elem.get_double() ) );
    bsoncxx::document::element destination_to_model_elem = doc["destination_to_model"];
    json_object_set_new( element, "destination_to_model", json_real( destination_to_model_elem.get_double() ) );
    bsoncxx::document::element focus_destination_elem = doc["focus_destination"];
    json_object_set_new( element, "focus_destination", json_real( focus_destination_elem.get_double() ) );
    bsoncxx::document::element destination_to_background_elem = doc["destination_to_background"];
    json_object_set_new( element, "destination_to_background", json_real( destination_to_background_elem.get_double() ) );
    bsoncxx::document::element aperture_elem = doc["aperture"];
    json_object_set_new( element, "aperture", json_real( aperture_elem.get_double() ) );


    json_array_append_new(array, element );
  }
  return array;
}

bool delete_favourite_from_db(user current_user, std::string favourite_name){
    mongocxx::collection coll = db["users"];
    bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result = coll.find_one(document{} << "name" << favourite_name << finalize);
    if(maybe_result) {
      bsoncxx::document::view view = maybe_result->view();
      bsoncxx::document::element pass_element = view["password"];
      std::string password = pass_element.get_utf8().value.to_string();
      if (current_user.password == password) {
        coll = db["favourites"];
        coll.delete_one(document{} << "name" << favourite_name << finalize);
        return true;
      } else {
        return false;
      }
    } else {

      return false;
    }
    return true;



  return true;
}

bool set_favourite(user current_user, all_params params, std::string favourite_name){
  mongocxx::collection coll = db["favourites"];
  bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result = coll.find_one(document{} << "name" << favourite_name << "email" << current_user.email << finalize);
  if(maybe_result) {
    return false;
  } else {
    auto builder = document{};
    bsoncxx::document::value doc_value = builder
      << "name" << favourite_name << "email" << current_user.email <<
        "background_name" << params.background_name <<
        "model_name" << params.model_name <<
        "strategy_name" << params.strategy_name <<
        "crop_factor" << params.crop_factor <<
        "destination_to_model" << params.destination_to_model <<
        "focus_destination" << params.focus_destination <<
        "destination_to_background" << params.destination_to_background <<
        "aperture" << params.aperture
      << finalize;
    bsoncxx::document::view view = doc_value.view();
    coll.insert_one(view);
    return true;
  }


}
