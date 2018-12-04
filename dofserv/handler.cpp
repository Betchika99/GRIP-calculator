#include "handler.hpp"
#include "json_parser.hpp"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <jansson.h>

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>



#define BOUNDARY "xXPubSubXx"
#define HEADER_BUFFER_SIZE 1024
void new_user(){

}

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

void get_background_default_images(struct evhttp_request *request, void *arg){
  struct evbuffer *buffer = evbuffer_new();
  struct evkeyvalq uri_params;
  printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
  evhttp_parse_query (request->uri, &uri_params);
  const char* img_name = "/Users/iamfrommoscow/Desktop/uml2.jpg";
  evhttp_add_header (request->output_headers, "Content-Type", "multipart/form-data; boundary=xXPubSubXx" );
  evbuffer_add_printf(buffer, "--%s\r\n", BOUNDARY);
  for (size_t i = 0; i < 5; i++) {
    if (!img_name) {
      evbuffer_add_printf (buffer, "Bad request");
      evhttp_send_reply (request, HTTP_BADREQUEST, "Bad request", buffer);
      evhttp_clear_headers (&uri_params);
      evbuffer_free (buffer);
      return;
    }
    int fd = open(img_name, O_RDONLY);
    if (fd < 0) {
      evbuffer_add_printf (buffer, " Image %s not found", img_name);
      evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
      evhttp_clear_headers (&uri_params);
      evbuffer_free (buffer);
      return;
    }
    struct stat stbuf;
    if (fstat (fd, &stbuf) < 0) {
       evbuffer_add_printf (buffer, "File %s not found", img_name);
       evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
       evhttp_clear_headers (&uri_params);
       evbuffer_free (buffer);

       return;
   }

   evbuffer_add_printf(buffer, "Content-Disposition: form-data");
   evbuffer_add_printf(buffer, "Content-Type: image/jpeg");


   int total_read_bytes = 0;
   while (total_read_bytes < stbuf.st_size) {
       int read_bytes = evbuffer_read(buffer, fd, stbuf.st_size);
       if (read_bytes < 0) {
           evbuffer_add_printf (buffer, "Error reading file %s", img_name);
           evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
           evhttp_clear_headers (&uri_params);
           evbuffer_free (buffer);

           return;
       }
       total_read_bytes += read_bytes;
   }

   evbuffer_add_printf(buffer, "--%s\r\n", BOUNDARY);



  }

 evhttp_send_reply (request, HTTP_OK, "HTTP_OK", buffer);

 evhttp_clear_headers (&uri_params);
 evbuffer_free (buffer);


}

void get_model_default_images(struct evhttp_request *request, void *arg){
  struct evbuffer *buffer = evbuffer_new();
  struct evkeyvalq uri_params;
  printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
  evhttp_parse_query (request->uri, &uri_params);

// /Users/iamfrommoscow/Desktop/uml2.jpg



  const char* img_name = "/Users/iamfrommoscow/Desktop/uml2.jpg";
  evhttp_add_header (request->output_headers, "Content-Type", "image/jpg");
  int fd = open(img_name, O_RDONLY);
  if (fd < 0) {
    evbuffer_add_printf (buffer, " Image %s not found", img_name);
    evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
    evhttp_clear_headers (&uri_params);
    evbuffer_free (buffer);
    return;
  }
  struct stat stbuf;
  if (fstat (fd, &stbuf) < 0) {
     evbuffer_add_printf (buffer, "File %s not found", img_name);
     evhttp_send_reply (request, HTTP_NOTFOUND, "File not found", buffer);
     evhttp_clear_headers (&uri_params);
     evbuffer_free (buffer);

     return;
 }

 int total_read_bytes = 0;
 while (total_read_bytes < stbuf.st_size) {
     int read_bytes = evbuffer_read (buffer, fd, stbuf.st_size);
     if (read_bytes < 0) {
         evbuffer_add_printf (buffer, "Error reading file %s", img_name);
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

}

void get_last_user_params(struct evhttp_request *request, void *arg){
  printf("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);

  json_t *root = json_object();
  json_t *input = json_object();
  json_t *output = json_object();

  all_params parameters;

  json_object_set_new( input, "background_id", json_integer( parameters.background_id ) );
  json_object_set_new( input, "model_id", json_integer( parameters.model_id ) );
  json_object_set_new( input, "format_id", json_integer( parameters.format_id ) );
  json_object_set_new( input, "crop_factor", json_real( parameters.crop_factor ) );
  json_object_set_new( input, "destination_to_model", json_real( parameters.destination_to_model ) );
  json_object_set_new( input, "focus_destination", json_real( parameters.focus_destination ) );
  json_object_set_new( input, "destination_to_background", json_real( parameters.destination_to_background ) );
  json_object_set_new( input, "aperture", json_real( parameters.aperture ) );
  json_object_set_new( root, "input_params", input );



  json_object_set_new( output, "depth", json_real( parameters.depth ) );
  json_object_set_new( output, "front_GRIP", json_real( parameters.front_GRIP ) );
  json_object_set_new( output, "back_GRIP", json_real( parameters.back_GRIP ) );
  json_object_set_new( output, "hyperfocal_distance", json_real( parameters.hyperfocal_distance ) );
  json_object_set_new( root, "output_params", output );





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

  json_to_user_struct(requestJSON);


  free(requestDataBuffer);
}

void set_to_favorites(struct evhttp_request *request, void *arg){

}

void get_my_favorites(struct evhttp_request *request, void *arg){

}
