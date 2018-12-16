
#ifndef HANDLER_H
#define HANDLER_H

#include <event.h>
#include <evhttp.h>
#include <jansson.h>
#include <string>

void unspecified_URL(struct evhttp_request *request, void *arg);

void images_list(struct evhttp_request *request, void *arg);

void get_background_image(struct evhttp_request *request, void *arg);

void get_model_image(struct evhttp_request *request, void *arg);

void get_last_user_params(struct evhttp_request *request, void *arg);

void set_last_user_params(struct evhttp_request *request, void *arg);

void set_to_favorites(struct evhttp_request *request, void *arg);

void get_my_favorites(struct evhttp_request *request, void *arg);

void sign_in(struct evhttp_request *request, void *arg);

void delete_favourite(struct evhttp_request *request, void *arg);



#endif


// - метод, который принимает запрос на получение названий фотографий моделей и бэкграундов
// ПРИЁМ
// {
//   название стратегии
// }
// ОТДАЧА
// {
//   model_names{
//       массив записей вида:{
//          название картинки
//        }
//
//   }
//   background_names{
//       массив записей вида:{
//          название картинки
//        }
//   }
//}




// - метод, который принимает json с ObjectID и возвращает model
// ПРИЁМ
// {
//   название фотки
// }
// ОТДАЧА
// бинарник картинки


// - метод, который принимает json с ObjectID и возвращает background
// ПРИЁМ
// {
//   название фотки
// }
// ОТДАЧА
// бинарник картинки



// - метод, который принимает json с email и password и возвращает json с сетом последних параметров
// ПРИЁМ
// {
//   email
//   password
// }
// ОТДАЧА
// {
//   input_params{
//       ...
//       ...
//       ...
//   }
//   output_params{
//       ...
//       ...
//       ...
//   }
//}



// - метод, который принимает json с email, password и сетом последних параметров и возвращает 200/403
// ПРИЁМ
// {
//   email
//   password
//   input_params{
//       ...
//       ...
//       ...
//   }
//   output_params{
//       ...
//       ...
//       ...
//   }
// }
// ОТДАЧА
// 200/403


// - метод, которые принимает json с email и password и возвращает json с массивом избранных сетов параметров
// ПРИЁМ
// {
//   email
//   password
// }
// ОТДАЧА
/////////////////////// МАССИВ ///////////////////////////////////
// {
//   input_params{
//       ...
//       ...
//       ...
//   }
//   output_params{
//       ...
//       ...
//       ...
//   }
//}


// - метод, который принимает json с email, password и новым избранным сетом параметров (тут тоже вернуть ObjectID)
// ПРИЁМ
// {
//   email
//   password
//   input_params{
//       ...
//       ...
//       ...
//   }
//   output_params{
//       ...
//       ...
//       ...
//   }
// }
// ОТДАЧА
// {
//  ObjID
// }


// - метод, который принимает email, password, ObjectID и удаляет по нему один из избранных сетов (DELETE) (403/200)
// ПРИЁМ
// {
//   email
//   password
//   objID
// }
// ОТДАЧА
// 200/403
