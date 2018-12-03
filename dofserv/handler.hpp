
#ifndef HANDLER_H
#define HANDLER_H

#include <event.h>
#include <evhttp.h>
#include <jansson.h>
#include <string>

void unspecified_URL(struct evhttp_request *request, void *arg);

void get_background_default_images(struct evhttp_request *request, void *arg);

void get_model_default_images(struct evhttp_request *request, void *arg);

void get_last_user_params(struct evhttp_request *request, void *arg);

void set_last_user_params(struct evhttp_request *request, void *arg);

void set_to_favorites(struct evhttp_request *request, void *arg);

void get_my_favorites(struct evhttp_request *request, void *arg);



#endif
