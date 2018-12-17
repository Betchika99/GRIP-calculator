#include "handler.hpp"
#include "json_parser.hpp"
#include "db_work.hpp"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <jansson.h>
#include <iostream>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>


using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

#define HEADER_BUFFER_SIZE 1024
#define HTTP_FORBIDDEN 500

void unspecified_URL(struct evhttp_request *request, void *arg){

    struct evbuffer *buffer = evbuffer_new();
    if (buffer == NULL){
        fprintf(stderr, "ERROR: Can not create evbuffer(An evbuffer is an opaque data type for efficiently buffering data to be sent or received on the network.)");
    }
    evbuffer_add_printf(buffer, "ERROR: This URL does not exist");
    printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
    evhttp_send_reply(request, 404, "Not Found", buffer);
    evbuffer_free(buffer);
}

void a(struct evhttp_request *request, void *arg){

  mongocxx::uri uri("mongodb://localhost:27017");
  mongocxx::client client(uri);
  mongocxx::database db = client["dofdb"];
  mongocxx::collection coll = db["strategies"];

  auto builder = document{};
  bsoncxx::document::value doc_value = builder
    << "strategy_name" << "Portrait"
    << "background_name_default" << "Hello_world" <<
      "model_name_default" << "Hello_world" <<
      "crop_factor_min" << 1.1 <<
      "destination_to_model_min" << 1.0 <<
      "focus_destination_min" << 1.0 <<
      "destination_to_background_min" << 1.0 <<
      "aperture_min" << 1.0 <<
      "crop_factor_max" << 1.0 <<
      "destination_to_model_max" << 1.1 <<
      "focus_destination_max" << 1.0 <<
      "destination_to_background_max" << 1.0 <<
      "aperture_max" << 1.0 <<
      "crop_factor_default" << 1.0 <<
      "destination_to_model_default" << 1.0 <<
      "focus_destination_default" << 1.0 <<
      "destination_to_background_default" << 1.0 <<
      "aperture_default" << 1.0 << finalize;
  bsoncxx::document::view view = doc_value.view();
  coll.insert_one(view);

  doc_value = builder
    << "strategy_name" << "Macro"
    << "background_name_default" << "Hello_world" <<
      "model_name_default" << "Hello_world" <<
      "crop_factor_min" << 1.1 <<
      "destination_to_model_min" << 1.0 <<
      "focus_destination_min" << 1.0 <<
      "destination_to_background_min" << 1.0 <<
      "aperture_min" << 1.0 <<
      "crop_factor_max" << 1.0 <<
      "destination_to_model_max" << 1.1 <<
      "focus_destination_max" << 1.0 <<
      "destination_to_background_max" << 1.0 <<
      "aperture_max" << 1.0 <<
      "crop_factor_default" << 1.0 <<
      "destination_to_model_default" << 1.0 <<
      "focus_destination_default" << 1.0 <<
      "destination_to_background_default" << 1.0 <<
      "aperture_default" << 1.0 << finalize;
  view = doc_value.view();
  coll.insert_one(view);

  doc_value = builder
    << "strategy_name" << "CloseUp"
    << "background_name_default" << "Hello_world" <<
      "model_name_default" << "Hello_world" <<
      "crop_factor_min" << 1.1 <<
      "destination_to_model_min" << 1.0 <<
      "focus_destination_min" << 1.0 <<
      "destination_to_background_min" << 1.0 <<
      "aperture_min" << 1.0 <<
      "crop_factor_max" << 1.0 <<
      "destination_to_model_max" << 1.1 <<
      "focus_destination_max" << 1.0 <<
      "destination_to_background_max" << 1.0 <<
      "aperture_max" << 1.0 <<
      "crop_factor_default" << 1.0 <<
      "destination_to_model_default" << 1.0 <<
      "focus_destination_default" << 1.0 <<
      "destination_to_background_default" << 1.0 <<
      "aperture_default" << 1.0 << finalize;
  view = doc_value.view();
  coll.insert_one(view);

  doc_value = builder
    << "strategy_name" << "Landscape"
    << "background_name_default" << "Hello_world" <<
      "model_name_default" << "Hello_world" <<
      "crop_factor_min" << 1.1 <<
      "destination_to_model_min" << 1.0 <<
      "focus_destination_min" << 1.0 <<
      "destination_to_background_min" << 1.0 <<
      "aperture_min" << 1.0 <<
      "crop_factor_max" << 1.0 <<
      "destination_to_model_max" << 1.1 <<
      "focus_destination_max" << 1.0 <<
      "destination_to_background_max" << 1.0 <<
      "aperture_max" << 1.0 <<
      "crop_factor_default" << 1.0 <<
      "destination_to_model_default" << 1.0 <<
      "focus_destination_default" << 1.0 <<
      "destination_to_background_default" << 1.0 <<
      "aperture_default" << 1.0 << finalize;
  view = doc_value.view();
  coll.insert_one(view);



////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////





  coll = db["models"];
  doc_value = builder
    << "strategy_name" << "Landscape"
    << "background_name_default" << "Hello_world" <<
      "model_name_default" << "Hello_world" <<
      "crop_factor_min" << 1.1 <<
      "destination_to_model_min" << 1.0 <<
      "focus_destination_min" << 1.0 <<
      "destination_to_background_min" << 1.0 <<
      "aperture_min" << 1.0 <<
      "crop_factor_max" << 1.0 <<
      "destination_to_model_max" << 1.1 <<
      "focus_destination_max" << 1.0 <<
      "destination_to_background_max" << 1.0 <<
      "aperture_max" << 1.0 <<
      "crop_factor_default" << 1.0 <<
      "destination_to_model_default" << 1.0 <<
      "focus_destination_default" << 1.0 <<
      "destination_to_background_default" << 1.0 <<
      "aperture_default" << 1.0 << finalize;
  view = doc_value.view();
  coll.insert_one(view);

  evhttp_send_reply(request, 200, "OK", NULL);
}




void images_list(struct evhttp_request *request, void *arg){
  struct evkeyvalq uri_params;
  printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
  evhttp_parse_query (request->uri, &uri_params);

  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }

  std::string strategy_name = json_to_strategy_name(requestJSON).c_str();

  json_t *root = json_object();

  json_t *model_names = return_models(strategy_name);
  json_t *background_names = return_backgrounds(strategy_name);

  json_object_set_new(root, "model_names", model_names );
  json_object_set_new(root, "background_names", background_names );


  char *responseData = json_dumps(root, JSON_INDENT(3));
  int responseLen = strlen(responseData);
  char responseHeader[HEADER_BUFFER_SIZE];
  snprintf(responseHeader, HEADER_BUFFER_SIZE, "%d", (int)responseLen);
  json_decref(root);

  struct evbuffer *buffer = evbuffer_new();
  evhttp_add_header(request->output_headers, "Content-Type", "application/json");
  evhttp_add_header(request->output_headers, "Content-Length", responseHeader);
  evbuffer_add(buffer, responseData, responseLen);

  evhttp_send_reply(request, 200, "OK", buffer);

  evbuffer_free(buffer);

}

void strategies_list(struct evhttp_request *request, void *arg){
  struct evkeyvalq uri_params;
  printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
  evhttp_parse_query (request->uri, &uri_params);

  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }

  json_t *root = json_object();

  json_t *strategies = return_strategies();

  json_object_set_new(root, "strategies", strategies);

  char *responseData = json_dumps(root, JSON_INDENT(3));
  int responseLen = strlen(responseData);
  char responseHeader[HEADER_BUFFER_SIZE];
  snprintf(responseHeader, HEADER_BUFFER_SIZE, "%d", (int)responseLen);
  json_decref(root);

  struct evbuffer *buffer = evbuffer_new();
  evhttp_add_header(request->output_headers, "Content-Type", "application/json");
  evhttp_add_header(request->output_headers, "Content-Length", responseHeader);
  evbuffer_add(buffer, responseData, responseLen);

  evhttp_send_reply(request, 200, "OK", buffer);

  evbuffer_free(buffer);
}

void get_background_image(struct evhttp_request *request, void *arg){
  struct evbuffer *buffer = evbuffer_new();
  struct evkeyvalq uri_params;
  printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
  evhttp_parse_query (request->uri, &uri_params);

  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }


  const char* img_address = return_background_address(json_to_background_name(requestJSON)).c_str();
  evhttp_add_header (request->output_headers, "Content-Type", "image/png");
  int fd = open(img_address, O_RDONLY);
  if (fd < 0) {
    evbuffer_add_printf (buffer, " Image %s not found", img_address);
    evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
    evhttp_clear_headers (&uri_params);
    evbuffer_free (buffer);
    return;
  }
  struct stat stbuf;
  if (fstat (fd, &stbuf) < 0) {
     evbuffer_add_printf (buffer, "File %s not found", img_address);
     evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
     evhttp_clear_headers (&uri_params);
     evbuffer_free (buffer);

     return;
  }

  int total_read_bytes = 0;
  while (total_read_bytes < stbuf.st_size) {
     int read_bytes = evbuffer_read (buffer, fd, stbuf.st_size);
     if (read_bytes < 0) {
         evbuffer_add_printf (buffer, "Error reading file %s", img_address);
         evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
         evhttp_clear_headers (&uri_params);
         evbuffer_free (buffer);

         return;
     }
     total_read_bytes += read_bytes;
  }

  evhttp_send_reply (request, HTTP_OK, "HTTP_OK", buffer);

  evhttp_clear_headers (&uri_params);
  evbuffer_free (buffer);
  free(requestDataBuffer);


}

void get_model_image(struct evhttp_request *request, void *arg){
  struct evbuffer *buffer = evbuffer_new();
  struct evkeyvalq uri_params;
  printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
  evhttp_parse_query (request->uri, &uri_params);

  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }


  const char* img_address = return_model_address(json_to_model_name(requestJSON)).c_str();

  evhttp_add_header (request->output_headers, "Content-Type", "image/png");
  int fd = open(img_address, O_RDONLY);
  if (fd < 0) {
    evbuffer_add_printf (buffer, " Image %s not found", img_address);
    evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
    evhttp_clear_headers (&uri_params);
    evbuffer_free (buffer);
    return;
  }
  struct stat stbuf;
  if (fstat (fd, &stbuf) < 0) {
     evbuffer_add_printf (buffer, "File %s not found", img_address);
     evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
     evhttp_clear_headers (&uri_params);
     evbuffer_free (buffer);

     return;
  }

  int total_read_bytes = 0;
  while (total_read_bytes < stbuf.st_size) {
     int read_bytes = evbuffer_read (buffer, fd, stbuf.st_size);
     if (read_bytes < 0) {
         evbuffer_add_printf (buffer, "Error reading file %s", img_address);
         evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
         evhttp_clear_headers (&uri_params);
         evbuffer_free (buffer);

         return;
     }
     total_read_bytes += read_bytes;
  }

  evhttp_send_reply (request, HTTP_OK, "HTTP_OK", buffer);

  evhttp_clear_headers (&uri_params);
  evbuffer_free (buffer);
  free(requestDataBuffer);


}

void get_last_user_params(struct evhttp_request *request, void *arg){
  printf("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }

  json_t *root = json_object();

  user current_user = json_to_user_struct(requestJSON);
  if (db_sign_in(current_user)) {
    all_params parameters = return_last_params(current_user);
    json_t *input = json_object();

    json_object_set_new( input, "strategy_name", json_string( parameters.strategy_name.c_str() ) );
    json_object_set_new( input, "background_name", json_string( parameters.background_name.c_str() ) );
    json_object_set_new( input, "model_name", json_string( parameters.model_name.c_str() ) );
    json_object_set_new( input, "crop_factor", json_real( parameters.crop_factor ) );
    json_object_set_new( input, "destination_to_model", json_real( parameters.destination_to_model ) );
    json_object_set_new( input, "focus_destination", json_real( parameters.focus_destination ) );
    json_object_set_new( input, "destination_to_background", json_real( parameters.destination_to_background ) );
    json_object_set_new( input, "aperture", json_real( parameters.aperture ) );
    json_object_set_new( root, "input_params", input );

  }

  char *responseData = json_dumps(root, JSON_INDENT(3));
  int responseLen = strlen(responseData);
  char responseHeader[HEADER_BUFFER_SIZE];
  snprintf(responseHeader, HEADER_BUFFER_SIZE, "%d", (int)responseLen);
  json_decref(root);

  struct evbuffer *buffer = evbuffer_new();
  evhttp_add_header(request->output_headers, "Content-Type", "application/json");
  evhttp_add_header(request->output_headers, "Content-Length", responseHeader);
  evbuffer_add(buffer, responseData, responseLen);

  evhttp_send_reply(request, 200, "OK", buffer);

  evbuffer_free(buffer);
}

void set_last_user_params(struct evhttp_request *request, void *arg){

  printf("%s\n", evhttp_request_uri(request));

  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }

  user current_user = json_to_user_struct(requestJSON);
  all_params parameters = json_to_params_struct(requestJSON);
  if(set_last_params(current_user, parameters)){
    evhttp_send_reply(request, 200, "OK", NULL);
  } else {
    evhttp_send_reply(request, HTTP_FORBIDDEN, "OK", NULL);
  }



  free(requestDataBuffer);
}

void set_to_favorites(struct evhttp_request *request, void *arg){
  printf("%s\n", evhttp_request_uri(request));

  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }
  std::string favourite_name = json_to_favourite_name(requestJSON);
  user current_user = json_to_user_struct(requestJSON);
  all_params parameters = json_to_params_struct(requestJSON);

  if(set_favourite(current_user, parameters, favourite_name)){
    evhttp_send_reply(request, 200, "OK", NULL);

  } else {
    evhttp_send_reply(request, HTTP_FORBIDDEN, "OK", NULL);
  }

  free(requestDataBuffer);
}

void get_my_favorites(struct evhttp_request *request, void *arg){
  printf("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);

  printf("%s\n", evhttp_request_uri(request));

  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }
  std::string favourite_name = json_to_favourite_name(requestJSON);
  user current_user = json_to_user_struct(requestJSON);

  json_t *root = json_object();
  json_t *favourites_list = return_favourites(current_user);


  json_object_set_new( root, "sets", favourites_list );


  char *responseData = json_dumps(root, JSON_INDENT(3));
  int responseLen = strlen(responseData);
  char responseHeader[HEADER_BUFFER_SIZE];
  snprintf(responseHeader, HEADER_BUFFER_SIZE, "%d", (int)responseLen);
  json_decref(root);

  struct evbuffer *buffer = evbuffer_new();
  evhttp_add_header(request->output_headers, "Content-Type", "application/json");
  evhttp_add_header(request->output_headers, "Content-Length", responseHeader);
  evbuffer_add(buffer, responseData, responseLen);

  evhttp_send_reply(request, 200, "OK", buffer);

  evbuffer_free(buffer);
}

void sign_in(struct evhttp_request *request, void *arg){
  printf("%s\n", evhttp_request_uri(request));

  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }

  user current_user = json_to_user_struct(requestJSON);
  if (db_sign_in(current_user)) {
    evhttp_send_reply(request, 200, "OK", NULL);

  } else {
    evhttp_send_reply(request, HTTP_FORBIDDEN, "OK", NULL);
  }






  free(requestDataBuffer);
}

void delete_favourite(struct evhttp_request *request, void *arg){
  printf("%s\n", evhttp_request_uri(request));
  struct event_base *base = (struct event_base *)arg;
  struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
  size_t requestLen = evbuffer_get_length(requestBuffer);
  char *requestDataBuffer = (char *)malloc(sizeof(char) * requestLen);
  evbuffer_copyout(requestBuffer, requestDataBuffer, requestLen);

  json_error_t error;

  json_t *requestJSON = json_loadb(requestDataBuffer, requestLen, 0, &error);

  if (requestJSON != NULL){
    char *requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
    printf("%s\n", requestDataString);
  }

  std::string favourite_name = json_to_favourite_name(requestJSON);
  user current_user = json_to_user_struct(requestJSON);


  if (delete_favourite_from_db(current_user, favourite_name)){
    evhttp_send_reply(request, 200, "OK", NULL);
  } else {
    evhttp_send_reply(request, HTTP_FORBIDDEN, "OK", NULL);

  }




}
