#include <iostream>
#include <evhttp.h>
#include <handler.h>


int main() {
    uint16_t port = 8000;
    const char *address = "127.0.0.1";

    event_init();
    struct evhttp *server = evhttp_start(address, port);

    printf("Succesfully started on %s port %d\n", address, port);

    evhttp_set_gencb(server, unspecified_URL, NULL);
    evhttp_set_cb(server, "/get_background_images", get_background_default_images, NULL);
    evhttp_set_cb(server, "/get_model_images", get_model_default_images, NULL);
    evhttp_set_cb(server, "/get_last_params", get_last_user_params, NULL);
    evhttp_set_cb(server, "/set_last_params", set_last_user_params, NULL);
    evhttp_set_cb(server, "/set_favorite", set_to_favorites, NULL);
    evhttp_set_cb(server, "/get_favorites", get_my_favorites, NULL);

    event_dispatch();
    evhttp_free(server);
    return 0;
}



