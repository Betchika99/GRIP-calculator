#include "handler.h"


void new_user(){

}

void unspecified_URL(struct evhttp_request *request, void *arg){
    struct evbuffer *buffer = evbuffer_new();
    if (buffer == NULL){
        fprintf(stderr, "ERROR: Can not create evbuffer(An evbuffer is an opaque data type for efficiently buffering data to be sent or received on the network.)");
    }
    evbuffer_add_printf(buffer, "ERROR: This URL does not exist");
    evhttp_send_reply(request, 404, "Not Found", buffer);
    evbuffer_free(buffer);
}


void get_background_default_images(struct evhttp_request *request, void *arg){

}

void get_model_default_images(struct evhttp_request *request, void *arg){

}

void get_last_user_params(struct evhttp_request *request, void *arg){

}

void set_last_user_params(struct evhttp_request *request, void *arg){

}

void set_to_favorites(struct evhttp_request *request, void *arg){

}

void get_my_favorites(struct evhttp_request *request, void *arg){

}
