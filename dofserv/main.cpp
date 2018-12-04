#include <iostream>
#include <event.h>
#include <evhttp.h>
#include "handler.hpp"
#include <stdlib.h>
#include <signal.h>


int main() {
    uint16_t port = 12345;
    const char *address = "0.0.0.0";
    struct event_base *ev_base = event_init();
    struct evhttp *server = evhttp_new(ev_base);
    if (evhttp_bind_socket (server, address, port) == -1) {
       printf("ERROR: Can't start on %s port %d\n", address, port);
       exit (1);
    }
    printf("Succesfully started on %s port %d\n", address, port);

    evhttp_set_cb(server, "/get_background_images", get_background_default_images, NULL);
    evhttp_set_cb(server, "/get_model_images", get_model_default_images, NULL);
    evhttp_set_cb(server, "/get_last_params", get_last_user_params, NULL);
    evhttp_set_cb(server, "/set_last_params", set_last_user_params, NULL);
    evhttp_set_cb(server, "/set_favorite", set_to_favorites, NULL);
    evhttp_set_cb(server, "/get_favorites", get_my_favorites, NULL);
    evhttp_set_gencb(server, unspecified_URL, NULL);
    event_base_dispatch (ev_base);



    evhttp_free(server);



    return 0;
}
